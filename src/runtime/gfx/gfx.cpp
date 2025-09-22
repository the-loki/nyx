//
// Created by loki on 24-4-22.
//

#include <runtime/gfx/gfx.h>
#include <runtime/extension/function.h>
#include <runtime/window/window.h>
#include <runtime/gfx/gfx_context.h>
#include <runtime/engine.h>

#include <glfw3webgpu.h>
#include <webgpu_extension.h>

#ifdef __EMSCRIPTEN__

#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/html5_webgpu.h>

#endif

namespace nyx::runtime::gfx {

Gfx::Gfx() : context_(std::make_unique<GfxContext>()) {}

Gfx::~Gfx() = default;

void Gfx::update() {
	auto engine = engine_.lock();

	if (!engine) {
		return;
	}

	auto window = engine->window_;

	if (window->size_.x==context_->swap_chain_size_.x && window->size_.y==context_->swap_chain_size_.y) {
		return;
	}

	if (context_->swap_chain_) {
		wgpuSwapChainRelease(context_->swap_chain_);
		context_->swap_chain_ = nullptr;
	}

	context_->swap_chain_size_ = window->size_;

	if (window->size_.x==0 || window->size_.y==0) {
		return;
	}

	auto swap_chain_desc = WGPUSwapChainDescriptor{};
	swap_chain_desc.width = window->size_.x;
	swap_chain_desc.height = window->size_.y;
	swap_chain_desc.presentMode = WGPUPresentMode_Fifo;
	swap_chain_desc.format = context_->preferred_texture_format_;
	swap_chain_desc.usage = WGPUTextureUsage_RenderAttachment;
	context_->swap_chain_ = wgpuDeviceCreateSwapChain(context_->device_, context_->surface_, &swap_chain_desc);
}

bool Gfx::create_gfx_context() {
	using namespace webgpu_extension;

	auto engine = engine_.lock();

	if (!engine) {
		return false;
	}

	auto window = engine->window_;

#ifndef __EMSCRIPTEN__
	WGPUInstanceDescriptor instance_desc = {};
	instance_desc.nextInChain = nullptr;
	context_->instance_ = wgpuCreateInstance(&instance_desc);
	context_->surface_ = glfwGetWGPUSurface(context_->instance_, window->window_);

	WGPURequestAdapterOptions adapter_opts = {};
	adapter_opts.nextInChain = nullptr;
	adapter_opts.compatibleSurface = context_->surface_;

#ifdef _WIN32
	adapter_opts.backendType = WGPUBackendType_D3D12;
#elif __APPLE__
	adapter_opts.backendType = WGPUBackendType_Metal;
#elif __linux__
	adapter_opts.backendType = WGPUBackendType_Vulkan;
#endif

	context_->adapter_ = request_adapter(context_->instance_, &adapter_opts);

	WGPUDeviceDescriptor device_desc = {};
	device_desc.nextInChain = nullptr;
	device_desc.label = "WebGPU Device";
	device_desc.requiredFeaturesCount = 0;
	device_desc.requiredLimits = nullptr;
	device_desc.defaultQueue.nextInChain = nullptr;
	device_desc.defaultQueue.label = "WebGPU Default Queue";
	context_->device_ = request_device(context_->adapter_, &device_desc);
#else
	context_->device = emscripten_webgpu_get_device();
#endif

	if (!context_->device_) {
		glfwSetWindowShouldClose(window->window_, GLFW_TRUE);
		return false;
	}

	wgpuDeviceSetUncapturedErrorCallback(context_->device_, &output_webgpu_error, nullptr);

#ifdef __EMSCRIPTEN__
	WGPUSurfaceDescriptorFromCanvasHTMLSelector selector = {};
	selector.selector = "#canvas";
	selector.chain = {};
	selector.chain.next = nullptr;
	selector.chain.sType = WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector;
	WGPUSurfaceDescriptor surface_desc = {};
	surface_desc.nextInChain = reinterpret_cast<WGPUChainedStruct*>(&selector);
	context_->instance = wgpuCreateInstance(nullptr);
	context_->surface = wgpuInstanceCreateSurface(context_->instance, &surface_desc);
#endif

	context_->supported_limits_.nextInChain = nullptr;
	wgpuDeviceGetLimits(context_->device_, &(context_->supported_limits_));
	context_->preferred_texture_format_ = wgpuSurfaceGetPreferredFormat(context_->surface_, context_->adapter_);

	return true;
}

bool Gfx::initialize(const std::weak_ptr<runtime::Engine> &engine) {
	engine_ = engine;
	return create_gfx_context();
}

}
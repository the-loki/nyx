//
// Created by loki on 2024/3/5.
//

#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <webgpu/webgpu.h>

namespace nyx::runtime::gfx {

struct GfxContext {
	WGPUDevice device_ = nullptr;
	glm::ivec2 swap_chain_size_{};
	WGPUSurface surface_ = nullptr;
	WGPUAdapter adapter_ = nullptr;
	WGPUInstance instance_ = nullptr;
	WGPUSwapChain swap_chain_ = nullptr;
	WGPUSupportedLimits supported_limits_{};
	WGPUTextureFormat preferred_texture_format_ = {};
};

}// namespace nyx::runtime::gfx
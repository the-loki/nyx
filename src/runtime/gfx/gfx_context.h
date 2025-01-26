//
// Created by loki on 2024/3/5.
//


#pragma once

#include <webgpu/webgpu.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace leyla::runtime::gfx {

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

}
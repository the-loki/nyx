//
// Created by loki on 2024/3/5.
//

#pragma once

#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <webgpu/webgpu.h>

namespace nyx::runtime::gfx {

inline void output_webgpu_error(WGPUErrorType error_type, const char *message, void *) {
	static const std::unordered_map<WGPUErrorType, const char *> errorTypeLabels = {
			{WGPUErrorType_Validation, "Validation"},
			{WGPUErrorType_OutOfMemory, "Out of memory"},
			{WGPUErrorType_Unknown, "Unknown"},
			{WGPUErrorType_DeviceLost, "Device lost"},
	};

	auto label = errorTypeLabels.find(error_type) != errorTypeLabels.end() ? errorTypeLabels.at(error_type) : "Unknown";

	printf("%s error: %s\n", label, message);
}

}// namespace nyx::runtime::gfx
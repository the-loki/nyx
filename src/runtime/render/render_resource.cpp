//
// Created by loki7 on 2025/11/22.
//


module;

#include <string>
#include <memory>
#include <optional>
#include <unordered_map>

module nyx.runtime;

import :render.render_resource;

namespace nyx::runtime::render {


RenderResource::RenderResource(std::string_view name, uint32_t id) : name_(name), id_(id) {}

std::optional<std::weak_ptr<RenderResource>> RenderResourceManager::get_resource(uint32_t id) {
	if (auto it = this->resource_map_.find(id); it != this->resource_map_.end()) { return it->second; }

	return std::nullopt;
}


}
//
// Created by loki7 on 2025/11/22.
//

module;

#include <string>
#include <memory>
#include <optional>
#include <unordered_map>

export module nyx.runtime:render.render_resource;

import :fwd;

namespace nyx::runtime::render {

export class RenderResourceManager final {
public:
	RenderResourceManager() = default;

	~RenderResourceManager() = default;

	std::optional<std::weak_ptr<RenderResource>> get_resource(uint32_t id);


private:
	std::unordered_map<uint32_t, std::shared_ptr<RenderResource>> resource_map_{};
};

export class RenderResource {
	friend class RenderResourceManager;

protected:
	RenderResource(std::string_view name, uint32_t id);

public:
	const uint32_t id_;
	const std::string name_;
};

}
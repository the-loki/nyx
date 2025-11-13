//
// Created by loki on 24-4-21.
//

#pragma once

#include <memory>
#include <runtime/gfx/gfx_context.h>
#include <runtime/runtime.h>
#include <vector>

namespace nyx::runtime::render {

class RenderGraph {
public:
	explicit RenderGraph(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~RenderGraph();
};

}// namespace nyx::runtime::render

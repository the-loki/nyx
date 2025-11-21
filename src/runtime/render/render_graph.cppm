//
// Created by loki on 24-4-21.
//

module;

#include <memory>

export module nyx.runtime:render.render_graph;

import :fwd;

namespace nyx::runtime::render {

export class RenderGraph {
public:
	explicit RenderGraph(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~RenderGraph();
};

}// namespace nyx::runtime::render

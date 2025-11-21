//
// Created by loki on 24-4-21.
//

module;

module nyx.runtime;

import :render.render_graph;

namespace nyx::runtime::render {

RenderGraph::RenderGraph(const std::weak_ptr<runtime::Engine> &engine) {
}
RenderGraph::~RenderGraph() = default;

}// namespace nyx::runtime::render
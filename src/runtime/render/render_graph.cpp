//
// Created by loki on 24-4-21.
//

#include <runtime/engine.h>
#include <runtime/render/render_graph.h>

namespace nyx::runtime::render {

RenderGraph::RenderGraph(const std::weak_ptr<runtime::Engine> &engine) {
}
RenderGraph::~RenderGraph() = default;

}// namespace nyx::runtime::render
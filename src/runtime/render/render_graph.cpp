//
// Created by loki on 24-4-21.
//

#include <runtime/render/render_graph.h>
#include <runtime/render/sink.h>
#include <runtime/render/pass.h>
#include <runtime/render/source.h>
#include <runtime/engine.h>

namespace leyla::runtime::render {

void RenderGraph::add_sink(std::unique_ptr<Sink> sink) {
	sinks_.emplace_back(std::move(sink));
}

void RenderGraph::add_pass(std::unique_ptr<Pass> pass) {
	passes_.emplace_back(std::move(pass));
}

void RenderGraph::add_source(std::unique_ptr<Source> source) {
	sources_.emplace_back(std::move(source));
}

RenderGraph::RenderGraph(const std::weak_ptr<runtime::Engine> &engine) : engine_(engine) {
}

RenderGraph::~RenderGraph() = default;

}
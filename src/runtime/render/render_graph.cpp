//
// Created by loki on 24-4-21.
//

#include <runtime/render/render_graph.h>
#include <runtime/render/sink.h>
#include <runtime/render/pass.h>
#include <runtime/render/source.h>

namespace fairy::runtime::render {

void RenderGraph::AddSink(std::unique_ptr<Sink> sink) {
	sinks_.emplace_back(std::move(sink));
}

void RenderGraph::AddPass(std::unique_ptr<Pass> pass) {
	passes_.emplace_back(std::move(pass));
}

void RenderGraph::AddSource(std::unique_ptr<Source> source) {
	sources_.emplace_back(std::move(source));
}

}
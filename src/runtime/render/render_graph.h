//
// Created by loki on 24-4-21.
//

#pragma once

#include <vector>
#include <memory>
#include <runtime/gfx/gfx_context.h>
#include <runtime/runtime.h>

namespace fairy::runtime::render {

class RenderGraph {
public:
	explicit RenderGraph(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~RenderGraph();
protected:
	void AddSink(std::unique_ptr<Sink> sink);
	void AddPass(std::unique_ptr<Pass> pass);
	void AddSource(std::unique_ptr<Source> source);
private:
	std::weak_ptr<runtime::Engine> engine_;
	std::vector<std::unique_ptr<Sink>> sinks_;
	std::vector<std::unique_ptr<Pass>> passes_;
	std::vector<std::unique_ptr<Source>> sources_;
};

}

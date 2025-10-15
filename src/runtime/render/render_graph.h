//
// Created by loki on 24-4-21.
//

#pragma once

#include <memory>
#include <runtime/core/type_traits.h>
#include <runtime/gfx/gfx_context.h>
#include <runtime/runtime.h>
#include <vector>

namespace nyx::runtime::render {

class RenderGraph : public core::NonCopyableAndMovable {
public:
	explicit RenderGraph(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~RenderGraph();

protected:
	void add_sink(std::unique_ptr<Sink> sink);
	void add_pass(std::unique_ptr<Pass> pass);
	void add_source(std::unique_ptr<Source> source);

private:
	std::weak_ptr<runtime::Engine> engine_;
	std::vector<std::unique_ptr<Sink>> sinks_;
	std::vector<std::unique_ptr<Pass>> passes_;
	std::vector<std::unique_ptr<Source>> sources_;
};

}// namespace nyx::runtime::render

//
// Created by loki on 24-4-21.
//

#pragma once

#include <vector>
#include <memory>
#include <runtime/gfx/gfx_context.h>

using GfxContext = ::fairy::runtime::gfx::GfxContext;

namespace fairy::runtime::render {

class Sink;
class Pass;
class Source;

class RenderGraph {

protected:
	void AddSink(std::unique_ptr<Sink> sink);
	void AddPass(std::unique_ptr<Pass> pass);
	void AddSource(std::unique_ptr<Source> source);
private:
	std::vector<std::unique_ptr<Sink>> sinks_;
	std::vector<std::unique_ptr<Pass>> passes_;
	std::vector<std::unique_ptr<Source>> sources_;
};

}

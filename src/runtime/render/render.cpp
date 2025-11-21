//
// Created by loki on 24-4-22.
//

module;

#include <memory>

module nyx.runtime;

import :engine;
import :render.render;

namespace nyx::runtime::render {

Render::Render(const std::weak_ptr<runtime::Engine> &engine)
	: engine_(engine), rdg_(std::make_shared<RenderGraph>(engine)) {
}

std::shared_ptr<gfx::Gfx> Render::get_gfx() const {
	auto engine = engine_.lock();

	if (engine) {
		return engine->gfx_;
	}

	return nullptr;
}

ForwardRender::ForwardRender(const std::weak_ptr<runtime::Engine> &engine) : Render(engine) {
}

DeferredRender::DeferredRender(const std::weak_ptr<runtime::Engine> &engine) : Render(engine) {
}

}// namespace nyx::runtime::render
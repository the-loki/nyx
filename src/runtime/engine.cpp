//
// Created by loki on 2024/2/16.
//


#include <iostream>
#include <thread>
#include <runtime/engine.h>
#include <runtime/window/window.h>
#include <runtime/gfx//gfx.h>
#include <runtime/render/render.h>

namespace fairy::runtime {

bool Engine::initialize() {
	world_ = std::make_shared<flecs::world>();
	auto thread_num = static_cast<int32_t>(std::thread::hardware_concurrency());
	world_->set_threads(thread_num);
	world_->set<flecs::Rest>({});

	window_ = window::Window::CreateDefault();

	if (!window_->initialize(shared_from_this())) {
		return false;
	}

	gfx_ = std::make_shared<gfx::Gfx>();

	if (!gfx_->initialize(shared_from_this())) {
		return false;
	}

	auto forward_render = std::make_shared<render::ForwardRender>(shared_from_this());;
	render_ = std::dynamic_pointer_cast<render::Render>(forward_render);

	return true;
}

void Engine::start() const {
	struct CoreHolder { void *x; } holder{};

	world_->entity().set(holder);
	world_->system<const CoreHolder>().kind(flecs::PreUpdate).each([&](const CoreHolder &) {
		window_->Update();
		gfx_->update();
	});

	while (world_->progress()) {

	}

	world_->quit();
}

std::shared_ptr<Engine> Engine::create() {
	auto engine = new Engine();
	return std::shared_ptr<Engine>(engine);
}

void Engine::quit() const {
	if (world_) {
		world_->quit();
	}
}

}

//
// Created by loki on 2024/2/16.
//

#pragma once

#include <flecs.h>
#include <memory>
#include <runtime/core/type_traits.h>
#include <runtime/framework/component/transform.h>
#include <runtime/runtime.h>

namespace nyx::runtime {

class Engine : public core::NonCopyableAndMovable, public std::enable_shared_from_this<Engine> {
protected:
	Engine() = default;

public:
	~Engine() = default;

	void quit() const;
	void start() const;
	bool initialize();
	static std::shared_ptr<Engine> create();

public:
	std::shared_ptr<gfx::Gfx> gfx_ = nullptr;
	std::shared_ptr<flecs::world> world_ = nullptr;
	std::shared_ptr<window::Window> window_ = nullptr;
	std::shared_ptr<render::Render> render_ = nullptr;
};

}// namespace nyx::runtime

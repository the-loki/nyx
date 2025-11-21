//
// Created by loki on 2024/2/16.
//

module;

#include <flecs.h>
#include <memory>

export module nyx.runtime:engine;

import :fwd;

namespace nyx::runtime {

export class Engine : public std::enable_shared_from_this<Engine> {
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

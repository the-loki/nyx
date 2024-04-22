//
// Created by loki on 2024/2/16.
//

#pragma once

#include <runtime/core/type_traits.h>
#include <memory>
#include <flecs.h>
#include <runtime/runtime.h>

namespace fairy::runtime {

class Engine : public core::NonCopyableAndMovable, public std::enable_shared_from_this<Engine> {
protected:
	Engine() = default;
public:
	~Engine() = default;

	void Quit() const;
	void Start() const;
	bool Initialize();
	static std::shared_ptr<Engine> Create();
public:
	std::shared_ptr<gfx::Gfx> gfx_ = nullptr;
	std::shared_ptr<flecs::world> world_ = nullptr;
	std::shared_ptr<window::Window> window_ = nullptr;
	std::shared_ptr<render::Render> render_ = nullptr;
};

}

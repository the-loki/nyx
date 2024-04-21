//
// Created by loki on 24-4-22.
//

#pragma once

#include <memory>
#include <flecs.h>
#include <runtime/engine.h>
#include <runtime/gfx/gfx_context.h>

namespace fairy::runtime {
class Engine;
}

namespace fairy::runtime::gfx {

class Gfx {
public:
	Gfx() = default;
	virtual ~Gfx() = default;
public:
	void Update();
	bool Initialize(const std::weak_ptr<runtime::Engine> &engine);
protected:
	bool CreateGfxContext();
private:
	GfxContext context_;
	std::weak_ptr<runtime::Engine> engine_;
};

}
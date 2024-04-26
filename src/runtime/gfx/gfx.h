//
// Created by loki on 24-4-22.
//

#pragma once

#include <memory>
#include <flecs.h>
#include <runtime/runtime.h>

namespace fairy::runtime::gfx {

class Gfx {
public:
	Gfx();
	virtual ~Gfx();
public:
	void update();
	bool initialize(const std::weak_ptr<runtime::Engine> &engine);
protected:
	bool create_gfx_context();
private:
	std::unique_ptr<GfxContext> context_;
	std::weak_ptr<runtime::Engine> engine_;
};

}
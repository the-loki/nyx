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
	void Update();
	bool Initialize(const std::weak_ptr<runtime::Engine> &engine);
protected:
	bool CreateGfxContext();
private:
	std::weak_ptr<runtime::Engine> engine_;
	std::unique_ptr<GfxContext> context_ = nullptr;
};

}
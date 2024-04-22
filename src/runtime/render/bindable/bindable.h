//
// Created by loki on 24-4-21.
//


#pragma once

#include <runtime/runtime.h>

namespace fairy::runtime::render {

class RenderGraph;

class Bindable {
public:
	virtual void Bind(RenderGraph &rdg) noexcept = 0;
	virtual ~Bindable() = default;
protected:
	static gfx::GfxContext *GetGfxContext(RenderGraph &rdg) noexcept;
};

inline gfx::GfxContext *Bindable::GetGfxContext(RenderGraph &rdg) noexcept {
	return nullptr;
}

}
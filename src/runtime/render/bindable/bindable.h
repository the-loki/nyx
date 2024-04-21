//
// Created by loki on 24-4-21.
//


#pragma once

#include <runtime/gfx/gfx_context.h>

using GfxContext = ::fairy::runtime::gfx::GfxContext;

namespace fairy::runtime::render {

class RenderGraph;

class Bindable {
public:
	virtual void Bind(RenderGraph &rdg) noexcept = 0;
	virtual ~Bindable() = default;
protected:
	static GfxContext *GetGfxContext(RenderGraph &rdg) noexcept;
};

inline GfxContext *Bindable::GetGfxContext(RenderGraph &rdg) noexcept {
	return nullptr;
}

}
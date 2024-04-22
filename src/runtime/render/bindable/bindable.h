//
// Created by loki on 24-4-21.
//


#pragma once

#include <runtime/runtime.h>
#include <runtime/core/type_traits.h>

namespace fairy::runtime::render {

class RenderGraph;

class Bindable : public core::NonCopyable {
public:
	virtual void bind(RenderGraph &rdg) noexcept = 0;
	virtual ~Bindable() = default;
protected:
	static gfx::GfxContext *GetGfxContext(RenderGraph &rdg) noexcept;
};

inline gfx::GfxContext *Bindable::GetGfxContext(RenderGraph &rdg) noexcept {
	return nullptr;
}

}
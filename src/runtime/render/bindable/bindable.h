//
// Created by loki on 24-4-21.
//

#pragma once

#include <runtime/core/type_traits.h>
#include <runtime/runtime.h>

namespace nyx::runtime::render {

class Bindable : public core::NonCopyable {
public:
	virtual void bind(RenderGraph &rdg) noexcept = 0;
	virtual ~Bindable() = default;

protected:
	static gfx::GfxContext *get_gfx_context(RenderGraph &rdg) noexcept;
};

inline gfx::GfxContext *Bindable::get_gfx_context(RenderGraph &rdg) noexcept {
	return nullptr;
}

}// namespace nyx::runtime::render
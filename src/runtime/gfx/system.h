//
// Created by loki on 2024/3/9.
//


#pragma once

#include <runtime/gfx/component/gfx_context.h>
#include <runtime/window/component/window.h>
#include <flecs.h>

namespace fairy::runtime::gfx {

using Window = fairy::runtime::window::Window;

void Initialize(flecs::world & world);
void SetupGfxContext(GfxContext &ctx, const Window &window);
void SetupSwapChain(GfxContext &ctx, const Window &window);

}
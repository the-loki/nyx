//
// Created by loki on 2024/3/9.
//

#include <runtime/window/system.h>
#include <runtime/gfx/component/gfx_context.h>

#include <flecs.h>

using GfxContext = fairy::runtime::gfx::GfxContext;

namespace fairy::runtime::window {

void Initialize(flecs::world & world) {
	world.entity().set(fairy::runtime::window::Window::CreateDefault());
	world.system<Window>().kind(flecs::OnStart).write<Window>().each(SetupGLFWWindow);
	world.system<Window>().kind(flecs::PreUpdate).write<GfxContext>().each(UpdateWindow);
}

}
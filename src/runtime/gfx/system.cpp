//
// Created by loki on 2024/3/9.
//

#include <runtime/gfx/system.h>

namespace fairy::runtime::gfx {

void Initialize(flecs::world & world) {
	world.system<GfxContext, const Window>().kind(flecs::OnStart).each(SetupGfxContext);
	world.system<GfxContext, const Window>().kind(flecs::PreUpdate).each(SetupSwapChain);
}

}
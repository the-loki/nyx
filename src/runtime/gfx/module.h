//
// Created by loki on 2024/3/5.
//


#pragma once

#include <flecs.h>
#include <runtime/gfx/system.h>

namespace fairy::runtime::gfx {

inline void InitializeModule(flecs::world & world) {
	Initialize(world);
}

}


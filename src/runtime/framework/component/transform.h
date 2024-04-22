//
// Created by loki on 24-4-22.
//


#pragma once

#include <glm/ext.hpp>
#include <glm/glm.hpp>

namespace fairy::runtime::framework {
struct Transform {
	glm::vec3 position_{};
	glm::quat rotation_{};
	glm::vec3 scale_{1.0f};
};
}

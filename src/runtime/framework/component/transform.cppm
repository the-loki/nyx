//
// Created by loki on 24-4-22.
//

module;

#include <glm/ext.hpp>
#include <glm/glm.hpp>

export module nyx.runtime:framework.component.transform;

namespace nyx::runtime::framework {

export struct Transform {
	glm::vec3 position_{};
	glm::quat rotation_{};
	glm::vec3 scale_{1.0f};
};

}// namespace nyx::runtime::framework

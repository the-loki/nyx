//
// Created by loki on 2024/3/4.
//

module;

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <memory>
#include <string>

export module nyx.runtime:window.window;

import :fwd;

namespace nyx::runtime::window {

export class Window {
public:
	void Update();
	static std::shared_ptr<Window> CreateDefault();
	bool initialize(const std::weak_ptr<runtime::Engine> &engine);

protected:
	bool create_window();

public:
	std::string title_;
	glm::ivec2 size_{};
	GLFWwindow *window_ = nullptr;
	std::weak_ptr<Engine> engine_;
};

}// namespace nyx::runtime::window
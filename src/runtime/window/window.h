//
// Created by loki on 2024/3/4.
//


#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include <runtime/runtime.h>


namespace leyla::runtime::window {

class Window {
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

}
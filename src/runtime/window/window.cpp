//
// Created by loki on 24-4-22.
//

#include <runtime/window/window.h>
#include <runtime/engine.h>

namespace nyx::runtime::window {

static void PrintGlfwError(int error, const char *description) {
	printf("GLFW Error %d: %s\n", error, description);
}

bool Window::create_window() {
	glfwSetErrorCallback(PrintGlfwError);

	if (!glfwInit()) {
		return false;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	auto title = title_;
	auto size = size_;
	window_ = glfwCreateWindow(size.x, size.y, title.data(), nullptr, nullptr);

	if (!window_) {
		glfwTerminate();
		return false;
	}

	glfwShowWindow(window_);

	return true;
}

void Window::Update() {
	if (glfwWindowShouldClose(window_)) {
		if (auto engine = engine_.lock();engine) {
			engine->quit();
		}

		return;
	}

	glfwPollEvents();
	glfwGetFramebufferSize(window_, &(size_.x), &(size_.y));
}

bool Window::initialize(const std::weak_ptr<runtime::Engine> &engine) {
	engine_ = engine;
	return create_window();
}

std::shared_ptr<Window> Window::CreateDefault() {
	auto window = std::make_shared<window::Window>();
	window->title_ = "nyx";
	window->size_ = {1280, 720};

	return window;
}

}
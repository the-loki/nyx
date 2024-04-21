//
// Created by loki on 24-4-22.
//

#include <runtime/window/window.h>
#include <runtime/engine.h>

namespace fairy::runtime::window {

static void PrintGlfwError(int error, const char *description) {
	printf("GLFW Error %d: %s\n", error, description);
}

bool Window::CreateWindow() {
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
			engine->Quit();
		}

		return;
	}

	glfwPollEvents();
	glfwGetFramebufferSize(window_, &(size_.x), &(size_.y));
}

bool Window::Initialize(const std::weak_ptr<runtime::Engine> &engine) {
	engine_ = engine;
	return CreateWindow();
}

std::shared_ptr<Window> Window::CreateDefault() {
	auto window = std::make_shared<window::Window>();
	window->title_ = "Fairy";
	window->size_ = {1280, 720};

	return window;
}

}
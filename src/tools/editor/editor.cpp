#include <runtime/engine.h>

int main() {
	auto engine = fairy::runtime::Engine::create();

	if (engine->initialize()) {
		engine->start();
	}

	return 0;
}


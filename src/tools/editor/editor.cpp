#include <runtime/engine.h>

int main() {
	auto engine = fairy::runtime::Engine::Create();

	if (engine->Initialize()) {
		engine->Start();
	}

	return 0;
}


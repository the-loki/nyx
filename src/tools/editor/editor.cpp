#include <runtime/engine.h>

int main() {
	fairy::runtime::Engine engine;

	if (engine.Initialize()) {
		engine.Start();
	}

	return 0;
}


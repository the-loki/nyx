#include <runtime/engine.h>
#include <runtime/resource/mesh_asset.h>

int main() {
	auto engine = leyla::runtime::Engine::create();
	leyla::runtime::resource::MeshAsset mesh;
	// mesh.load("../assets/models/cube.obj");

	if (engine->initialize()) {
		engine->start();
	}

	return 0;
}


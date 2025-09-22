#include <runtime/engine.h>
#include <runtime/resource/mesh_asset.h>

int main() {
	auto engine = nyx::runtime::Engine::create();
	nyx::runtime::resource::MeshAsset mesh;
	// mesh.load("../assets/models/cube.obj");

	if (engine->initialize()) {
		engine->start();
	}

	return 0;
}


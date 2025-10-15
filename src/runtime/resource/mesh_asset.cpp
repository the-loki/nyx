//
// Created by loki on 24-4-26.
//

#include <runtime/core/lru.hpp>
#include <runtime/resource/mesh_asset.h>

namespace nyx::runtime::resource {

bool MeshAsset::load(const std::string &path) {
	using namespace nyx::runtime::core;
	auto cache = LRUCache<std::string, std::string>::getInstance();

	return true;
}

}// namespace nyx::runtime::resource

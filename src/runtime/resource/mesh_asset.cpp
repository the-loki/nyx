//
// Created by loki on 24-4-26.
//

module;

#include <string>

module nyx.runtime;

import :common.lru;
import :resource.mesh_asset;

namespace nyx::runtime::resource {

bool MeshAsset::load(const std::string &path) {
	using namespace nyx::runtime::core;
	auto cache = LRUCache<std::string, std::string>::getInstance();

	return true;
}

}// namespace nyx::runtime::resource

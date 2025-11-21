//
// Created by loki on 24-4-26.
//

module;

#include <string>

export module nyx.runtime:resource.mesh_asset;

import :resource.asset;

namespace nyx::runtime::resource {

export class MeshAsset : public Asset {
public:
	MeshAsset() = default;

public:
	bool load(const std::string &path) override;
};

}// namespace nyx::runtime::resource

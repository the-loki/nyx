//
// Created by loki on 24-4-26.
//


#pragma once

#include <runtime/resource/asset.h>
#include <runtime/runtime.h>

namespace nyx::runtime::resource {

class MeshAsset : public Asset {
public:
	MeshAsset() = default;
public:
	bool load(const std::string &path) override;
};

}

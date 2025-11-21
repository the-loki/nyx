//
// Created by loki on 24-4-26.
//

module;

#include <string>

export module nyx.runtime:resource.asset;

namespace nyx::runtime::resource {

export class Asset {
public:
	Asset() = default;
	virtual ~Asset() = default;

public:
	virtual bool load(const std::string &path);
};

}// namespace nyx::runtime::resource

//
// Created by loki on 24-4-26.
//


#pragma once

#include <string>

namespace nyx::runtime::resource {

class Asset {
public:
	Asset() = default;
	virtual ~Asset() = default;
public:
	virtual bool load(const std::string &path);
};

}

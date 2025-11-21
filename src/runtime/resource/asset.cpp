//
// Created by loki on 24-4-26.
//

module;

#include <string>

module nyx.runtime;

import :resource.asset;

namespace nyx::runtime::resource {

bool Asset::load(const std::string &path) {
	return true;
}

}// namespace nyx::runtime::resource

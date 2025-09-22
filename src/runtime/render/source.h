//
// Created by loki on 24-4-21.
//

#pragma once

#include <string>

namespace nyx::runtime::render {

class Source {
public:
	explicit Source(std::string name);
	virtual ~Source() = default;
private:
	std::string name_;
};

}

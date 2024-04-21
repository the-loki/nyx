//
// Created by loki on 24-4-21.
//

#pragma once

#include <string>

namespace fairy::runtime::render {

class Source {
public:
	explicit Source(std::string name);
	~Source() = default;
private:
	std::string name_;
};

}

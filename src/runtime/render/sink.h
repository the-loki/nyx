//
// Created by loki on 24-4-21.
//

#pragma once

#include <string>

namespace fairy::runtime::render {

class Sink {
public:
	explicit Sink(std::string name);
	~Sink() = default;
private:
	std::string name_;
};

}

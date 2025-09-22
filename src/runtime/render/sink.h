//
// Created by loki on 24-4-21.
//

#pragma once

#include <string>

namespace nyx::runtime::render {

class Sink {
public:
	explicit Sink(std::string name);
	virtual ~Sink() = default;
private:
	std::string name_;
};

}

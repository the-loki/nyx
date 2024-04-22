//
// Created by loki on 24-4-21.
//

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <runtime/runtime.h>

namespace fairy::runtime::render {

class Pass {
public:
	explicit Pass(std::string name);
	~Pass() = default;

protected:
	void RegisterSink(std::unique_ptr<Sink> sink);
	void RegisterSource(std::unique_ptr<Source> source);
private:
	std::string name_;
	std::vector<std::unique_ptr<Sink>> sinks_;
	std::vector<std::unique_ptr<Source>> sources_;
};

}

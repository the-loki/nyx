//
// Created by loki on 24-4-21.
//

#pragma once

#include <memory>
#include <runtime/core/type_traits.h>
#include <runtime/runtime.h>
#include <string>
#include <vector>

namespace nyx::runtime::render {

class Pass : public core::NonCopyable {
public:
	explicit Pass(std::string name);
	~Pass() = default;

protected:
	void register_sink(std::unique_ptr<Sink> sink);
	void register_source(std::unique_ptr<Source> source);

private:
	std::string name_;
	std::vector<std::unique_ptr<Sink>> sinks_;
	std::vector<std::unique_ptr<Source>> sources_;
};

}// namespace nyx::runtime::render

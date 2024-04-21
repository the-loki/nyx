//
// Created by loki on 24-4-21.
//

#include <runtime/render/pass.h>
#include <runtime/render/sink.h>
#include <runtime/render/source.h>

namespace fairy::runtime::render {

Pass::Pass(std::string name) : name_(std::move(name)) {

}

void Pass::RegisterSink(std::unique_ptr<Sink> sink) {
	sinks_.emplace_back(std::move(sink));
}

void Pass::RegisterSource(std::unique_ptr<Source> source) {
	sources_.emplace_back(std::move(source));
}

}
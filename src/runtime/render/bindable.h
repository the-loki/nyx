//
// Created by loki on 24-4-21.
//


#pragma once

namespace fairy::runtime::render {

class RenderGraph;

class Bindable {
public:
	virtual void Bind(RenderGraph &rdg) = 0;
	virtual ~Bindable() = default;
};

}
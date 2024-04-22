//
// Created by loki on 24-4-21.
//

#pragma once

#include <runtime/core/type_traits.h>

namespace fairy::runtime::fairy {

class Renderable : public core::NonCopyable {
public:
	Renderable() = default;
	virtual ~Renderable() = default;
private:

};

}
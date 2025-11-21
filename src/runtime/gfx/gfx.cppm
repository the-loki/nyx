//
// Created by loki on 24-4-22.
//

module;

#include <memory>

export module nyx.runtime:gfx.gfx;

import :fwd;

namespace nyx::runtime::gfx {

export class Gfx {
public:
	Gfx();
	virtual ~Gfx();

public:
	void update();
	bool initialize(const std::weak_ptr<runtime::Engine> &engine);

protected:
	bool create_gfx_context();

private:
	std::unique_ptr<GfxContext> context_;
	std::weak_ptr<runtime::Engine> engine_;
};

}// namespace nyx::runtime::gfx
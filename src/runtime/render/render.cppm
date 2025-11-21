//
// Created by loki on 24-4-22.
//

module;

#include <memory>

export module nyx.runtime:render.render;

import :fwd;
import :render.render_graph;

namespace nyx::runtime::render {

export class Render  {
public:
	explicit Render(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~Render() = default;

protected:
	std::weak_ptr<runtime::Engine> engine_;
	std::shared_ptr<RenderGraph> rdg_ = nullptr;

public:
	[[nodiscard]] std::shared_ptr<gfx::Gfx> get_gfx() const;
};

export class ForwardRender : public Render {
public:
	explicit ForwardRender(const std::weak_ptr<runtime::Engine> &engine);
	~ForwardRender() override = default;
};

export class DeferredRender : public Render {
public:
	explicit DeferredRender(const std::weak_ptr<runtime::Engine> &engine);
	~DeferredRender() override = default;
};

}// namespace nyx::runtime::render

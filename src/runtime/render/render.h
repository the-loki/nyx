//
// Created by loki on 24-4-22.
//


#pragma once

#include <memory>
#include <optional>
#include <runtime/core/type_traits.h>
#include <runtime/runtime.h>

namespace fairy::runtime::render {

class Render : public core::NonCopyableAndMovable {
public:
	explicit Render(const std::weak_ptr<runtime::Engine> &engine);
	virtual ~Render() = default;
protected:
	std::weak_ptr<runtime::Engine> engine_;
	std::shared_ptr<RenderGraph> rdg_ = nullptr;
public:
	[[nodiscard]] std::shared_ptr<gfx::Gfx> get_gfx() const;
};

class ForwardRender : public Render {
public:
	explicit ForwardRender(const std::weak_ptr<runtime::Engine> &engine);
	~ForwardRender() override = default;
};

class DeferredRender : public Render {
public:
	explicit DeferredRender(const std::weak_ptr<runtime::Engine> &engine);
	~DeferredRender() override = default;
};

}

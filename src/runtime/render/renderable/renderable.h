//
// Created by loki on 24-4-21.
//

#pragma once

#include <runtime/core/type_traits.h>
#include <runtime/runtime.h>
#include <memory>

namespace leyla::runtime::render {

class Renderable : public core::NonCopyable {
public:
	explicit Renderable(const std::weak_ptr<Render> &render);
	virtual ~Renderable() = default;
public:
	void submit();
	virtual void resolve_resource() = 0;
public:
	std::weak_ptr<Render> render_;
	std::shared_ptr<IndexBuffer> index_buffer_;
	std::shared_ptr<VertexBuffer> vertex_buffer_;
};

}
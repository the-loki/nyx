//
// Created by loki on 24-4-22.
//

#include <runtime/render/render.h>
#include <runtime/render/render_graph.h>
#include <runtime/engine.h>

namespace fairy::runtime::render {

Render::Render(const std::weak_ptr<runtime::Engine> &engine) : rdg_(std::make_shared<RenderGraph>(engine)) {
}

ForwardRender::ForwardRender(const std::weak_ptr<runtime::Engine> &engine) : Render(engine) {
}

DeferredRender::DeferredRender(const std::weak_ptr<runtime::Engine> &engine) : Render(engine) {

}

}
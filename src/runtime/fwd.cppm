//
// Created by loki7 on 2025/11/21.
//

export module nyx.runtime:fwd;

namespace nyx::runtime {
export class Engine;

namespace gfx {
export class Gfx;
export struct GfxContext;
}// namespace gfx

namespace window {
export class Window;
}

namespace render {
export class Render;
export class RenderGraph;
export class Source;
export class Sink;
export class Pass;
export class Renderable;
export class Bindable;
export class VertexBuffer;
export class IndexBuffer;
}// namespace render

namespace resource {
export class Asset;
export class MeshAsset;
export class AssetReader;
}// namespace resource

}// namespace nyx::runtime
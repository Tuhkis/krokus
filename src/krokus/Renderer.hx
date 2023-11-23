package krokus;

typedef RendererPtr = hl.Abstract<"krokus_renderer">

@:hlNative('krokus')
class Renderer {
  private var ptr: RendererPtr;

  private static function rendererCreateNative(width: Int, height: Int): RendererPtr {return null;}
  private static function rendererDisposeNative(r: RendererPtr): Void {}
  private static function rendererClearNative(r: RendererPtr): Void {}
  private static function rendererSetClearColorNative(r: Single, g: Single, b: Single): Void {}
  private static function rendererPushTriangleNative(
    renderer: RendererPtr,
    x0: Single, y0: Single,
    x2: Single, y1: Single,
    x1: Single, y2: Single,
    uv0x: Single, uv0y: Single,
    uv2x: Single, uv1y: Single,
    uv1x: Single, uv2y: Single,
    r0: Single, g0: Single, b0: Single, a0: Single,
    r1: Single, g1: Single, b1: Single, a1: Single,
    r2: Single, g2: Single, b2: Single, a2: Single,
    texture: Int
  ): Void {}
  private static function rendererBeginNative(r: RendererPtr): Void {}
  private static function rendererEndNative(r: RendererPtr): Void {}

  public function new(width: Int, height: Int) {
    ptr = rendererCreateNative(width, height);
  }

  public inline function dispose() {
    rendererDisposeNative(ptr);
  }

  public inline function clear() {
    rendererClearNative(ptr);
  }

  public inline function setClearColor(color: Color): Void {
    rendererSetClearColorNative(color.r, color.g, color.b);
  }

  public inline function pushTriangle(a: Vec2, b: Vec2, c: Vec2, aUv: Vec2, bUv: Vec2, cUv: Vec2, aColor: Color, bColor: Color, cColor: Color, texture: Texture): Void {
    rendererPushTriangleNative(ptr,
      a.x, a.y, b.x, b.y, c.x, c.y,
      aUv.x, aUv.y, bUv.x, bUv.y, cUv.x, cUv.y,
      aColor.r, aColor.g, aColor.b, aColor.a,
      bColor.r, bColor.g, bColor.b, bColor.a,
      cColor.r, cColor.g, cColor.b, cColor.a,
      texture
    );
  }

  public inline function begin() {
    rendererBeginNative(ptr);
  }

  public inline function end() {
    rendererEndNative(ptr);
  }
}

package krokus;

typedef RendererPtr = hl.Abstract<"krokus_renderer">

@:hlNative('krokus')
class Renderer {
  private var ptr: RendererPtr;

  private static function rendererCreateNative(width: Int, height: Int): RendererPtr {return null;}
  private static function rendererDisposeNative(r: RendererPtr): Void {}
  private static function rendererClearNative(r: RendererPtr): Void {}
  private static function rendererSetClearColorNative(r: Single, g: Single, b: Single): Void {}
  private static function rendererPushRectNative(
    renderer: RendererPtr,
    x0: Single, y0: Single,
    x1: Single, y1: Single,
    texture: Int
  ): Void {}
  private static function rendererBeginNative(r: RendererPtr): Void {}
  private static function rendererEndNative(r: RendererPtr): Void {}
  private static function rendererSetColorNative(re: RendererPtr, r: Single, g: Single, b: Single, a: Single): Void {}

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

  public inline function pushRect(pos: Vec2, dims: Vec2, texture: Texture): Void {
    rendererPushRectNative(ptr, pos.x, pos.y, dims.x, dims.y, texture);
  }

  public inline function begin() {
    rendererBeginNative(ptr);
  }

  public inline function end() {
    rendererEndNative(ptr);
  }

  public inline function setColor(col: Color): Void {
    rendererSetColorNative(ptr, col.r, col.g, col.b, col.a);
  }
}

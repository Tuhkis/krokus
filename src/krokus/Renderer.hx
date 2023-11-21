package krokus;

typedef RendererPtr = hl.Abstract<"krokus_renderer">

@:hlNative('krokus')
class Renderer {
  private var ptr: RendererPtr;

  private static function rendererCreateNative(width: Int, height: Int): RendererPtr {return null;}
  private static function rendererDisposeNative(r: RendererPtr): Void {}

  public function new(width: Int, height: Int) {
    ptr = rendererCreateNative(width, height);
  }

  public inline function dispose() {
    rendererDisposeNative(ptr);
  }
}

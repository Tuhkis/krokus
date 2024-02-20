package krokus;

typedef WindowPtr = hl.Abstract<"krokus_window">

@:hlNative('krokus')
class Window {
  private var ptr: WindowPtr;
  static private var initialised: Bool = false;

  private static function windowSystemInitNative(): Void {}
  private static function windowCreateNative(width: Int, height: Int, title: hl.Bytes, titleLen: Int): WindowPtr {return null;}
  private static function windowDisposeNative(window: WindowPtr) {}
  private static function windowShouldCloseNative(window: WindowPtr): Bool {return true;}
  private static function windowPollEventsNative(): Void {};
  private static function windowSwapBuffersNative(window: WindowPtr) {}

  public static inline function pollEvents() { windowPollEventsNative(); }

  public function new(width: Int, height: Int, title: String) {
    if (!initialised) {
      windowSystemInitNative();
      initialised = true;
    }
    ptr = windowCreateNative(width, height, cast (title, HString).toBytes(), title.length);
  }

  public inline function dispose() {
    windowDisposeNative(ptr);
  }

  public inline function shouldClose(): Bool {
    return windowShouldCloseNative(ptr);
  }

  public inline function swapBuffers(): Void {
    windowSwapBuffersNative(ptr);
  }
}

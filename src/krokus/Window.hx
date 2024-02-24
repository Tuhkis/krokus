package krokus;

typedef WindowPtr = hl.Abstract<"krokus_window">

@:hlNative('krokus')
class Window {
  private var ptr: WindowPtr;
  static private var initialised: Bool = false;

  private static function windowSystemInitNative(): Void {}
  private static function windowCreateNative(width: Int, height: Int, title: hl.Bytes, titleLen: Int): WindowPtr {return null;}
  private static function windowDisposeNative(window: WindowPtr): Void {}
  private static function windowShouldCloseNative(window: WindowPtr): Bool {return true;}
  private static function windowPollEventsNative(): Void {};
  private static function windowSwapBuffersNative(window: WindowPtr): Void {}
  private static function windowSetResizableNative(v: Int): Void {}
  private static function windowKeyDownNative(window: WindowPtr, key: Int): Bool {return false;}
  private static function windowSetSwapIntervalNative(interval: Int): Void {}

  public static inline function pollEvents() { windowPollEventsNative(); }
  public static inline function setResizable(resizable: Bool) {
    if (!resizable) {
      windowSetResizableNative(0);
      return;
    }
    windowSetResizableNative(1);
  }
  public static inline function setSwapInterval(interval: Int) { windowSetSwapIntervalNative(interval); }

  public function new(width: Int, height: Int, title: String) {
    if (!initialised) {
      windowSystemInitNative();
      initialised = true;
    }
    ptr = windowCreateNative(width, height, cast (title, HString).toBytes(), title.length);
  }

  public inline function dispose() {
    windowDisposeNative(ptr);
    ptr = null;
  }

  public inline function shouldClose(): Bool {
    return windowShouldCloseNative(ptr);
  }

  public inline function swapBuffers(): Void {
    windowSwapBuffersNative(ptr);
  }

  public inline function isKeyDown(key: Keycode): Bool {
    return windowKeyDownNative(ptr, key);
  }
}

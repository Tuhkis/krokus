package krokus;

@:hlNative('krokus')
class Clock {
  private var now: Single;
  private var prev: Single;

  private static function delay_native(ms: Single): Void {}
  private static function get_time_native(): Single { return 0.0; }

  public function new() {}

  public inline function tick(fps: Single): Single {
    now = get_time_native();
    var delta = this.now - this.prev;
    prev = now;
    delay_native(1000.0 / fps);
    return delta;
  }

  public inline function getTime(): Single { return get_time_native(); }
}


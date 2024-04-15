package krokus;

class Test extends App {
  static final WIDTH = 800;
  static final HEIGHT = 800;
  static final TITLE = "Krokus App";

  var pos = new Vec2(32, 32);
  var size = new Vec2(64, 64);
  var white: Texture;
  var mypng: Texture;

  public static function main() { new Test(WIDTH, HEIGHT, TITLE); }

  public function init() {
    white = TextureLoader.getWhite();
    mypng = TextureLoader.loadRGB("my1.png");
    fps = 0.0;
  }

  public function shutdown() {}

  public function tick(deltaTime: Single) {
    if (win.isKeyDown(Key.KEY_D)) {
      pos.x += 100.0 * deltaTime;
    }

    if (win.isKeyDown(Key.KEY_A)) {
      pos.x += -100.0 * deltaTime;
    }

    if (win.isKeyDown(Key.KEY_S)) {
      pos.y += 100.0 * deltaTime;
    }

    if (win.isKeyDown(Key.KEY_W)) {
      pos.y += -100.0 * deltaTime;
    }

    if (win.isKeyDown(Key.KEY_ESCAPE)) {
      quit();
    }
  }

  public function render() {
    g.pushRect(pos, size, mypng);
  }
}


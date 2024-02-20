package krokus;

class Test {
  public static function main() {
    var win = new Window(1000, 800, "Krokus app");
    var g = new Renderer(1000, 800);
    var white = TextureLoader.getWhite();
    var mypng = TextureLoader.loadTextureRGB("my1.png");
    var mainClock = new Clock();

    var whiteColor = new Color(1, 1, 1, 1);
    var v0 = new Vec2(0, 64);
    var v1 = new Vec2(200, 128);

    g.setClearColor(Color.GREY);

    while (!win.shouldClose()) {
      var deltaTime = mainClock.tick(60);
      g.clear();
      g.begin();
        g.setColor(whiteColor);
        g.pushRect(
          v1, v1,
          white
        );
        g.setColor(Color.RED);
        g.pushRect(
          v0, new Vec2(64, 64),
          mypng
        );
      g.end();

      Window.pollEvents();
      win.swapBuffers();
    }

    g.dispose();
    win.dispose();
  }
}


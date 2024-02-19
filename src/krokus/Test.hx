package krokus;

class Test {
  public static function main() {
    Window.init();
    var win = new Window(1000, 800, "Krokus app");
    var g = new Renderer(1000, 800);
    var white = TextureLoader.getWhite();
    var mypng = TextureLoader.loadTexture("my1.png");

    g.setClearColor(Color.RED);

    while (!win.shouldClose()) {
      g.clear();
      g.begin();
        g.pushRect(
          new Vec2(32, 32), new Vec2(64, 64),
          new Color(1.0, 1.0, 1.0, 1.0),
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


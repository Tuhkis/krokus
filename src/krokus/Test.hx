package krokus;

class Test {
  public static function main() {
    Window.init();
    var win = new Window(1000, 800, "Krokus app");
    var g = new Renderer(1000, 800);

    g.setClearColor(Color.RED);

    while (!win.shouldClose()) {
      g.clear();
      g.begin();
        g.pushTriangle(
          new Vec2(0, 0), new Vec2(64, 64), new Vec2(0, 64),
          new Vec2(0, 0), new Vec2(1, 1), new Vec2(0, 1),
          new Color(1, 1, 1, 1), new Color(1, 1, 1, 1), new Color(1, 1, 1, 1), 0
        );
      g.end();
    
      Window.pollEvents();
      win.swapBuffers();
    }
    
    g.dispose();
    win.dispose();
  }
}


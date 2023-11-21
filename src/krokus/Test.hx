package krokus;

class Test {
  public static function main() {
    Window.init();
    var win = new Window(800, 800, "Window title");
    var g = new Renderer(800, 800);

    while (!win.shouldClose()) {
      Window.pollEvents();
    }
    
    g.dispose();
    win.dispose();
  }
}


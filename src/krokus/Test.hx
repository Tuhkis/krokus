package krokus;

class Test {
  public static function main() {
    Window.init();
    var win = new Window(800, 800, "Krokus app");
    var g = new Renderer(800, 800);

    while (!win.shouldClose()) {
      g.clear();
    
      Window.pollEvents();
      win.swapBuffers();
    }
    
    g.dispose();
    win.dispose();
  }
}


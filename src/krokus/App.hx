package krokus;

class App {
  private var win: Window;

  public var g: Renderer;
  public var fps: Single = 0.0;

  public function new(width: Int, height: Int, title: String) {
    var prev: Single = Clock.getTime();
    var now: Single = prev;
    var deltaTime: Single = 0.0;

    win = new Window(width, height, title);
    g = new Renderer(width, height);
    g.setClearColor(Color.BLUE);

    while (!win.shouldClose()) {
      Window.pollEvents();
      now = Clock.getTime();
      deltaTime = now - prev;
      prev = now;
      tick(deltaTime);
      g.clear();
      g.begin();
      render();
      g.end();
      win.swapBuffers();
      if (fps > 0)
        Clock.delay(1000.0 / fps);
    }
    g.dispose();
    win.dispose();
  }

  public function tick(deltaTime: Single) {}
  public function render() {}
}


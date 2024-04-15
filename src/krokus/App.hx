package krokus;

abstract class App {
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

    init();

    while (true) {
      Window.pollEvents();
      if (win.shouldClose()) break;
      now = Clock.getTime();
      deltaTime = now - prev;
      prev = now;
      tick(deltaTime);
      g.clear();
      g.begin();
      render();
      g.end();
      win.swapBuffers();
      if (fps > 0.75)
        Clock.delay(1000.0 / fps);
    }
    quit();
  }

  public function quit() {
    shutdown();
    g.dispose();
    win.dispose();
    Sys.exit(0);
  }

  abstract function tick(deltaTime: Single): Void;
  abstract function render(): Void;
  abstract function init(): Void;
  abstract function shutdown(): Void;
}


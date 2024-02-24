package krokus;

class Color {
  public static final RED = new Color(1.0, 0.2, 0.2, 1.0);
  public static final BLUE = new Color(0.4, 0.6, 1.0, 1.0);
  public static final GREY = new Color(0.2, 0.2, 0.2, 1.0);

  public var r: Single = 0.0;
  public var g: Single = 0.0;
  public var b: Single = 0.0;
  public var a: Single = 0.0;

  public function new(p_r: Single, p_g: Single, p_b: Single, p_a: Single) {
    this.r = p_r;
    this.g = p_g;
    this.b = p_b;
    this.a = p_a;
  }
}


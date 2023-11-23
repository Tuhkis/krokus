package krokus;

@:hlNative('krokus')
class TextureLoader {
  private static function textureGetWhiteNative(): Texture {return 0;}

  public static inline function getWhite(): Texture {
    return textureGetWhiteNative();
  }
}


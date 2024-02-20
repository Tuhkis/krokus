package krokus;

@:hlNative('krokus')
class TextureLoader {
  private static function textureGetWhiteNative(): Texture {return 0;}
  private static function loadTextureRgbNative(path: hl.Bytes, pathLen: Int): Texture {return 0;}
  private static function loadTextureRgbaNative(path: hl.Bytes, pathLen: Int): Texture {return 0;}

  public static inline function getWhite(): Texture {
    return textureGetWhiteNative();
  }

  public static inline function loadTextureRGB(path: String): Texture {
    return loadTextureRgbNative(cast (path, HString).toBytes(), path.length);
  }

  public static inline function loadTextureRGBA(path: String): Texture {
    return loadTextureRgbaNative(cast (path, HString).toBytes(), path.length);
  }
}


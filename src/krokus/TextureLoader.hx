package krokus;

@:hlNative('krokus')
class TextureLoader {
  private static function textureGetWhiteNative(): Texture {return 0;}
  private static function loadTextureNative(path: hl.Bytes, pathLen: Int): Texture {return 0;}

  public static inline function getWhite(): Texture {
    return textureGetWhiteNative();
  }

  public static inline function loadTexture(path: String): Texture {
    return loadTextureNative(cast (path, HString).toBytes(), path.length);
  }
}


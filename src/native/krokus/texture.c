#include "texture.h"
#include "hl_string.h"
#include <stb_image.h>

HL_PRIM S32 HL_NAME(texture_get_white_native) (U0) {
  return sr_get_white_texture();
}

HL_PRIM S32 HL_NAME(load_texture_rgb_native) (vbyte* path, S32 path_len) {
  mut char path_buf[path_len + 1];
  path_buf[path_len] = 0;
  chars_from_vbytes(path_buf, path, path_len);

  mut S32 w, h, channels;
  mut U8* img = stbi_load(path_buf, &w, &h, &channels, 0);
  ASSERT(img != nullptr);

  mut U32 texture;
  glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  free(img);
  return texture;
}

HL_PRIM S32 HL_NAME(load_texture_rgba_native) (vbyte* path, S32 path_len) {
  mut char path_buf[path_len + 1];
  path_buf[path_len] = 0;
  chars_from_vbytes(path_buf, path, path_len);

  mut S32 w, h, channels;
  mut U8* img = stbi_load(path_buf, &w, &h, &channels, 0);
  ASSERT(img != nullptr);

  mut U32 texture;
  glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  free(img);
  return texture;
}

DEFINE_PRIM(_I32, texture_get_white_native, _NO_ARG)
DEFINE_PRIM(_I32, load_texture_rgb_native, _BYTES _I32)
DEFINE_PRIM(_I32, load_texture_rgba_native, _BYTES _I32)


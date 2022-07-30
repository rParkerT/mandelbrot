#include "bitmap.h"
#include <fstream>
#include <iostream>

namespace mandelbrot {

Bitmap::Bitmap(int width, int height)
    : width(width), height(height),
      pixels(std::make_unique<uint8_t[]>(width * height * color_num)) {}

bool Bitmap::write(const std::string &filename) {
  file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +
                          width * height * color_num;

  file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  info_header.width = width;
  info_header.height = height;

  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::binary);

  if (!file)
    return false;

  file.write(reinterpret_cast<char *>(&file_header), sizeof(file_header));
  file.write(reinterpret_cast<char *>(&info_header), sizeof(info_header));
  file.write(reinterpret_cast<char *>(pixels.get()),
             width * height * color_num);

  file.close();

  return true;
}

void Bitmap::set_pixel(int x, int y, const RGB &color) {
  uint8_t *pixel = pixels.get();
  pixel += (y * color_num) * width + (x * color_num);
  pixel[0] = color.b;
  pixel[1] = color.g;
  pixel[2] = color.r;
}

} // namespace mandelbrot

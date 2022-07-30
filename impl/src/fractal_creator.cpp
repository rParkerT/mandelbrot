#include "fractal_creator.h"
#include <cmath>

namespace mandelbrot {

FractalCreator::FractalCreator(int width, int height)
    : width(width), height(height),
      fractal(std::make_unique<int[]>(width * height)), bm(width, height) {}

void FractalCreator::calculate_iteration() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      double x_fractal = (x - width / 2 - 200) * 2.0 / height;
      double y_fractal = (y - height / 2) * 2.0 / height;
      int iterations =
          mandelbrot::Mandelbrot::get_iterations(x_fractal, y_fractal);
      fractal[y * width + x] = iterations;
    }
  }
}

void FractalCreator::draw_fractal() {
  RGB color = RGB(0, 0, 0);

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int iterations = fractal[y * width + x];
      if (iterations != mandelbrot::Mandelbrot::MAX_ITERATIONS &&
          iterations > 0) {
        int n = iterations % 16;
        color = get_color(n);
      }
      if (iterations == mandelbrot::Mandelbrot::MAX_ITERATIONS ||
          iterations == 0) {
        color = RGB(0, 0, 0);
      }
      bm.set_pixel(x, y, color);
    }
  }
}

RGB FractalCreator::get_color(int n) {
  if (color_map.count(n)) {
    return color_map.at(n);
  }
  return RGB(255, 255, 255);
}

void FractalCreator::draw_bitmap(const std::string &file_name) {
  bool created = bm.write(file_name);
  if (!created)
    std::cout << "Couldn' t create bitmap image file" << std::endl;
}

void FractalCreator::run(const std::string &file_name) {
  calculate_iteration();
  draw_fractal();
  draw_bitmap(file_name);
}

} // namespace mandelbrot

#include "fractal_creator.h"

int main() {
  int const WIDTH = 800;
  int const HEIGHT = 600;
  mandelbrot::FractalCreator fractal_creator(WIDTH, HEIGHT);
  std::string filename{"test.bmp"};
  fractal_creator.run(filename);

  return 0;
}

#include "mandelbrot.h"
#include <complex>

namespace mandelbrot {

int Mandelbrot::get_iterations(double x, double y) {
  std::complex<double> z = 0;
  std::complex<double> c(x, y);
  int iterations = 0;

  while (iterations < MAX_ITERATIONS) {
    z = z * z + c;
    if (std::abs(z) > 2) // not part of Mandelbrot set
      break;
    ++iterations;
  }
  return iterations;
}

} // namespace mandelbrot

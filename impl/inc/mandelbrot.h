#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace mandelbrot {

/**
 * Implementation of the Mandelbrot class.
 *
 * The Mandelbrot set https://en.wikipedia.org/wiki/Mandelbrot_set
 *
 */
class Mandelbrot {
public:
  /**
   * Constructor of Mandelbrot
   *
   * Default implementation
   */
  Mandelbrot() = default;
  /**
   * Destructor of Bitmap
   *
   * Default implementation
   */
  ~Mandelbrot() = default;

  /// Maximum number of iterations used in calculation of Mandelbrot set
  static constexpr int MAX_ITERATIONS = 1000;

  /**
   * Function that returns number of iterations from Mandelbrot set calculation.
   * Mandelbrot set may be created by sampling the complex numbers and
   * testing, for each sample point c if it crosses an arbitrarily chosen
   * threshold (-2 or 2). If it doesn't cross the threshold, iteration number
   * increases until it reaches MAX_ITERATIONS, if it does, loop terminates and
   * the last iteration value is returned.
   *
   * @param x x-coordinate in pixels
   * @param y y-coordinate in pixels
   * @return iteration number
   */
  static int get_iterations(double x, double y);
};

} // namespace mandelbrot

#endif /* MANDELBROT_H_ */

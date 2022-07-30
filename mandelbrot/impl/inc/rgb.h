#ifndef RGB_H_
#define RGB_H_

#include <iostream>

namespace mandelbrot {

/**
 * Implementation of the RGB structure.
 *
 * RGB is used to store color information to each pixel.
 *
 */
struct RGB {
  /// Red color
  uint8_t r;
  /// Red green
  uint8_t g;
  /// Red blue
  uint8_t b;

  /**
   * Constructor of RGB
   *
   * @param r red color
   * @param g green color
   * @param b blue color
   */
  RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

  /**
   * Destructor of RGB
   *
   * Default implementation
   */
  ~RGB() = default;
};

} // namespace mandelbrot

#endif /* RGB_H_ */

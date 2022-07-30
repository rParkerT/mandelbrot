#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "bitmap.h"
#include "mandelbrot.h"
#include "rgb.h"
#include <map>
#include <string>

namespace mandelbrot {

/**
 * Implementation of the FractalCreator class.
 *
 * FractalCreator class calls for bitmap file creation, Mandelbrot set
 * calculation and defining each pixel color
 *
 */
class FractalCreator {
  /// Image width
  int width{0};
  /// Image height
  int height{0};
  /// unique_ptr to fractal array
  std::unique_ptr<int[]> fractal{nullptr};
  /// Bitmap default ctor
  mandelbrot::Bitmap bm;
  /// Color map used to find color value for each pixel, based on the iteration
  /// calculated for that pixel
  std::map<int, RGB> color_map{
      {0, RGB(66, 30, 15)},     {1, RGB(25, 7, 26)},
      {2, RGB(9, 1, 47)},       {3, RGB(4, 4, 73)},
      {4, RGB(0, 7, 100)},      {5, RGB(12, 44, 138)},
      {6, RGB(24, 82, 177)},    {7, RGB(57, 125, 209)},
      {8, RGB(134, 181, 229)},  {9, RGB(211, 236, 248)},
      {10, RGB(241, 233, 191)}, {11, RGB(248, 201, 95)},
      {12, RGB(255, 170, 0)},   {13, RGB(204, 128, 0)},
      {14, RGB(153, 87, 0)},    {15, RGB(106, 52, 3)}};

  /**
   * Function that calls for Mandelbrot::get_iterations for each pixel in image.
   * Iteration value that is returned from that function is saved in fractal
   * array.
   */
  void calculate_iteration();

  /**
   * Function that sets the color value for each pixel, based on it's iteration
   * value, that is fetched from fractal array. To set color, iteration values
   * are scaled to color_map. If the scaled iteration value is not found in
   * color_map, color is set to white. If the iteration value is equal to
   * MAX_ITERATIONS or 0, color is set to black.
   */
  void draw_fractal();

  /**
   * Function that calls for bitmap file creation. In cas the file is not
   * created the error message is displayed.
   */
  void draw_bitmap(const std::string &file_name);

  /**
   * Function that returns color value from color map, based on key n.
   *
   * @param n scaled iteration value, calculated in Mandelbrot::get_iterations
   */
  RGB get_color(int n);

public:
  /**
   * Constructor of Mandelbrot
   *
   *
   * @param width of Image
   * @param height of Image
   */
  FractalCreator(int width, int height);

  /**
   * Destructor of Bitmap
   *
   * Default implementation
   */
  ~FractalCreator() = default;

  /**
   * Function that calls for bitmap file creation, Mandelbrot set
   * calculation and defining each pixel color
   *
   * @param filename name of the image file that will be created
   */
  void run(const std::string &file_name);
};

} // namespace mandelbrot

#endif /* FRACTALCREATOR_H_ */

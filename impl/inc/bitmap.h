#ifndef BITMAP_H_
#define BITMAP_H_

#include "bitmap_file_header.h"
#include "bitmap_info_header.h"
#include "rgb.h"
#include <memory>
#include <string>

namespace mandelbrot {

/**
 * Implementation of the Bitmap class.
 *
 * Class Bitmap is used to store color to pixel in image file.
 *
 */
class Bitmap {
private:
  /// Image width
  int width{0};
  /// Image height
  int height{0};
  /// unique_ptr to array of pixels in image
  std::unique_ptr<uint8_t[]> pixels{nullptr};

  /// Number of colors is set to 3, using RGB notation
  static constexpr int color_num = 3;

  /// BitmapFileHeader default ctor
  BitmapFileHeader file_header;
  /// BitmapInfoHeader default ctor
  BitmapInfoHeader info_header;

public:
  /**
   * Constructor of Bitmap
   *
   * @param width of Image
   * @param height of Image
   */
  Bitmap(int width, int height);

  /**
   * Destructor of Bitmap
   *
   * Default implementation
   */
  ~Bitmap() = default;

  /**
   * Function for creating image file with filename name. If file can not be
   * created, function return false.
   *
   * @param filename name of the image file that will be created
   * @return false if the image file can not be created, true if it is created
   */
  bool write(const std::string &filename);

  /**
   * Function that sets color value for specific pixel in pixels.
   *
   * @param x x-coordinate in pixels
   * @param y y-coordinate in pixels
   * @param color RGB structure that contains red, green, blue info
   */
  void set_pixel(int x, int y, const RGB &color);
};

} // namespace mandelbrot

#endif /* BITMAP_H_ */

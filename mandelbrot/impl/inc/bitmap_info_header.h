#ifndef BITMAP_INFO_HEADER_H_
#define BITMAP_INFO_HEADER_H_

#include <cstdint>

#pragma pack(push, 2)

namespace mandelbrot {

/**
 * Implementation of the BitmapInfoHeader structure.
 *
 * BitmapInfoHeader is used to create bitmap file header.
 *
 */
struct BitmapInfoHeader {
  /// Specifies the number of bytes required by the structure.
  int32_t header_size{40};
  /// Specifies the width of the bitmap, in pixels.
  int32_t width;
  /// Specifies the height of the bitmap, in pixels.
  int32_t height;
  /// Specifies the number of planes for the target device. This value must be
  /// set to 1.
  int16_t planes{1};
  /// Specifies the number of bits per pixel (bpp).
  int16_t bits_per_pixel{24};
  /// Specifies compression of file, no compression set
  int32_t compression{0};
  /// Specifies the size, in bytes, of the image. Set to 0 for uncompressed RGB
  /// bitmaps.
  int32_t data_size{0};
  /// Specifies the horizontal resolution, in pixels per meter, of the target
  /// device for the bitmap.
  int32_t horizontal_resolution{2400};
  /// Specifies the vertical resolution, in pixels per meter, of the target
  /// device for the bitmap.
  int32_t vertical_resolution{2400};
  /// Specifies the number of color indices in the color table that are actually
  /// used by the bitmap.
  int32_t colors{0};
  /// Specifies the number of color indices that are considered important for
  /// displaying the bitmap. If this value is zero, all colors are important.
  int32_t important_colors{0};
};

} // namespace mandelbrot

#pragma pack(pop)

#endif /* BITMAP_INFO_HEADER_H_ */

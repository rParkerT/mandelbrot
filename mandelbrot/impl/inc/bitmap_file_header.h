#ifndef BITMAP_FILE_HEADER_H_
#define BITMAP_FILE_HEADER_H_

#include <cstdint>

#pragma pack(push, 2)

namespace mandelbrot {

/**
 * Implementation of the BitmapFileHeader structure.
 *
 * BitmapFileHeader is used to create bitmap file header.
 *
 */
struct BitmapFileHeader {
  /// File type, must be BM
  char header[2]{'B', 'M'};
  /// The size, in bytes, of the bitmap file
  int32_t file_size;
  /// Reserved; must be zero.
  int32_t reserved{0};
  /// The offset, in bytes, from the beginning of the BITMAPFILEHEADER structure
  /// to the bitmap bits.
  int32_t data_offset;
};

} // namespace mandelbrot

#pragma pack(pop)

#endif /* BITMAP_FILE_HEADER_H_ */

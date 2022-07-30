include_directories(${Mandelbrot_SOURCE_DIR}/impl/inc)
add_library(bitmap bitmap.cpp)
add_library(mandelbrot_class mandelbrot.cpp)
add_library(fractal_creator fractal_creator.cpp)
add_executable(mandelbrot main.cpp bitmap.cpp mandelbrot.cpp fractal_creator.cpp)

target_link_libraries(mandelbrot mandelbrot_class bitmap fractal_creator)

Implementation of the Mandelbrot set calculation. It creates bitmap file, which
can be seen in project.

CMake is used for project build. Doxygen is used for project documentation.

To build project and project documentation, go to root directory:
<pre>
$ cd root
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make doc
</pre>
To check valgrind: valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./mandelbrot

Camera demo
===========

```
mkdir build && cd build
conan install .. --build missing
cmake ..
cmake --build .
conan imports .. -if=.

cd bin
./camera
```

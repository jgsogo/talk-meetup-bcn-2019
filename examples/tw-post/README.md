How to post a tweet
===================


```
mkdir build && cd build
conan install .. --build missing
cmake .. -DCMAKE_MODULE_PATH=$(pwd)
cmake --build .
sourcce ../secret.env && ./tw-post
```

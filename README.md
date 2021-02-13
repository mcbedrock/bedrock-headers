# Minecraft: Bedrock Edition modding headers

#### This is currently being updated for 1.16.200.02, this project was abandoned for a time when symbols were stripped from the official binaries but they're back since 1.16.x!

You can view symbols from your native lib with `nm -nDC libminecraftpe.so` which is a handy utility provided by `binutils`

This repository aims to be the most complete, organized, and up to date headers available for the game.

Obviously it's far from this at the moment but yes, you too can help contribute!

## Using

Simply add `include(../path/to/headers/CMakeLists.txt` to your CMake project and go ham!

# Minecraft: Bedrock Edition modding headers

#### This is currently (being) adapted to the Android 1.16.200.02 x86_64 binary. This project was abandoned for a while when symbols were stripped from the official binaries but they're back in this version. Field offsets are similar to Windows 10 Edition and some info is ripped from a W10E project.

You can view symbols from your lib with `nm -anDC libminecraftpe.so` which is a handy utility provided by `binutils`. If you only see MSA (Xbox Live stuff), AppPlatform, FMod, and other related symbols then they might be stripped: this seems to be the case in latest betas.

Rest assured if you're determined you can pattern search for instances of these classes and the field offsets provided in this project should be relatively the same. However, function offsets are currently not a priority in this project so you will sadly have to implement those on your own for now.

This repository aims to be the most complete, organized, and up to date headers available for the game.

Obviously it's far from this at the moment but yes, you too can help contribute!

## Using

For CMake users you can simply `include(bedrock-headers/CMakeLists.txt)` in your project!

For everything else such as traditional Makefile you will need to add the search paths manually.
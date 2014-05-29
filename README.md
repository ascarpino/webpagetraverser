WebPageTraverser
================

Description
-----------
WebPageTraverser is a Qt tool to retrieve information about HTML elements in a
web page.

It includes info about the position, the text, the size and more.

Dependencies
------------
* qt >= 5.0 (http://qt-project.org/)
* cmake >= 2.8.8 (http://www.cmake.org/)

Build and installation
----------------------
1. $ mkdir build
2. $ cd build
3. $ cmake ../
4. $ make
5. \# make install

Potential Errors
----------------
* If CMake does not find the path to your Qt 5 instalation, then set the *-DCMAKE_PREFIX_PATH* option to that path:

```
$ cmake -DCMAKE_PREFIX_PATH=/Users/username/Qt/5.3/clang_64/
```

License
-------
LGPL3

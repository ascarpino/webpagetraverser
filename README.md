# WebPageTraverser

## Description

WebPageTraverser is a Qt tool to retrieve information about HTML elements in a web page.

It includes info about the position, the text, the size and more.

## Dependencies

* [Qt](http://qt-project.org/) >= 5.0
* [CMake](http://www.cmake.org/) >= 2.8.8

## Build and installation

    $ mkdir build
    $ cd build
    $ cmake ../
    $ make
    # make install

### Build errors

* If CMake does not find the path to your Qt 5 instalation, then set the `-DCMAKE_PREFIX_PATH` option to that path, e.g.:

    $ cmake -DCMAKE_PREFIX_PATH=/usr/local/lib/cmake/

**NOTE:** That path should point to the parent of the folder that contains Qt5CoreConfig.cmake

## Usage

    $ WebPageTraverser http://www.google.it

Check `WebPageTraverser -h` for more.

### Runtime errors

* `QXcbConnection: Could not connect to display`

You don't have a X11 session running. You can simulate it by using [Xvfb](http://xorg.freedesktop.org), install it and then run:

    $ xvfb-run -a WebPageTraverser http://www.google.it

## License

LGPL3

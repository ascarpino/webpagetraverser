WebPageTraverser
================

Description
-----------
WebPageTraverser is a Qt tool to retrieve information about HTML elements in a
web page.

It includes info about the position, the text, the size and more.

Dependencies
------------
* [Qt](http://qt-project.org/) >= 5.0
* [CMake](http://www.cmake.org/) >= 2.8.8

Build and installation
----------------------
    $ mkdir build
    $ cd build
    $ cmake ../
    $ make
    # make install

Potential Errors
----------------
##mac
* If CMake does not find the path to your Qt 5 instalation, then set the `-DCMAKE_PREFIX_PATH` option to that path, e.g.:

    $ cmake -DCMAKE_PREFIX_PATH=/Users/username/Qt/5.3/clang_64/
    
## Ubuntu
* If CMake does not find the path to your Qt 5 instalation, then set the `-DCMAKE_PREFIX_PATH` option to that path, e.g.:

    $ cmake -DCMAKE_PREFIX_PATH=/opt/Qt/5.3/clang_64/

**Check that the parent of the folder that contains Qt5CoreConfig.cmake**

Usage
-----
    $ WebPageTraverser http://www.google.it

Check `WebPageTraverser -h` for more.

License
-------
LGPL3

# Descrizione Progetto

## Errors

1. error **QXcbConnection: Could not connect to display **

install xvfb
```
#!bash

$ sudo apt-get install xvfb

$ xvfb-run -a WebPageTraverser -j
```
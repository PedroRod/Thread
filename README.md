Introduction
------------
Simple C++ thread library for multi threading applications

I created this small library for personal use, to make the use of threading in C++ cleaner and easier to read.

Notes
------------
This library does not allow you to forcefully stop a thread since that is never a good idea, instead it gives you an atomic boolean that you can monitor and stop the thread execution accordingly.

Tests
------------
This library contains a set (8) of seasy to understand googletests that serve as documentation.

Contributing
------------
I will be more than happy to see people contribute to this small lib, If you wish to contribute please do so with clean code and clean/meaningful tests.
As a side note, If you see any code smells in this library, please let me know so I can refactor.
I try to write as clean and beautiful code as possible.


License
------------
Copyright (c) 2015 Pedro Rodriguez

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

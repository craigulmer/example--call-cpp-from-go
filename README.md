example--call-cpp-from-go
=========================

Simple example of how to call simple c++ code from go


I've been working on a project that has a good bit of C++ code and I wanted to see if I could interface with the C++ from Go. There seem to be a few ways to do this. If you're trying to do a lot of ellaborate stuff, people say go with SWIG to wrap the calls (and then wrap them with your own code to make it usable!). I just needed something simple though- something that could create a class and then invoke some of its methods. 

The first step in getting things working was figure out how to build C code that could take advantage of C++ classes. That means, compile the class with g++, compile some C code calling the class with gcc, and then link the two together via gcc. As it turns out, someone was wondering the exact same thing on StackOverflow.

See the answers for "Elegantly call C++ from C"
http://stackoverflow.com/questions/7281441/elegantly-call-c-from-c

The above q/a will explain how to make a C header that both C and C++ will like, and how to write some simple trampoline functions to jump into your C++ code from C. Perfect.

The next step was figuring out how to get Go to build code that links in with a library of our C++/C code. In a nutshell, you can do this by putting some cgo directives in comments, import C, and deal with Go<->C type conversions. If you do it right, you should be able to do a "go build" and it will figure itself out. Thanks to David Fritz explaining the Go part and fixing my problems.

Go Notes:
- Your C/C++ code must be shared (-shared) and relocatable (-fPIC) 
- The Go code must include lib paths to your library (-L. -lmyclass)
- If you're using c++ code, you'll need -lstdc++ for C++ things
- Make sure the shared lib is in your LD_LIBRARY_PATH at runtime,
   as it gets loaded in at runtime
- Be warned that Go is a little aggressive in inferring what to
   include. I had a test program with a main in its source and
   Go somehow pulled that in and gave errors 


To build:
make
make run

Running make should build three executables:
myclass_from_cpp -- example of cpp code
myclass_from_c   -- example of C code calling C++
myclass from_go  -- example of Go calling C++

The "make run" command should show you how to invoke the go code from the command line.

This was tested on a stock fedora 17 machine with go 1.0.3 and gcc 4.7.2 20120921.

 
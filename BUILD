 == Before compiling ==

make sure that the headers of libgmp are installed on your system (e.g. libgmp-dev), and, of course, the library itself (it should be installed when installing the header files)
 
Some tips for compiling hpcalc:
 
The makefile compiles the source code efficiently into a single ELF file (architecture depending of the gcc version). There are some preprocessor constants
which you may change to customize the debug level, precision etc.

        -- in headers/math_hpcalc.h: ACC (for ACCuracy) defines the default accuracy for GMP in bits. Can be dynamically changed with the option '-b'.
        -- in headers/main.h: DEBUG controls if hpcalc prints more or less debug information. Of course you may insert your own debug routines.
        -- in headers/main.h: ERR_DATATYPE controls the error message if the user gives conflicting datatypes (e.g. hpcalc -i -f)
        -- in headers/main.h: ERR_CALCTYPE controls the error message if the user gives conflicting calculation types (e.g. hpcalc -i -a -s)


If you have questions about git, visit http://lbo.spheniscida.de and the linked doc files.

== The Build Process itself ==

Simply execute make.sh and you get the built ELF binary (or whatever) in build/.

You may also use the makefile, but it's recommended to use the shellscript.

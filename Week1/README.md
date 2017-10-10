# This week:
  - Get to know your tools - Visual Studio and CodeBlocks
  - Compilation of basic "Hello World" C++ program.
  - Walk-trough of basic syntax.
  - Variable declarations
  - Data types
    - int, float (just to get started)
  - Input/Output - cin and cout

  + Optional:
    - C++ compilation process example
    
# The C++ compilation process:

Given a filename 'sample.cpp', the steps to obtain an executable file are as follows:

1. The C++ preprocessor:

   Extend the 'sample.cpp' source code with the code
   in the included header files via the C++ preprocessor:

   Result in: 'sample_extended.cpp'

2. Compiler:

   Compile 'sample_extended.cpp'
   into an assembly code for the current platform:

   Result in: 'sample_assembly.s'


3. Assembler:

   The assembler code 'sample_assembly.s' is assembled into
   and object code for the platform.

   Result in: 'sample_object_file.o'

4. Linker:

   The object file 'sample_object_file.o' is linked together
   with the object files of any library functions used to
   produce an executable file 'sample'.

   Result in: 'sample'.


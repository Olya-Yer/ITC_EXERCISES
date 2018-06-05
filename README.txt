
This is the README file of “Battle Ship” program developed by
Galust Betkhemyan and Sevak Sahakyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. BUILD
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION
        

1. AUTHOR
Galust Betkhemyan, Olya Yeritspokhyan.
E-mail: olya.yeritspokhyan@gmail.com
		galustbetkhemyan@gmail.com

Project Maintainer
	Galust Betkhemyan, Olya Yeritspokhyan.
	olya.yeritspokhyan@gmail.com
	galustbetkhemyan@gmail.com
	
2. INTRODUCTION
The “Smart Array” program presents an improved version of C++ array. 
The program creates an array with ability to resize. 

3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen
make

4. BUILD
See the following commands in the project root directory.
Build the project
	make
	
Delete secondary files
	make clean

5. DIRECTORY STRUCTURE
- smart_array – the top directory
	- src – should contain the source code of the project
	- makefile – the top makefile for building the project
	- docs -  for containing documentations
		Product requirements document
		Functional specification document
		Development specification document
		/doxygen_config should contain file for doxygen configuration file

After building, the following directories should be created:
	- deps – should contain dependency files
	- obj – should contain oject files
	- bin – should contain executable file
	
	
6. USAGE
The “Smart Array” program can be run with "bin/program" command.
The program presents class improvement the C++ array. The user can create an array ,
    fill it with integers with  function set_element(index, value); get value of a cell
    (get_element(index)), resize the array (i.e. make it bigger or cut off from
    the end). 
    The class also provides print_array() method for visualization of the array.

7. DOCUMENTATION
"make docs" command generates doxygen documentation.

Doxygen also generates documentation from C/C++ code comments.

To see the generated documentation use ./docs/doxygen/html/index.html.

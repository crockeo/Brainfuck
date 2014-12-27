#ifndef _IO_HPP_
#define _IO_HPP_

//////////////
// Includes //
#include <istream>
#include <string>

//////////
// Code //

// Running a program based on a given stream.
void runProgram(std::istream&);

// Running a program based on a given file path.
void runProgram(std::string);

#endif

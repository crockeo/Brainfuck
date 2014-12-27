#ifndef _PARSER_HPP_
#define _PARSER_HPP_

//////////////
// Includes //
#include <istream>

#include "brainfuck.hpp"

//////////
// Code //

// Running a parser on an input and a BrainfuckState.
BrainfuckState runParser(BrainfuckState, std::istream&) throw(BrainfuckException);

#endif

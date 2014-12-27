#include "brainfuck.hpp"

//////////////
// Includes //
#include <string>
#include <vector>

//////////
// Code //

// Creating a BrainfuckException with a given message.
BrainfuckException::BrainfuckException(std::string msg) {
    this->msg = msg;
}

// Creating a BrainfuckException with a generic message.
BrainfuckException::BrainfuckException() {
    this->msg = "Generic Brainfuck exception.\n";
}

// Returning a c_str() version of msg.
const char* BrainfuckException::what() const throw() {
    return this->msg.c_str();
}

// Creating the internal state with a given size.
BrainfuckState::BrainfuckState(int size) {
    this->data = std::vector<unsigned char>(size);
    this->loc = 0;
}

// Creating an internal state with the default size.
BrainfuckState::BrainfuckState() {
    this->data = std::vector<unsigned char>(DEFAULT_SIZE);
    this->loc = 0;
}

// Peeking at the current index.
unsigned char BrainfuckState::peek() const {
    return this->data[this->loc];
}

// Poking at the current index.
void BrainfuckState::poke(unsigned char byte) { this->data[this->loc] = byte; }

// Getting the current size.
int BrainfuckState::size() const {
    return this->data.size();
}

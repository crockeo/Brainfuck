#include "brainfuck.hpp"

//////////////
// Includes //
#include <vector>

//////////
// Code //

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
unsigned char BrainfuckState::peek() { return this->data[this->loc]; }

// Poking at the current index.
void BrainfuckState::poke(unsigned char byte) { this->data[this->loc] = byte; }

// Getting the current size.
int BrainfuckState::getSize() { return this->data.size(); }

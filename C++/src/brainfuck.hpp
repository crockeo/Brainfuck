#ifndef _BRAINFUCK_HPP_
#define _BRAINFUCK_HPP_

//////////////
// Includes //
#include <exception>
#include <string>
#include <vector>

//////////
// Code //

// The maximum size of the brainfuck array.
const static int DEFAULT_SIZE = 30000;

class BrainfuckException : public std::exception {
private:
    std::string msg;

public:
    // Creating a BrainfuckException with a given message.
    BrainfuckException(std::string);

    // Creating a BrainfuckException with a generic message.
    BrainfuckException();

    // Returning a c_str() version of msg.
    const char* what() const throw();
};

// The internal state of the brainfuck array.
class BrainfuckState {
private:
    std::vector<unsigned char> data;

public:
    int loc;

    // Creating the internal state with a given size.
    BrainfuckState(int);

    // Creating an internal state with the default size.
    BrainfuckState();

    // Peeking at the current index.
    unsigned char peek() const;

    // Poking at the current index.
    void poke(unsigned char);

    // Getting the current size.
    int size() const;
};

#endif

#include "parser.hpp"

//////////////
// Includes //
#include <iostream>
#include <istream>

#include "brainfuck.hpp"

//////////
// Code //

// Attempting to start a location.
BrainfuckState doLoop(BrainfuckState state, std::string str, int& loc) {
    int eloc;
    for (eloc = loc; str[eloc] != ']'; eloc++) {
        if (eloc >= str.size())
            throw BrainfuckException("Expected a ']' to close the loop.\n");
    }

    std::string sub = str.substr(loc + 1, eloc - 2);
    while (state.peek())
        state = runParser(state, sub);
    loc = eloc + 1;

    return state;
}

// Parsing a single character in the brainfucks.
BrainfuckState parseChar(BrainfuckState state, char c) {
    switch (c) {
    case '>':
        state.loc++;
        if (state.loc >= state.size())
            state.loc = 0;
        break;
    case '<':
        state.loc--;
        if (state.loc < 0)
            state.loc = state.size() - 1;
        break;
    case '+':
        state.poke(state.peek() + 1);
        break;
    case '-':
        state.poke(state.peek() - 1);
        break;
    case '.':
        std::cout << state.peek();
        break;
    case ',':
        std::cout << "NEED TO IMPLEMENT ','!!!" << std::endl;
        break;
    case '[':
        throw BrainfuckException("Unexpected '['!\n");
    case ']':
        throw BrainfuckException("Unexpected ']'!\n");
    }

    return state;
}

// Running a parser on an input and a BrainfuckState.
BrainfuckState runParser(BrainfuckState state, std::string str) throw(BrainfuckException) {
    for (int loc = 0; loc < str.size(); loc++) {
        if (str[loc] == '[')
            state = doLoop(state, str, loc);
        else
            state = parseChar(state, str[loc]);
    }

    return state;
}

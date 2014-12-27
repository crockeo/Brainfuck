//////////////
// Includes //
#include <iostream>

#include "io.hpp"

//////////
// Code //

// The entry point.
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Proper usage: " << argv[0] << " <source file>" << std::endl;
        return 1;
    }

    try {
        runProgram(std::string(argv[1]));
    } catch (const std::string& msg) {
        std::cout << msg << std::endl;
        return 1;
    }

    return 0;
}

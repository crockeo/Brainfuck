#include "io.hpp"

//////////////
// Includes //
#include <fstream>
#include <istream>
#include <string>

#include "brainfuck.hpp"
#include "parser.hpp"

//////////
// Code //

// Running a program based on a given stream.
void runProgram(std::istream& stream) {
    std::string str;
    char c;

    while (!stream.eof()) {
        stream.get(c);
        str.push_back(c);
    }

    runParser(BrainfuckState(), str);
}

// Running a program based on a given file path.
void runProgram(std::string path) throw(std::string) {
    std::ifstream reader(path);
    if (!reader.good())
        throw std::string("Failed to open source file.");

    runProgram(reader);

    reader.close();
}

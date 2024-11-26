#include <iostream>
#include <filesystem>
#include <fstream>

#include "CodeLoc.h"

class Reader
{
private:
    // the input file content
    std::ifstream input;
    // the current char in input
    char curChar = '\0';
    // the  current localion of the current character on the format (for example : L3C9)
    CodeLoc curCodeLoc{1ull, 0ull};
    // check if reached the end of file
    bool moreToRead = false;

public:
    explicit Reader(std::filesystem::path &path);
    ~Reader();

    // return the current character in input
    char getChar() const;
    // return the current location of current character
    CodeLoc getCodeLoc() const;
    // check if we reach the end of the file input to terminate the program
    bool isEOF() const; // true -> not more to read;
    // move on in reading input file
    void advance();
    // check if the current character equals to expected one
    void expect(char c);
};

#include "Reader.h"
#include <fstream>
#include <filesystem>
#include <cassert>

// constructor
Reader::Reader(std::filesystem::path &path)
{
    // read the input file from provided path
    input = std::ifstream(path);

    // check if the input file is not read
    if (!input.is_open())
    {
        throw std::runtime_error("Reader error: file path is not correct..!");
    }

    // start reading the input
    advance();
}

// destructor
Reader::~Reader()
{
    // close the input file
    input.close();
}

// move on reading the input file
void Reader::advance()
{
    // check if we reach the end of the file then -> terminate
    assert(!isEOF());

    // read the next target character from input file and store it in curChar if there is no character -> moreToRead = false (it is the end of the file)
    if (!input.get(curChar))
    {
        moreToRead = false;
    }
    // check if the reader fetch the end of the line
    if (curChar == '\0')
    {
        curCodeLoc.line++;
        curCodeLoc.column = 0;
    }
    curCodeLoc.column++;
}

// check if we reach the end of the file
bool Reader::isEOF() const
{
    return !moreToRead;
}

// return the current char
char Reader::getChar() const
{
    return curChar;
}

// return the location of the current char
CodeLoc Reader::getCodeLoc() const
{
    return curCodeLoc;
}

// check if the current character equals to expected one
void Reader::expect(char c)
{
    advance();
    assert(curChar == c);
}
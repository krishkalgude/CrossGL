#ifndef LEXER_H
#define LEXER_H

#include "Tokens.h"

class Lexer {
    std::string input;
    char currentChar;
    size_t pos;

    void advance();
public:
    Lexer(const std::string& input);
    Token getNextToken();
};

#endif 
#include "Lexer.h"

Lexer::Lexer(const std::string& input) : input(input), pos(0), currentChar(input[pos]) {}

void Lexer::advance() {
    pos++;
    if (pos < input.length()) {
        currentChar = input[pos];
    } else {
        currentChar = '\0';
    }
}

Token Lexer::getNextToken() {
     if (currentChar == '<') {
        advance();
        if (currentChar == '<') {
            advance();
            if (currentChar == '=') {
                advance();
                return Token(T_ASSIGN_SHIFT_LEFT, "<<=");
            }
           
        }
       
    }

    return Token(TokenType::UNKNOWN, "");  
}

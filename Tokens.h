#ifndef TOKENS_H
#define TOKENS_H

enum TokenType {
    T_ASSIGN_SHIFT_LEFT,  
};

class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

#endif 

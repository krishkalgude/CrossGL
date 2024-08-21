#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "ASTNodes.h"

class Parser {
    Lexer lexer;
    Token currentToken;

    void advanceToken();
    std::unique_ptr<Node> parsePrimaryExpression();
public:
    Parser(Lexer lexer);
    std::unique_ptr<Node> parseAssignmentExpression();
};

#endif 

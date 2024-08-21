#include "Parser.h"

Parser::Parser(Lexer lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

void Parser::advanceToken() {
    currentToken = lexer.getNextToken();
}

std::unique_ptr<Node> Parser::parsePrimaryExpression() {
    return nullptr;
}

std::unique_ptr<Node> Parser::parseAssignmentExpression() {
    std::unique_ptr<Node> lhs = parsePrimaryExpression();

    if (currentToken.type == T_ASSIGN_SHIFT_LEFT) {
        advanceToken();  
        std::unique_ptr<Node> rhs = parseAssignmentExpression();
        return std::make_unique<AssignmentShiftLeftNode>(std::move(lhs), std::move(rhs));
    }

    return lhs;
}

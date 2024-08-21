#include <iostream>
#include <string>
#include <memory>  
#include <vector> 
enum TokenType {
    T_ASSIGN_SHIFT_LEFT,  
};
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
}
Node* Parser::parseAssignmentExpression() {
    
    Node* lhs = parsePrimaryExpression();
    if (currentToken.getType() == T_ASSIGN_SHIFT_LEFT) {
        Token op = currentToken;
        advanceToken(); 
        Node* rhs = parseAssignmentExpression();  
        return new AssignmentShiftLeftNode(lhs, rhs);
    }
return lhs;
}
class AssignmentShiftLeftNode : public Node {
public:
    Node* lhs;
    Node* rhs;

    AssignmentShiftLeftNode(Node* lhs, Node* rhs) : lhs(lhs), rhs(rhs) {}

    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
};
void CodeGenerator::visit(AssignmentShiftLeftNode* node) {
   
    node->lhs->accept(this);
    node->rhs->accept(this);
    output << " <<=";
}
void testShiftLeftAssignment() {
    std::string code = "a <<= 3;";
    Lexer lexer(code);
    Parser parser(lexer);
    
    Node* root = parser.parse();
   
}

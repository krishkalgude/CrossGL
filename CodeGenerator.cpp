#include "Visitor.h"
#include <iostream>

class CodeGenerator : public Visitor {
public:
    void visit(AssignmentShiftLeftNode* node) override {
        
        std::cout << "Generating code for left shift assignment:\n";
        node->lhs->accept(this);
        std::cout << " <<=";
        node->rhs->accept(this);
    }
};

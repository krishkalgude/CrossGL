#ifndef VISITOR_H
#define VISITOR_H

#include "ASTNodes.h"

class Visitor {
public:
    virtual void visit(AssignmentShiftLeftNode* node) = 0;
    virtual ~Visitor() = default;
};

#endif 

#ifndef AST_NODES_H
#define AST_NODES_H

#include <memory>

class Visitor;

class Node {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Node() = default;
};

class AssignmentShiftLeftNode : public Node {
public:
    std::unique_ptr<Node> lhs;
    std::unique_ptr<Node> rhs;

    AssignmentShiftLeftNode(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs)
        : lhs(std::move(lhs)), rhs(std::move(rhs)) {}

    void accept(Visitor* visitor) override;
};

#endif 

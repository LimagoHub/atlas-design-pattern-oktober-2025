//
// Created by JoachimWagner on 29.10.2025.
//

#pragma once

#include "AbstractNode.h"

class Node :public AbstractNode{
public:

    using AbstractNode::AbstractNode;
    void print(std::ostream &os) const override {
        os << std::string{"Node: "};
        AbstractNode::print(os);
    }

    auto getChildren() const -> const Children & override {
        return children;
    }

    auto append(AbstractNodeShared child)-> void {
        child->setParent(weak_from_this());
        children.push_back(child);
    }
private:
    Children children;
};

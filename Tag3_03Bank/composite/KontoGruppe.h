//
// Created by JoachimWagner on 29.10.2025.
//

#pragma once

#include "AbstractBankNode.h"

class KontoGruppe : public AbstractBankNode{
public:

    using AbstractBankNode::AbstractBankNode;
    void print(std::ostream &os) const override {
        os << std::string{"KontoGruppe: "};
        AbstractBankNode::print(os);
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

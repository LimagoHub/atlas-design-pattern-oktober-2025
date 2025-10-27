//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <iostream>
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"
namespace mitarbeiter::visitor {

    class PrintVisitor: public AbstractMitarbeiterVisitor {
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            std::cout << lohn_empfaenger << "\n";
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            std::cout << gehalts_empfaenger << "\n";
        }
    };

} // visitor

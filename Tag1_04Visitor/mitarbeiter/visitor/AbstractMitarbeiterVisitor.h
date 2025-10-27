//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once
#include "MitarbeiterVisitor.h"
namespace mitarbeiter::visitor {

    class AbstractMitarbeiterVisitor: public MitarbeiterVisitor {
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            // OK
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            //ok
        }
    };

} // visitor

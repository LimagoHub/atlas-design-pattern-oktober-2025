//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once
namespace mitarbeiter {
    class GehaltsEmpfaenger;
    class LohnEmpfaenger;
}

namespace mitarbeiter::visitor {

    class MitarbeiterVisitor {
    public:
        virtual void visit(mitarbeiter::LohnEmpfaenger &lohn_empfaenger) = 0;

        virtual void visit(mitarbeiter::GehaltsEmpfaenger &gehalts_empfaenger) = 0;
    };

}

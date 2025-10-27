//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <iostream>
#include "AbstractState.h"

class StateA: public AbstractState{
public:

    using AbstractState::AbstractState;
    void drucken() override {
        std::cout << "Hier druckt A" << std::endl;
    }

    void changeToB() override {
        getBusiness()->current = getBusiness()->stateB;
    }
};

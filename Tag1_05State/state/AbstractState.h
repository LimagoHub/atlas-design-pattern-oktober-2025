//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once
#include <stdexcept>
#include "State.h"
#include "../Business.h"

class AbstractState :public State{
    Business * business;
public:
    explicit AbstractState(Business *business) : business(business) {}

    ~AbstractState()  = default;
    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }
protected:
    Business *getBusiness() const {
        return business;
    }

};

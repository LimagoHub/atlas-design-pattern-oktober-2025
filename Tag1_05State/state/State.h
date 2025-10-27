//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once


class State {
public:
    virtual ~State()=default;

    // Fachlogik
    virtual void drucken() = 0;

    virtual void changeToA() = 0;
    virtual void changeToB() = 0;
};

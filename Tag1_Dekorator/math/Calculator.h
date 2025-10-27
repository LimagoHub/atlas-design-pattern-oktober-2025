//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once


class Calculator {

public:

    virtual ~Calculator() = default;

    virtual double add(double a , double b) = 0;

    virtual double sub(double a , double b) = 0;
};

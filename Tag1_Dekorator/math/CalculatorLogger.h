//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include "Calculator.h"

class CalculatorLogger: public Calculator{
    std::unique_ptr<Calculator> calculator;

public:
    explicit CalculatorLogger(std::unique_ptr<Calculator> calculator) : calculator(std::move(calculator)) {}

    double add(double a, double b) override {
        std::cout << "Add wurde gerufen" << std::endl;
        return calculator->add(a,b);
    }

    double sub(double a, double b) override {
        return calculator->sub(a,b);
    }
};

//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include "../math/Calculator.h"


class CalcClient {
    std::unique_ptr<Calculator> calculator;
public:

    explicit CalcClient(std::unique_ptr<Calculator> calculator) : calculator(std::move(calculator)) {}

    void go() {
        std::cout << calculator->add(3,4) << std::endl;
    }

};

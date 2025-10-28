//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"

namespace command {
    using Calc=math::Calculator;
    class PrintCommand :public AbstractCommand{
    public:
        ~PrintCommand() override = default;
        auto execute() -> void override {
            Calc::getInstance()->print();
        }
    };

} // command

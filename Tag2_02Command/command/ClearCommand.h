//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"


namespace command {
    using Calc=math::Calculator;

    class ClearCommand: public Command {
        double value;
    public:
        ~ClearCommand() override = default;

        auto parse(const StringVector &tokens) -> void override {
            value = std::stod(tokens[1]);
        }

        auto execute() -> void override {
            value = Calc::getInstance()->getMemory();
            Calc::getInstance()->clear();
        }

        auto undo() -> void override {
            Calc::getInstance()->setMemory(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };

} // command

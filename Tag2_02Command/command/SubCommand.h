//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"


namespace command {
    using Calc=math::Calculator;

    class SubCommand: public Command {
        double value;
    public:
        ~SubCommand() override = default;

        auto parse(const StringVector &tokens) -> void override {
            value = std::stod(tokens[1]);
        }

        auto execute() -> void override {
            Calc::getInstance()->sub(value);
        }

        auto undo() -> void override {
            Calc::getInstance()->add(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };

} // command

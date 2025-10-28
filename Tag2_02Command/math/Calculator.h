//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include <memory>
#include <iostream>

namespace math {

    class Calculator {
        double memory{0};
        Calculator() {}
    public:
        // Delete Copy, move, zuweisung

        [[nodiscard]] static auto getInstance()->std::shared_ptr<Calculator>  {
            static std::shared_ptr<Calculator> instance{new Calculator{}};

            return instance;
        }

        double getMemory() const {
            return memory;
        }

        void setMemory(double memory) {
            Calculator::memory = memory;
        }

        auto print() const->void{
            std::cout << memory << std::endl;
        }
        auto clear()-> void {
            memory = 0;
        }

        auto add(double value)-> void {
            memory += value;
        }
        auto sub(double value)-> void {
            memory -= value;
        }
        auto mult(double value)-> void {
            memory *= value;
        }
        auto div(double value)-> void {
            memory /= value;
        }

    };

} // math

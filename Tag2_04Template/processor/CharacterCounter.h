//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include "AbstractFileprocessor.h"

namespace processor {

    class CharacterCounter: public AbstractFileprocessor{

        int counter;
    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            counter ++;
        }

        void close() override {
           std::cout << counter << std::endl;
        }

    };

} // processor

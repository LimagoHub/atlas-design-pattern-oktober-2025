//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include "Command.h"

namespace command {
    using CommandPointer = std::shared_ptr<Command>;


    class CommandHistory {
    public:
        virtual ~CommandHistory()=default;
        CommandHistory()=default;

        auto add(const CommandPointer &c )->void {
            if(c->isQuery()) return;
            // Euer Problem
        }

        auto undo()->void {
            std::cout << "Can't undo" << std::endl;
        }

        auto redo()->void {
            std::cout << "Can't redo" << std::endl;
        }
    };

} // command

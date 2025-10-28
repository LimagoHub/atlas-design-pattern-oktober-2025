//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <memory>
#include "Command.h"
#include "AddCommand.h"
#include "PrintCommand.h"
#include "ClearCommand.h"
#include <regex>

namespace command {


    class CommandFactory {
    public:
        using COMMAND = std::shared_ptr<Command>;
        using StringVector = std::vector<std::string>;
        static COMMAND create(std::string line) {
            COMMAND result;
            const StringVector tokens =tokenizeLine(line);
            if(tokens[0] == "Add"){
                result = std::make_shared<AddCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Print"){
                result = std::make_shared<PrintCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Clear"){
                result = std::make_shared<ClearCommand>();
                result->parse(tokens);
            }
            return result;
        }

    private:
        static StringVector tokenizeLine(const std::string &line) {
            auto const regex = std::regex{R"(\s+)"};
            auto const result = StringVector(
                    std::sregex_token_iterator{std::begin(line), std::end(line), regex, -1},
                    std::sregex_token_iterator{}
            );
            return result;
        }
    };


} // command

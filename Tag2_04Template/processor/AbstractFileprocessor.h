//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace processor {

    class AbstractFileprocessor {

    public:
        void run(std::string filename) {  // Kernalgorithmus  nicht ueberschreiben

            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }
            init();
            int ch;
            while( EOF != (ch = fin.get())) {

               process(static_cast<char>( ch));
            }

            close();

            fin.close();
        }

        virtual void init() {
            // ok
        }

        virtual void process(char c) = 0;

        virtual void close() {
            // ok
        }

    };

} // processor

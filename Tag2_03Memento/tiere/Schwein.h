//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include <string>
#include <ostream>
#include <memory>
#include "SchweineMemento.h"

namespace tiere {

    class Schwein {
        std::string name;
        int gewicht;
        void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
        }

        class MySchweineMemento: public SchweineMemento {
            const std::string name;
            const int gewicht;
        public:
            MySchweineMemento(const std::string &name, const unsigned int gewicht) : name(name), gewicht(gewicht) {}
            const std::string &getName() const {
                return name;
            }

            const unsigned int getGewicht() const {
                return gewicht;
            }
        };

    public:
        explicit Schwein(const std::string &name) : name(name), gewicht(10) {}

        std::shared_ptr<SchweineMemento>  getMemento() const {
            return std::make_shared<MySchweineMemento>(name, gewicht);
        }

        void setMemento(std::shared_ptr<SchweineMemento> memento) {
            auto myMemento = std::dynamic_pointer_cast<MySchweineMemento>(memento);
            setName(myMemento->getName());
            setGewicht(myMemento->getGewicht());
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            Schwein::name = name;
        }

        int getGewicht() const {
            return gewicht;
        }

        void fuettern() {
            setGewicht(getGewicht() + 1);
        }

        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }

    };

} // tiere

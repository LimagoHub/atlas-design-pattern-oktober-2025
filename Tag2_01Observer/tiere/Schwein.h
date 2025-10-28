//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <functional>
#include "Tier.h"
#include "../propertychanged/PropertyChangedSupport.h"

namespace tiere {

    using PropertyChangeSupport = propertychanged::PropertyChangedSupport;

    class Schwein: public Tier {
        inline static const unsigned MAX_WEIGHT{20};
        std::vector<std::function<void(Schwein *)>> listeners;
        propertychanged::PropertyChangedSupport propertyChangeSupport;

        std::string name;
        int gewicht;

        void firePigTooFatEvent() {
            for (const auto &listener: listeners) {
                listener(this);
            }
        }

        inline void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
            if (gewicht > MAX_WEIGHT) firePigTooFatEvent();
            propertyChangeSupport.firePropertyChanged("gewicht");
        }

    public:
        Schwein(const std::string &name, int gewicht) : name(name), gewicht(gewicht), propertyChangeSupport(reinterpret_cast<std::any *>(this)) {}

        void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
            listeners.emplace_back(listener);
        }

        void addPropertyChangeListener(std::function<void(std::any, std::string)> listener) {
            propertyChangeSupport.addPropertyChangedListener(listener);
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            Schwein::name = name;
            propertyChangeSupport.firePropertyChanged("name");
        }

        int getGewicht() const {
            return gewicht;
        }

        void fuettern() {
            setGewicht(getGewicht() + 1);
        }

        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os << "Schwein: "  << " name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }




    };

} // tiere

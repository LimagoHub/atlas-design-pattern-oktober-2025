//
// Created by JoachimWagner on 28.10.2025.
//

#pragma once
#include <any>
#include <string>
#include <vector>
#include <functional>
namespace propertychanged {

    class PropertyChangedSupport {
        std::vector<std::function<void(std::any, std::string)>> listeners;
        std::any *source;
    public:
        explicit PropertyChangedSupport(std::any *source) : source(source) {}

        void addPropertyChangedListener(const std::function<void(std::any, std::string)> &listener) {
            listeners.emplace_back(listener);
        }

        void firePropertyChanged(std::string propertyname) {
            for (const auto &listener: listeners) {
                listener(source, propertyname);
            }
        }

    };

} // propertychanged

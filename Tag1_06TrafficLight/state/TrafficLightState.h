//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <string>

namespace trafficlight::state {

    class TrafficLightState {
    public:
        virtual ~TrafficLightState() = default;

        virtual std::string getColor() = 0;    // Business
        virtual void nextColor() = 0; // Statuswechsel
    };

} // state

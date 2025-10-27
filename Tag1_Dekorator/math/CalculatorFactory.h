//
// Created by JoachimWagner on 27.10.2025.
//

#pragma once

#include <memory>
#include "Calculator.h"
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorSecure.h"
using CalculatorPointer = std::unique_ptr<Calculator>;
class CalculatorFactory {

    inline static bool logger{false};
    inline static bool secure{false};

public:
    static CalculatorPointer create() {
        std::unique_ptr<Calculator> calc;
        calc = std::make_unique<CalculatorImpl>();
        if(logger) calc = std::make_unique<CalculatorLogger>(std::move(calc));
        if (secure) calc = std::make_unique<CalculatorSecure>(std::move(calc));
        return calc;
    }

    static bool isLogger() {
        return logger;
    }

    static void setLogger(bool logger) {
        CalculatorFactory::logger = logger;
    }

    static bool isSecure() {
        return secure;
    }

    static void setSecure(bool secure) {
        CalculatorFactory::secure = secure;
    }
};

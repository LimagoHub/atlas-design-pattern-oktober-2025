
#include <iostream>
#include <chrono>
#include "client/CalcClient.h"
#include "math/CalculatorFactory.h"
#include "math/CalculatorLogger.h"
#include "math/CalculatorSecure.h"
int main() {

    CalculatorFactory::setLogger(true);
    CalculatorFactory::setSecure(true);
    std::unique_ptr<Calculator> calc = CalculatorFactory::create();


    CalcClient client{std::move(calc)};

    client.go();

    auto start_ = std::chrono::high_resolution_clock::now();
    auto end_ = std::chrono::high_resolution_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;
    return 0;
}

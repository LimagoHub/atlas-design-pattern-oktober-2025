#include <iostream>
#include <memory>
#include "processor/AbstractFileprocessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"

using Processor = std::shared_ptr<processor::AbstractFileprocessor>;


int main() {
    Processor fileprocessor = std::make_shared<processor::LineCounter>();

    fileprocessor->run("..\\data\\blind.txt");

    return 0;
}

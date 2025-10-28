#include <iostream>
#include "tiere/Schwein.h"
int main() {
    tiere::Schwein piggy {"Miss Piggy"};

    std::cout << piggy << std::endl;


    // Zustand merken

    auto memento = piggy.getMemento();


    piggy.fuettern();

    std::cout << piggy << std::endl;

    // Zustand wiederherstellen
    piggy.setMemento(memento);

    std::cout << piggy << std::endl;

    return 0;
}

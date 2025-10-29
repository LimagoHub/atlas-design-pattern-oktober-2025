#include <iostream>
#include "Person.h"

int main() {
    auto person = Person::builder()
            .withAnrede("Frau")
            .withVorname("Erika")
            .build();
    return 0;
}

#include <iostream>
#include "tiere/Tier.h"
#include "tiere/Schwein.h"

class Metzger {
public:
    void schlachten(tiere::Tier *tier) {
        std::cout << "Messer wetz" << std::endl;
    }
};
template<class T>
class Spediteur {
public:
    void fahren(T *Ware) {
        std::cout << "Wir fahren auf der Autobahn" << std::endl;
    }
};

class Observer {
public: void listen(tiere::Schwein s, std::string propName){
    std::cout << s << " -> " << propName << " wurde geändert" << std::endl;
}
};

int main() {
    Metzger metzger;
    Spediteur<tiere::Schwein> spediteur;
    Observer observer;
    tiere::Schwein piggy{"Miss piggy",10};

    piggy.addPropertyChangeListener([&observer](std::any sender,std::string propname){observer.listen(*(std::any_cast<tiere::Schwein *>(sender)), propname);});

    piggy.addPigTooFatListener([&metzger](tiere::Schwein *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener([&spediteur](tiere::Schwein *s){spediteur.fahren(s);});
    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;
}

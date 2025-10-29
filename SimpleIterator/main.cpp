#include <iostream>

template<class T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

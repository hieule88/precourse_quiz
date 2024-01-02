#include <iostream>

class Example {
public:
    int *buf;

    Example() { buf = new int[1024]; }
    ~Example() { delete[] buf; }

    // Deep copy constructor
    Example(const Example &other) {
        buf = new int[1024];
        for (int i = 0; i < 1024; ++i) {
            buf[i] = other.buf[i];
        }
    }
};

int main() {
    Example ex1;
    Example ex2 = ex1;

    // Additional code for demonstration
    std::cout << "ex1.buf[0] before modification: " << ex1.buf[0] << std::endl;
    std::cout << "ex2.buf[0] before modification: " << ex2.buf[0] << std::endl;

    // Modify ex1.buf to demonstrate the independence of buffers
    ex1.buf[0] = 42;

    std::cout << "ex1.buf[0] after modification: " << ex1.buf[0] << std::endl;
    std::cout << "ex2.buf[0] after modification: " << ex2.buf[0] << std::endl;

    return 0;
}

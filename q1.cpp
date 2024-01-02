#include <iostream>

// Pure abstract class
class Vehicle {
public:
    // Only pure virtual functions are implemented
    virtual void start() const = 0;
    virtual void stop() const = 0;
};

// Motorbike
class Motorbike : public Vehicle {
public:
    void start() const override {
        std::cout << "Motorbike is starting." << std::endl;
    }

    void stop() const override {
        std::cout << "Motorbike is stopping." << std::endl;
    }
};

int main() {
    Motorbike myMotorbike;

    // Using polymorphism to call functions on a Motorbike instance
    Vehicle* vehiclePtr = &myMotorbike;

    vehiclePtr->start();
    vehiclePtr->stop();

    return 0;
}
﻿#include <iostream>

class Vehicle {
protected:
    SpeedControl* speedControl;

public:
    Vehicle(SpeedControl* control) : speedControl(control) {}

    virtual void drive() = 0;
    virtual void refuel() = 0;
    virtual void measureSpeed() {
        speedControl->measureSpeed();
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(SpeedControl* control) : Vehicle(control) {}

    void drive() override {
        // Реалізація для автомобіля
    }

    void refuel() override {
        // Реалізація заправки автомобіля
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(SpeedControl* control) : Vehicle(control) {}

    void drive() override {
        // Реалізація для мотоцикла
    }

    void refuel() override {
        // Реалізація заправки мотоцикла
    }
};

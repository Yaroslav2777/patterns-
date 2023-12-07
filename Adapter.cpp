#include <iostream>

// Це наш інтерфейс, який потрібно адаптувати
class TargetInterface {
public:
    virtual void request() const = 0;
};

// Це клас, що ми хочемо адаптувати
class Adaptee {
public:
    void specificRequest() const {
        cout << "Adaptee's specific request." << endl;
    }
};

// Адаптер, який забезпечує сумісність між TargetInterface і Adaptee
class Adapter : public TargetInterface {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() const override {
        // Виклик методу Adaptee з методу TargetInterface
        adaptee->specificRequest();
    }
};

int main() {
    // Створення об'єкта Adaptee
    Adaptee* adaptee = new Adaptee();

    // Створення об'єкта Adapter з використанням Adaptee
    TargetInterface* adapter = new Adapter(adaptee);

    // Виклик методу через Adapter
    adapter->request();

    delete adaptee;
    delete adapter;

    return 0;
}

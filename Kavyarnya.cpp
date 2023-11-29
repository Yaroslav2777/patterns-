#include <iostream>
#include <string>

// Базовий клас напою
class Drink {
public:
    virtual void prepare() = 0;
    virtual ~Drink() = default;
};

// Конкретні класи напоїв
class Coffee : public Drink {
public:
    void prepare() override {
        cout << "Preparing coffee..." << endl;
        // Логіка приготування кави
    }
};

class Tea : public Drink {
public:
    void prepare() override {
        cout << "Preparing tea..." << endl;
        // Логіка приготування чаю
    }
};

// Фабрика напоїв
class DrinkFactory {
public:
    // Метод створення напою за типом
    static Drink* createDrink(const string& type) {
        if (type == "Coffee") {
            return new Coffee();
        }
        else if (type == "Tea") {
            return new Tea();
        }
        return nullptr;
    }
};

// Приклад використання фабрики
int main() {
    Drink* coffee = DrinkFactory::createDrink("Coffee");
    if (coffee) {
        coffee->prepare();
        delete coffee;
    }

    Drink* tea = DrinkFactory::createDrink("Tea");
    if (tea) {
        tea->prepare();
        delete tea;
    }

    return 0;
}

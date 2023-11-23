#include <iostream>

// Абстрактний клас "Фабрика продуктів"
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual void createProductGeneration() = 0;
    virtual void createProductPasswords() = 0;
};

// Конкретна фабрика "Фабрика продуктів 1"
class ConcreteFactory1 : public AbstractFactory {
public:
    void createProductGeneration() {
        cout << "Product Generation from Factory 1" << endl;
    }

    void createProductB() {
        cout << "Product Passwords from Factory 1" << endl;
    }
};

// Конкретна фабрика "Фабрика продуктів 2"
class ConcreteFactory2 : public AbstractFactory {
public:
    void createProductGeneration() {
        cout << "Product Generation from Factory 2" << endl;
    }

    void createProductB() {
        cout << "Product Passwords from Factory 2" << endl;
    }
};

// Класи продуктів
class ProductA {
public:
    void use() {
        cout << "Using Product Generation" << endl;
    }
};

class ProductB {
public:
    void consume() {
        cout << "Consuming Product Passwords" << endl;
    }
};

int main() {
    // Використання абстрактної фабрики
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractFactory* factory2 = new ConcreteFactory2();

    // Створення продуктів відповідно до вибраної фабрики
    factory1->createProductGeneration();
    factory1->createProductPasswords();

    factory2->createProductGeneration();
    factory2->createProductPasswords();

    // Видалення фабрик
    delete factory1;
    delete factory2;

    return 0;
}

#include <iostream>

// Абстрактний клас для створення об'єктів
class Product {
public:
    virtual void doSomething() = 0;
};

// Конкретний клас, який наслідується від абстрактного класу Product
class ConcreteProductAppl : public Product {
public:
    void doSomething() override {
        cout << "Виконую дію ConcreteProducAppl" << endl;
    }
};

// Інший конкретний клас
class ConcreteProductBot : public Product {
public:
    void doSomething() override {
        cout << "Виконую дію ConcreteProductBot" << endl;
    }
};

// Фабричний клас для створення об'єктів
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// Конкретний фабричний клас для створення об'єктів ConcreteProductA
class ConcreteFactoryAppl : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductAppl();
    }
};

// Інший конкретний фабричний клас для створення об'єктів ConcreteProductB
class ConcreteFactoryBot : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductBot();
    }
};

int main() {
    // Використання фабрики для створення об'єкта
    Factory* factory = new ConcreteFactoryAppl();
    Product* product = factory->createProduct();
    product->doSomething();

    // Зміна фабрики для створення іншого об'єкта
    delete product;
    delete factory;

    factory = new ConcreteFactoryBot();
    product = factory->createProduct();
    product->doSomething();

    delete product;
    delete factory;

    return 0;
}

#include <iostream>

// Абстракція
class Abstraction {
protected:
    class Implementation* implementation;
public:
    virtual void operation() = 0;
    virtual ~Abstraction() {}
};

// Реалізація
class Implementation {
public:
    virtual void performOperation() = 0;
    virtual ~Implementation() {}
};

// Конкретна абстракція 1
class ConcreteAbstraction1 : public Abstraction {
public:
    ConcreteAbstraction1(Implementation* impl) {
        implementation = impl;
    }

    void operation() override {
        cout << "ConcreteAbstraction1: ";
        implementation->performOperation();
    }
};

// Конкретна абстракція 2
class ConcreteAbstraction2 : public Abstraction {
public:
    ConcreteAbstraction2(Implementation* impl) {
        implementation = impl;
    }

    void operation() override {
        cout << "ConcreteAbstraction2: ";
        implementation->performOperation();
    }
};

// Конкретна реалізація 1
class ConcreteImplementation1 : public Implementation {
public:
    void performOperation() override {
        scout << "Operation 1\n";
    }
};

// Конкретна реалізація 2
class ConcreteImplementation2 : public Implementation {
public:
    void performOperation() override {
        cout << "Operation 2\n";
    }
};

int main() {
    // Створюємо об'єкти абстракції та реалізації
    Implementation* implementation1 = new ConcreteImplementation1();
    Implementation* implementation2 = new ConcreteImplementation2();

    Abstraction* abstraction1 = new ConcreteAbstraction1(implementation1);
    Abstraction* abstraction2 = new ConcreteAbstraction2(implementation2);

    // Викликаємо операції через абстракцію
    abstraction1->operation();
    abstraction2->operation();

    // Звільняємо пам'ять
    delete implementation1;
    delete implementation2;
    delete abstraction1;
    delete abstraction2;

    return 0;
}


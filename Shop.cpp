#include <iostream>
#include <memory>
#include <string>

// Базовий клас товару
class Product {
public:
    virtual void info() const = 0;
    virtual ~Product() = default;
};

// Класи конкретних товарів
class Toy : public Product {
public:
    void info() const override {
        cout << "Це іграшка" << endl;
    }
};

class Book : public Product {
public:
    void info() const override {
        cout << "Це книга" << endl;
    }
};

// Фабрика для створення товарів
class ProductFactory {
public:
    enum ProductType {
        TOY,
        BOOK
    };

    unique_ptr<Product> createProduct(ProductType type) {
        switch (type) {
        case TOY:
            return make_unique<Toy>();
        case BOOK:
            return make_unique<Book>();
        default:
            return nullptr;
        }
    }
};

int main() {
    ProductFactory factory;

    // Створення товару за допомогою фабрики
    unique_ptr<Product> toy = factory.createProduct(ProductFactory::TOY);
    unique_ptr<Product> book = factory.createProduct(ProductFactory::BOOK);

    // Вивід інформації про товари
    toy->info();
    book->info();

    return 0;
}



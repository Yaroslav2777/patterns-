#include <iostream>
#include <string>

// Клас, об'єкт якого будується
class Product {
public:
    void setPartPassword(const string& partPassword) {
        partPassword_ = partPassword;
    }

    void setPartBoom(const string& partBoom) {
        partBoom_ = partBoom;
    }

    void setPartCat(const string& partCat) {
        partCat_ = partCat;
    }

    void showProduct() const {
        cout << "Parts of the product: " << partPassword_ << ", " << partBoom_ << ", " << partCat_ << endl;
    }

private:
    string partPassword_;
    string partBoom_;
    string partCat_;
};

// Базовий клас Builder, який визначає інтерфейс для створення об'єктів
class Builder {
public:
    virtual ~Builder() {}
    virtual void buildPartPassword() = 0;
    virtual void buildPartBoom() = 0;
    virtual void buildPartCat() = 0;
    virtual Product* getProduct() = 0;
};

// Конкретний клас Builder для створення конкретного об'єкту Product
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        product_ = new Product();
    }

    ~ConcreteBuilder() {
        delete product_;
    }

    void buildPartPassword() override {
        product_->setPartPassword("Part Password");
    }

    void buildPartBoom() override {
        product_->setPartBoom("Part Boom");
    }

    void buildPartCat() override {
        product_->setPartCat("Part Cat");
    }

    Product* getProduct() override {
        return product_;
    }

private:
    Product* product_;
};

// Клас Director, який відповідає за використання Builder для побудови об'єктів
class Director {
public:
    Director(Builder* builder) : builder_(builder) {}

    void construct() {
        builder_->buildPartPassword();
        builder_->buildPartBoom();
        builder_->buildPartCat();
    }

private:
    Builder* builder_;
};

int main() {
    ConcreteBuilder* concreteBuilder = new ConcreteBuilder();
    Director director(concreteBuilder);

    director.construct();

    Product* product = concreteBuilder->getProduct();
    product->showProduct();

    delete product;
    delete concreteBuilder;

    return 0;
}

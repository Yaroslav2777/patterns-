#include <iostream>
#include <unordered_map>

// Абстрактний клас прототипу
class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void setInfo(const string& info) = 0;
    virtual void printInfo() = 0;
};

// Конкретний клас прототипу
class ConcretePrototype : public Prototype {
private:
    string info;

public:
    Prototype* clone() override {
        ConcretePrototype* cloned = new ConcretePrototype();
        cloned->setInfo(this->info);
        return cloned;
    }

    void setInfo(const string& info) override {
        this->info = info;
    }

    void printInfo() override {
        cout << "Info: " << info << endl;
    }
};

// Прототипний менеджер, який дозволяє робити клони
class PrototypeManager {
private:
    unordered_map<string, Prototype*> prototypes;

public:
    void registerPrototype(const string& key, Prototype* prototype) {
        prototypes[key] = prototype;
    }

    Prototype* create(const string& key) {
        if (prototypes.find(key) != prototypes.end()) {
            return prototypes[key]->clone();
        }
        return nullptr;
    }
};

int main() {
    ConcretePrototype* original = new ConcretePrototype();
    original->setInfo("Original object");

    PrototypeManager manager;
    manager.registerPrototype("key", original);

    // Створення клону
    Prototype* cloned = manager.create("key");
    if (cloned) {
        cloned->printInfo();
    }

    delete original;
    delete cloned;

    return 0;
}

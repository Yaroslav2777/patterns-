#include <iostream>

class Singleton {
public:
    // Метод доступу до єдиного екземпляру класу
    static Singleton& getInstance() {
        static Singleton instance; // Єдиний екземпляр класу
        return instance;
    }

    // Деякі методи чи дані класу
    void showMessage() {
        cout << "Hi Singleton!" << endl;
    }

    // Позбавляємося можливості копіювання та присвоєння
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Забороняємо створення зовнішніми методами
    Singleton() {}
};

// Приклад використання Singleton
int main() {
    // Отримання єдиного екземпляру
    Singleton& singleton = Singleton::getInstance();

    // Використання методу
    singleton.showMessage();

    return 0;
}

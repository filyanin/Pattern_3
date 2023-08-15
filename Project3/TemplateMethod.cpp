// Кофемашина может уметь делать разные виды кофе: американо, латте, классический кофе с молоком и т.д.
// Скорее всего, существует общий шаблон действий, необходимых для варки кофе, который меняется в зависимости от того, 
// какой напиток выбрал клиент.

// 

#include <iostream>

// Абстрактный класс, определяющий шаблонный метод алгоритма
class CoffeeTemplate {
public:
    // Шаблонный метод, определяющий процесс приготовления кофе
    void makeCoffee() {
        boilWater();
        brewCoffeeGrinds();
        pourInCup();
        addCondiments();
    }

    // Абстрактные методы, которые подклассы должны реализовать
    virtual void brewCoffeeGrinds() = 0;
    virtual void addCondiments() = 0;

    // Общие шаги, которые можно переиспользовать
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
};

// Конкретная реализация класса для приготовления кофе
class CoffeeMilkSugar : public CoffeeTemplate {
public:
    void brewCoffeeGrinds() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};

// Конкретная реализация класса для приготовления кофе
class CoffeeAmericano : public CoffeeTemplate {
public:
    void brewCoffeeGrinds() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }
};

//int main() {
//    CoffeeMilkSugar coffee;
//    coffee.makeCoffee();
//
//    return 0;
//}

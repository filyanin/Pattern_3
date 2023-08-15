// ���������� ����� ����� ������ ������ ���� ����: ���������, �����, ������������ ���� � ������� � �.�.
// ������ �����, ���������� ����� ������ ��������, ����������� ��� ����� ����, ������� �������� � ����������� �� ����, 
// ����� ������� ������ ������.

// 

#include <iostream>

// ����������� �����, ������������ ��������� ����� ���������
class CoffeeTemplate {
public:
    // ��������� �����, ������������ ������� ������������� ����
    void makeCoffee() {
        boilWater();
        brewCoffeeGrinds();
        pourInCup();
        addCondiments();
    }

    // ����������� ������, ������� ��������� ������ �����������
    virtual void brewCoffeeGrinds() = 0;
    virtual void addCondiments() = 0;

    // ����� ����, ������� ����� ����������������
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
};

// ���������� ���������� ������ ��� ������������� ����
class CoffeeMilkSugar : public CoffeeTemplate {
public:
    void brewCoffeeGrinds() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};

// ���������� ���������� ������ ��� ������������� ����
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

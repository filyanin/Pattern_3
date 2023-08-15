// У выключателя света есть два состояния: включен и выключен. Разнесем их на два класса - наследника интерфейса состояний.
// И сделаем два метода - метод включения и выключения, работающие по разному, в зависимости от состояния

#include <iostream>

// Определение интерфейса состояний
class State {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Конкретное состояние: Включено
class OnState : public State {
public:
    void turnOn() override {
        std::cout << "Already ON" << std::endl;
    }

    void turnOff() override;
};

// Конкретное состояние: Выключено
class OffState : public State {
public:
    void turnOn() override;

    void turnOff() override {
        std::cout << "Already OFF" << std::endl;
    }
};

// Класс контекста (лампочки), который использует состояния
class Light {
private:
    State* currentState;

public:
    Light() {
        currentState = new OffState();
    }

    void setState(State* state) {
        delete currentState;
        currentState = state;
    }

    void turnOn() {
        currentState->turnOn();
        this->setState(new OnState());  // Переход к состоянию "Включено"
    }

    void turnOff() {
        currentState->turnOff();
        this->setState(new OffState());  // Переход к состоянию "Выключено"
    }
};

void OnState::turnOff() {
    std::cout << "Turning OFF" << std::endl;
}

void OffState::turnOn() {
    std::cout << "Turning ON" << std::endl;
}
//
//int main() {
//    Light light;
//
//    light.turnOn();  // Включение
//    light.turnOff(); // Выключение
//
//    light.turnOff(); // Уже выключено
//    light.turnOn();  // Включение
//
//    return 0;
//}

// В умном доме все "умные" элементы являются участниками одной системы и взаимодействуют под контролем одного
// "умного" центра. Таким образом все изменения транслируются от элемента к умному дому, а он сам уже ретранслирует то, 
// что необходимо другим участникам.
// Например, если бы мы добавили умный замок, можно было бы описать событие запирания замка при срабатывании датчика движения.



#include <iostream>
#include <string>
#include <vector>

class Component;  
// Абстрактный класс посредника
class Mediator {
public:
    virtual void notify(Component* sender, const std::string& event) = 0;
};

// Абстрактный класс компонента
class Component {
protected:
    Mediator* mediator;

public:
    Component(Mediator* med) : mediator(med) {}

    virtual void sendEvent(const std::string& event) {
        mediator->notify(this, event);
    }

    virtual void receiveEvent(const std::string& event) = 0;
};

// Конкретный компонент: Датчик движения
class MotionSensor : public Component {
public:
    MotionSensor(Mediator* med) : Component(med) {}

    void receiveEvent(const std::string& event) override {
        std::cout << "Motion Sensor received event: " << event << std::endl;
    }
};

// Конкретный компонент: Система безопасности
class SecuritySystem : public Component {
public:
    SecuritySystem(Mediator* med) : Component(med) {}

    void receiveEvent(const std::string& event) override {
        std::cout << "Security System received event: " << event << std::endl;
    }
};

// Конкретный посредник: Умный дом
class SmartHome : public Mediator {
private:
    std::vector<Component*> components;

public:
    void addComponent(Component* component) {
        components.push_back(component);
    }

    void notify(Component* sender, const std::string& event) override {
        for (Component* comp : components) {
            if (comp != sender) {
                comp->receiveEvent(event);
            }
        }
    }
};

//int main() {
//    SmartHome smartHome;
//
//    MotionSensor motionSensor(&smartHome);
//    SecuritySystem securitySystem(&smartHome);
//
//    smartHome.addComponent(&motionSensor);
//    smartHome.addComponent(&securitySystem);
//
//    motionSensor.sendEvent("Motion detected!");
//    securitySystem.sendEvent("Intruder alert!");
//
//    return 0;
//}

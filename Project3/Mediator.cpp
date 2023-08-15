// � ����� ���� ��� "�����" �������� �������� ����������� ����� ������� � ��������������� ��� ��������� ������
// "������" ������. ����� ������� ��� ��������� ������������� �� �������� � ������ ����, � �� ��� ��� ������������� ��, 
// ��� ���������� ������ ����������.
// ��������, ���� �� �� �������� ����� �����, ����� ���� �� ������� ������� ��������� ����� ��� ������������ ������� ��������.



#include <iostream>
#include <string>
#include <vector>

class Component;  
// ����������� ����� ����������
class Mediator {
public:
    virtual void notify(Component* sender, const std::string& event) = 0;
};

// ����������� ����� ����������
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

// ���������� ���������: ������ ��������
class MotionSensor : public Component {
public:
    MotionSensor(Mediator* med) : Component(med) {}

    void receiveEvent(const std::string& event) override {
        std::cout << "Motion Sensor received event: " << event << std::endl;
    }
};

// ���������� ���������: ������� ������������
class SecuritySystem : public Component {
public:
    SecuritySystem(Mediator* med) : Component(med) {}

    void receiveEvent(const std::string& event) override {
        std::cout << "Security System received event: " << event << std::endl;
    }
};

// ���������� ���������: ����� ���
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

// � ����������� ����� ���� ��� ���������: ������� � ��������. �������� �� �� ��� ������ - ���������� ���������� ���������.
// � ������� ��� ������ - ����� ��������� � ����������, ���������� �� �������, � ����������� �� ���������

#include <iostream>

// ����������� ���������� ���������
class State {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// ���������� ���������: ��������
class OnState : public State {
public:
    void turnOn() override {
        std::cout << "Already ON" << std::endl;
    }

    void turnOff() override;
};

// ���������� ���������: ���������
class OffState : public State {
public:
    void turnOn() override;

    void turnOff() override {
        std::cout << "Already OFF" << std::endl;
    }
};

// ����� ��������� (��������), ������� ���������� ���������
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
        this->setState(new OnState());  // ������� � ��������� "��������"
    }

    void turnOff() {
        currentState->turnOff();
        this->setState(new OffState());  // ������� � ��������� "���������"
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
//    light.turnOn();  // ���������
//    light.turnOff(); // ����������
//
//    light.turnOff(); // ��� ���������
//    light.turnOn();  // ���������
//
//    return 0;
//}

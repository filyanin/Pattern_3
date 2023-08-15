// ����� ��������������� ����������� ������������ ���� ������ �� ���������� ���������� ������� � ����� ����������� �������
// ����� ����, ��� ������ ����� �� ������ ��� �������� ���� ������, �� � ��� ����������� ������������� - ����������� ������� �����������
// ������� �������� ����� - ������ ����������� � ��������� ������� �����������, ������������ ���������� �� ������ ����������.

#include <iostream>
#include <vector>

// ��������� ����������� ��� ������������ ��������� �����������
class TemperatureObserver {
public:
    virtual void onTemperatureChanged(float newTemperature) = 0;
};

// ����� ������� �����������, ������� ����� ��������� ������������
class TemperatureSensor {
private:
    float temperature;
    std::vector<TemperatureObserver*> observers;

public:
    // ���������� �����������
    void addObserver(TemperatureObserver* observer) {
        observers.push_back(observer);
    }

    // �������� �����������
    void removeObserver(TemperatureObserver* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    // ��������� ����� ����������� � ���������� ������������
    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notifyObservers();
    }

    // ���������� ���� ������������ � ��������� �����������
    void notifyObservers() {
        for (TemperatureObserver* observer : observers) {
            observer->onTemperatureChanged(temperature);
        }
    }
};

// ���������� ����������� ��� ����������� �����������
class TemperatureDisplay : public TemperatureObserver {
public:
    void onTemperatureChanged(float newTemperature) override {
        std::cout << "Temperature changed: " << newTemperature << " C" << std::endl;
    }
};

// ���������� ����������� ��� ����������� �����������
class TemperatureLog : public TemperatureObserver {
public:
    void onTemperatureChanged(float newTemperature) override {
        std::cout << "Logging temperature: " << newTemperature << " C" << std::endl;
    }
};

//int main() {
//    TemperatureSensor sensor;
//
//    TemperatureDisplay display;
//    TemperatureLog log;
//
//    // ��������� ������������ � �������
//    sensor.addObserver(&display);
//    sensor.addObserver(&log);
//
//    // ������������� ����� �����������, ����������� �����������
//    sensor.setTemperature(25.0f);
//
//    // ������� ������ �� ������������
//    sensor.removeObserver(&display);
//
//    // �������� �����������, ���������� ����������� �� ��� �������� ����������
//    sensor.setTemperature(28.5f);
//
//    return 0;
//}

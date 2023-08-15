// Чтобы спрогнозировать температуру производится сбор данных на длительном промежутке времени с целью дальнейшего анализа
// Кроме того, эти данные нужны не только для закрытой базы данных, но и для мгновенного использования - просмотреть текущую температуру
// поэтому создадим класс - датчик температуры и несколько классов подписчиков, использующих информацию по своему усмотрению.

#include <iostream>
#include <vector>

// Интерфейс наблюдателя для отслеживания изменений температуры
class TemperatureObserver {
public:
    virtual void onTemperatureChanged(float newTemperature) = 0;
};

// Класс сенсора температуры, который будет оповещать наблюдателей
class TemperatureSensor {
private:
    float temperature;
    std::vector<TemperatureObserver*> observers;

public:
    // Добавление наблюдателя
    void addObserver(TemperatureObserver* observer) {
        observers.push_back(observer);
    }

    // Удаление наблюдателя
    void removeObserver(TemperatureObserver* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    // Установка новой температуры и оповещение наблюдателей
    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notifyObservers();
    }

    // Оповещение всех наблюдателей о изменении температуры
    void notifyObservers() {
        for (TemperatureObserver* observer : observers) {
            observer->onTemperatureChanged(temperature);
        }
    }
};

// Конкретный наблюдатель для отображения температуры
class TemperatureDisplay : public TemperatureObserver {
public:
    void onTemperatureChanged(float newTemperature) override {
        std::cout << "Temperature changed: " << newTemperature << " C" << std::endl;
    }
};

// Конкретный наблюдатель для логирования температуры
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
//    // Добавляем наблюдателей к сенсору
//    sensor.addObserver(&display);
//    sensor.addObserver(&log);
//
//    // Устанавливаем новую температуру, наблюдатели оповещаются
//    sensor.setTemperature(25.0f);
//
//    // Удаляем одного из наблюдателей
//    sensor.removeObserver(&display);
//
//    // Изменяем температуру, оставшийся наблюдатель всё еще получает оповещение
//    sensor.setTemperature(28.5f);
//
//    return 0;
//}

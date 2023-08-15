 // Рассмотрим пример отправки сообщений от программы пользователю
 // Сообщения могут быть текстовыми или голосовыми

#include <iostream> 
#include <string> 
#include <vector> 

// Интерфейс команды 
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Конкретная команда для отправки сообщения 
class SendMessageCommand : public Command {
private:
    std::string message;

public:
    SendMessageCommand(const std::string& msg) : message(msg) {}

    void execute() override {
        std::cout << "Отправлено сообщение: " << message << std::endl;
    }

    void undo() override {
        std::cout << "Отмена отправки сообщения: " << message << std::endl;
    }
};

// Конкретная команда для отправки аудиосообщения
class SendAudioCommand : public Command {
private:    std::string audioClip;
public:
    SendAudioCommand(const std::string& clip) : audioClip(clip) {}
    void execute() override {
        std::cout << "Отправлено аудиосообщение: " << audioClip << std::endl;
    }
    void undo() override {
        std::cout << "Отмена отправки аудиосообщения: " << audioClip << std::endl;
    }};

// Инвокер, который выполняет команды 
class CommandInvoker {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* cmd) {
        commands.push_back(cmd);
    }

    void executeCommands() {
        for (Command* cmd : commands) {
            cmd->execute();
        }
        commands.clear();
    }
};

//int main() {
//
//    setlocale(LC_ALL, "Russian");
//    CommandInvoker invoker;
//    // Создаем команды для отправки сообщений и аудиосообщений    
//    Command* sendCommand1 = new SendMessageCommand("Привет!");
//    Command* sendCommand2 = new SendAudioCommand("Аудиофайл.mp3");
//    invoker.addCommand(sendCommand1);    
//    invoker.addCommand(sendCommand2);
//    // Выполняем команды
//    invoker.executeCommands();
//    // Отменяем отправку последней команды
//    sendCommand2->undo();
//    delete sendCommand1;    delete sendCommand2;
//    return 0;
//}
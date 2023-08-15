 // ���������� ������ �������� ��������� �� ��������� ������������
 // ��������� ����� ���� ���������� ��� ����������

#include <iostream> 
#include <string> 
#include <vector> 

// ��������� ������� 
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// ���������� ������� ��� �������� ��������� 
class SendMessageCommand : public Command {
private:
    std::string message;

public:
    SendMessageCommand(const std::string& msg) : message(msg) {}

    void execute() override {
        std::cout << "���������� ���������: " << message << std::endl;
    }

    void undo() override {
        std::cout << "������ �������� ���������: " << message << std::endl;
    }
};

// ���������� ������� ��� �������� ��������������
class SendAudioCommand : public Command {
private:    std::string audioClip;
public:
    SendAudioCommand(const std::string& clip) : audioClip(clip) {}
    void execute() override {
        std::cout << "���������� ��������������: " << audioClip << std::endl;
    }
    void undo() override {
        std::cout << "������ �������� ��������������: " << audioClip << std::endl;
    }};

// �������, ������� ��������� ������� 
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
//    // ������� ������� ��� �������� ��������� � ��������������    
//    Command* sendCommand1 = new SendMessageCommand("������!");
//    Command* sendCommand2 = new SendAudioCommand("���������.mp3");
//    invoker.addCommand(sendCommand1);    
//    invoker.addCommand(sendCommand2);
//    // ��������� �������
//    invoker.executeCommands();
//    // �������� �������� ��������� �������
//    sendCommand2->undo();
//    delete sendCommand1;    delete sendCommand2;
//    return 0;
//}
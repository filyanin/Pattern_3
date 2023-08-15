// ����� � ����������� ���������� ������� ��������� �������� �����, ��� ���������� �� ����� ��������� ���������, 
// ����������� � ������.��� ������� �������� ����� ������ ���� ���������� ������� �������� : ������� ���������, 
// ������� ���������� � ������������.������ ������ ����� ���������� ������ ������������ ��� �������.

#include <iostream>
#include <string>

// �����, �������������� ������ �������� �����
class FeedbackRequest {
public:
    enum class FeedbackType { Complaint, Suggestion, Comment };
    FeedbackType type;
    std::string message;

    FeedbackRequest(FeedbackType t, const std::string& msg)
        : type(t), message(msg) {}
};

// ����������� ������� ����� ����������� ��������
class FeedbackHandler {
protected:
    FeedbackHandler* successor;

public:
    FeedbackHandler() : successor(nullptr) {}

    void setSuccessor(FeedbackHandler* handler) {
        successor = handler;
    }

    virtual void processFeedback(const FeedbackRequest& request) = 0;
};

// ���������� ���������� ��� ������ ���������
class SupportService : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Complaint) {
            std::cout << "������ ���������: ������� ������: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

// ���������� ���������� ��� ������ ����������
class DevelopmentDepartment : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Suggestion) {
            std::cout << "����� ����������: ������� �����������: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

// ���������� ���������� ��� �����������
class Management : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Comment) {
            std::cout << "�����������: ������ �����������: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

//int main() {
//    setlocale(LC_ALL, "Russian");
//    // �������� � ��������� ������������
//    SupportService support;
//    DevelopmentDepartment development;
//    Management management;
//
//    support.setSuccessor(&development);
//    development.setSuccessor(&management);
//
//    // �������� � ��������� �������� �������� �����
//    FeedbackRequest request1(FeedbackRequest::FeedbackType::Complaint, "�������� � �������");
//    FeedbackRequest request2(FeedbackRequest::FeedbackType::Suggestion, "�������� ����� �������");
//    FeedbackRequest request3(FeedbackRequest::FeedbackType::Comment, "����������� ������ �������");
//
//    support.processFeedback(request1);
//    support.processFeedback(request2);
//    support.processFeedback(request3);
//
//    return 0;
//}

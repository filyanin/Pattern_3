// Пусть в организации существует система обработки обратной связи, где закапзчики ПО могут оставлять замечания, 
// предложения и жалобы.Эти запросы обратной связи должны быть обработаны разными службами : службой поддержки, 
// отделом разработки и руководством.Каждая служба может обработать только определенный тип запроса.

#include <iostream>
#include <string>

// Класс, представляющий запрос обратной связи
class FeedbackRequest {
public:
    enum class FeedbackType { Complaint, Suggestion, Comment };
    FeedbackType type;
    std::string message;

    FeedbackRequest(FeedbackType t, const std::string& msg)
        : type(t), message(msg) {}
};

// Абстрактный базовый класс обработчика запросов
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

// Конкретный обработчик для службы поддержки
class SupportService : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Complaint) {
            std::cout << "Служба поддержки: Принята жалоба: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

// Конкретный обработчик для отдела разработки
class DevelopmentDepartment : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Suggestion) {
            std::cout << "Отдел разработки: Принято предложение: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

// Конкретный обработчик для руководства
class Management : public FeedbackHandler {
public:
    void processFeedback(const FeedbackRequest& request) override {
        if (request.type == FeedbackRequest::FeedbackType::Comment) {
            std::cout << "Руководство: Принят комментарий: " << request.message << std::endl;
        }
        else if (successor != nullptr) {
            successor->processFeedback(request);
        }
    }
};

//int main() {
//    setlocale(LC_ALL, "Russian");
//    // Создание и настройка обработчиков
//    SupportService support;
//    DevelopmentDepartment development;
//    Management management;
//
//    support.setSuccessor(&development);
//    development.setSuccessor(&management);
//
//    // Создание и обработка запросов обратной связи
//    FeedbackRequest request1(FeedbackRequest::FeedbackType::Complaint, "Проблема с заказом");
//    FeedbackRequest request2(FeedbackRequest::FeedbackType::Suggestion, "Добавить новую функцию");
//    FeedbackRequest request3(FeedbackRequest::FeedbackType::Comment, "Понравилась работа сервиса");
//
//    support.processFeedback(request1);
//    support.processFeedback(request2);
//    support.processFeedback(request3);
//
//    return 0;
//}

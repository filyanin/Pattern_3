// Допустим  нас есть разные типы фигур. 
// С помощью Посетителя мы можем получить информацию о каждой, не придавая значения форме

#include <iostream>
#include <vector>


class Circle;
class Rectangle;
class Triangle;

// Интерфейс посетителя
class ShapeVisitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Triangle& triangle) = 0;
};

// Абстрактный класс фигуры
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Конкретные классы фигур
class Circle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
private:
    int radius;
};

class Rectangle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
private:
    int a, b;
};

class Triangle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
private:
    int a, b, c;
};

// Конкретный посетитель для вывода информации о фигурах
class InfoVisitor : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Visited Circle" << std::endl;
    }

    void visit(Rectangle& rectangle) override {
        std::cout << "Visited Rectangle" << std::endl;
    }

    void visit(Triangle& triangle) override {
        std::cout << "Visited Triangle" << std::endl;
    }
};
//
//int main() {
//    std::vector<Shape*> shapes;
//    shapes.push_back(new Circle());
//    shapes.push_back(new Rectangle());
//    shapes.push_back(new Triangle());
//
//    InfoVisitor infoVisitor;
//
//    for (Shape* shape : shapes) {
//        shape->accept(infoVisitor);
//    }
//
//    // Очищаем память
//    for (Shape* shape : shapes) {
//        delete shape;
//    }
//
//    return 0;
//}

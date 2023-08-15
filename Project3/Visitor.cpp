// ��������  ��� ���� ������ ���� �����. 
// � ������� ���������� �� ����� �������� ���������� � ������, �� �������� �������� �����

#include <iostream>
#include <vector>


class Circle;
class Rectangle;
class Triangle;

// ��������� ����������
class ShapeVisitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Triangle& triangle) = 0;
};

// ����������� ����� ������
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// ���������� ������ �����
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

// ���������� ���������� ��� ������ ���������� � �������
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
//    // ������� ������
//    for (Shape* shape : shapes) {
//        delete shape;
//    }
//
//    return 0;
//}

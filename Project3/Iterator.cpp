// ������� �������� 
// �� ���������� ������������ ��� �����: ���� ��� ������ �������, ������ ��� ������.
// ��� ��������� ��� ������ ��������� ������ � ������ MultiCollection.
// � ������, ���� �� ��� ��������� �����, ��������, � ����� ������, ����� ���� �� ������� ��� ���� ��������, ����������� ��� ��������

#include <iostream>
#include <vector>
#include <list>

// ��������� ���������
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

// ���������� �������� ��� �������

class VectorIterator : public Iterator {
private:
    std::vector<int>& collection;
    size_t position;

public:
    VectorIterator(std::vector<int>& coll) : collection(coll), position(0) {}

    bool hasNext() override {
        return position < collection.size();
    }

    int next() override {
        if (hasNext()) {
            return collection[position++];
        }
        throw std::out_of_range("No more elements");
    }
};

// ���������� �������� ��� ������
class ListIterator : public Iterator {
private:
    std::list<int>& collection;
    typename std::list<int>::iterator current;

public:
    ListIterator(std::list<int>& coll) : collection(coll), current(coll.begin()) {}

    bool hasNext() override {
        return current != collection.end();
    }

    int next() override {
        if (hasNext()) {
            return *(current++);
        }
        throw std::out_of_range("No more elements");
    }
};

// �����, ������� �������� ������ � ������, � ������� ��������� ��� ���
class MultiCollection {
private:
    std::vector<int> vectorData;
    std::list<int> listData;

public:
    void addToVector(const int& item) {
        vectorData.push_back(item);
    }

    void addToList(const int& item) {
        listData.push_back(item);
    }

    Iterator* createVectorIterator() {
        return new VectorIterator(vectorData);
    }

    Iterator* createListIterator() {
        return new ListIterator(listData);
    }
};

int main() {
    MultiCollection multiCollection;
    multiCollection.addToVector(1);
    multiCollection.addToList(2);
    multiCollection.addToVector(3);

    Iterator* vectorIterator = multiCollection.createVectorIterator();
    Iterator* listIterator = multiCollection.createListIterator();

    std::cout << "Vector elements: ";
    while (vectorIterator->hasNext()) {
        std::cout << vectorIterator->next() << " ";
    }
    std::cout << std::endl;

    std::cout << "List elements: ";
    while (listIterator->hasNext()) {
        std::cout << listIterator->next() << " ";
    }
    std::cout << std::endl;


    return 0;
}

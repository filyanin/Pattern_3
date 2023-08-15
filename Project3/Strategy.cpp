// � �������������� ���������� ���� ������� ������ � ��������� �����.
// ������, ��� ��������, ���������� ���������� ����������� ������, ��� ����, ������� ������������� ��������� ���������


#include <iostream>
#include <vector>
#include <algorithm>

// ��������� ���������
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

// ���������� ��������� ��� ���������� ���������
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "���������� ���������" << std::endl;
        int n = data.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// ���������� ��������� ��� ���������� ��������
class MergeSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "���������� ��������" << std::endl;
        // ���������� ���������� ��������
        std::sort(data.begin(), data.end());
    }
};

// ����� ���������, ������� ���������� ���������
class SortContext {
private:
    SortingStrategy* strategy;

public:
    SortContext(SortingStrategy* strat) : strategy(strat) {}

    void setStrategy(SortingStrategy* strat) {
        strategy = strat;
    }

    void performSort(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data);
        }
    }
};

//int main() {
//    setlocale(LC_ALL, "Russian");
//    std::vector<int> numbers = { 7, 2, 5, 1, 8, 3 };
//
//    BubbleSortStrategy bubbleSort;
//    MergeSortStrategy mergeSort;
//
//    SortContext context(&bubbleSort);
//    context.performSort(numbers);
//
//    for (int num : numbers) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    context.setStrategy(&mergeSort);
//    context.performSort(numbers);
//
//    for (int num : numbers) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

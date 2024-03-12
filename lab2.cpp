#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

class MyArray
{
public:
    MyArray();
    ~MyArray();
    friend ostream& operator <<(std::ostream& os, const MyArray array);
    void SetRandom(std::string& s);
    int SumBeforeMin();

private:
    std::vector<int> v;
    int CheckIndex(std::string& s);
};

MyArray::MyArray(){}
MyArray::~MyArray(){}

ostream& operator << (std::ostream& os, const MyArray array) {
    for (int i = 0; i < array.v.size(); i++)
    {
        os << array.v[i] << " ";
    }
    return os;
}

void MyArray::SetRandom(std::string& s) {

    int length = CheckIndex(s);
    v.resize(length);
    v.reserve(length + 1);

    srand(time(NULL));

    for (int i = 0; i < length; i++)
        v[i] = rand() % 100 + 1;
}

int MyArray::CheckIndex(std::string& s) {
    try
    {
        int temp = 0;
        temp = std::stoi(s);
        if (temp < 0)
            throw 1;
        return temp;
    }
    catch (...)
    {
        cerr << "Некорректный индекс\n";
        exit(1);
    }
}

int MyArray::SumBeforeMin()
{
    int min = distance(v.begin(), min_element(v.begin(), v.end()));
    int sum = 0;

    for (int i = 0; i < min; i++) {
        sum += v[i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string s;

    std::cout << "Введите размер массива: ";
    std::cin >> s;

    MyArray v;

    v.SetRandom(s);

    std::cout << "Массив: " << v << "\n" 
         << "Сумма до минимального элемента: " 
    << v.SumBeforeMin();
} 

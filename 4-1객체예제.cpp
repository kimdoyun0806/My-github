#include <iostream>

/*class Animal {
private:
    int food;
    int weight;

public:
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat() {
        std::cout << "이 동물의 food : " << food << std::endl;
        std::cout << "이 동물의 weight : " << weight << std::endl;
    }
};

int main() {
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}*/

class Date {
    int year;
    int month; //1~12
    int day;   //1~31

public:
    void SetDate(int year_, int month_, int date_) {
        year = year_;
        month = month_;
        day = date_;
    }
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc) {
        std::cout << "얼만큼 더할것인지?" << std::endl;
        std::cin >> inc;
        year += inc;
        std::cout << year << std::endl;
    }

    void ShowDate() {
        std::cout << "변경 된 날짜 : " << year << "." << month << "." << day << std::endl;
    }
};

int main() {
    Date date;
    int input;
    int inc;
    std::cout << "1. 년도 변경 " << std::endl;
    std::cout << "2. 월 변경 " << std::endl;
    std::cout << "3. 일 변경 " << std::endl;
    std::cin >> input;
    switch (input) {
    case 1:
        date.AddYear(inc);
    case 2:

    case 3:

    default:
        break;
    }

    date.SetDate(2023, 12, 3);
    date.ShowDate();
}
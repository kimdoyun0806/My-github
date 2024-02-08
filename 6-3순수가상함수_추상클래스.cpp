#include <iostream>
#pragma warning (disable:4996)

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}
    //가상 함수에 = 0; 을 붙여서, 반드시 오버라이딩이 되도록 만든 함수를
    //순수 가상 함수라고 부른다
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    Dog() : Animal() {}
    void speak() override { std::cout << "왈왈" << std::endl; }
};
class Cat :public Animal {
public:
    Cat() : Animal() {}
    void speak() override { std::cout << "야옹" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
}
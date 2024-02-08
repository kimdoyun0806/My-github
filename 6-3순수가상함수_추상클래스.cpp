#include <iostream>
#pragma warning (disable:4996)

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}
    //���� �Լ��� = 0; �� �ٿ���, �ݵ�� �������̵��� �ǵ��� ���� �Լ���
    //���� ���� �Լ���� �θ���
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    Dog() : Animal() {}
    void speak() override { std::cout << "�п�" << std::endl; }
};
class Cat :public Animal {
public:
    Cat() : Animal() {}
    void speak() override { std::cout << "�߿�" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
}
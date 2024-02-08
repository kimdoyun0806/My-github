#include <iostream>
#pragma warning (disable:4996)

//다중상속(multiple inheritance)
class A {
public:
    int a;
    A() { std::cout << "A생성자 호출" << std::endl; }
};

class B {
public:
    int b;
    B() { std::cout << "B생성자 호출" << std::endl; }
};

class C :public B, public A {
public:
    int c;
    C() :A(), B() { std::cout << "C생성자 호출" << std::endl; }
};
int main() { C c; }
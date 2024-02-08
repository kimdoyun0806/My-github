#include <iostream>
#include <string>
#pragma warning (disable:4996)

//protected
/*
class Base {
protected:
    std::string parent_string;

public:
    Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;

public:
    Derived() : child_string("파생"), Base() {
        std::cout << "파생 클래스" << std::endl;

        //그렇다면 현재 private 인 Base의
        //parent_string 에 접근할 수 있을까?
        parent_string = "바꾸기";
    }
    void what() { std::cout << child_string << std::endl; }
};*/

class Base {
public:
    std::string parent_string;

public:
    Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;

public:
    Derived() : child_string("파생"), Base() {
        std::cout << "파생 클래스" << std::endl;
    }
    void what() { std::cout << child_string << std::endl; }
};

int main() {
    Base p;
    //Base 에서는 parent_string 이 public 이므로
    //외부에서 접근 가능
    std::cout << p.parent_string << std::endl;

    Derived c;
    //Derived 에서는 parent_string 이
    //private 상속을 받았기 때문에 private 이
    //되어 외부에서 접근 불가능
    std::cout << c.parent_string << std::endl;
}
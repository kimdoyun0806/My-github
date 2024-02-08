#include <iostream>
#include <string>
#pragma warning (disable:4996)

class Base {
    std::string s;

public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

    virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};
class Derived : public Base {
    std::string s;

public:
    Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

    void what() { std::cout << "파생 클래스의 what()" << std::endl; }
};

int main() {
    //업캐스팅(파생 클래스에서 기반 클래스로 캐스팅 하는 것
    /*Base p;
    Derived c;

    std::cout << "===포인터 버전===" << std::endl;
    Base* p_c = &c;
    p_c->what();

    return 0;*/

    //다운캐스팅은 되지 않음
    /*Base p;
    Derived c;
    std::cout << "===포인터 버전===" << std::endl;
    Derived* p_p = &p;
    p_p->what();
    return 0;*/
    
    /*Base p;
    Derived c;

    std::cout << "===포인터 버전===" << std::endl;
    Base* p_p = &c;

    Derived* p_c = static_cast<Derived*>(p_p);
    p_c->what();
    return 0;*/

    Base p;
    Derived c;

    Base* p_p = &p;
    Base* p_c = &c;
    

    std::cout << "==실제 객체는 Base==" << std::endl;
    p_p->what();

    std::cout << "==실제 객체는 Derived==" << std::endl;
    p_c->what();

    return 0;
}
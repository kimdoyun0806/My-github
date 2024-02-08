#include <iostream>
#include <string>
#pragma warning (disable:4996)

class Base {
    std::string s;

public:
    Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

    virtual void what() { std::cout << "��� Ŭ������ what()" << std::endl; }
};
class Derived : public Base {
    std::string s;

public:
    Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }

    void what() { std::cout << "�Ļ� Ŭ������ what()" << std::endl; }
};

int main() {
    //��ĳ����(�Ļ� Ŭ�������� ��� Ŭ������ ĳ���� �ϴ� ��
    /*Base p;
    Derived c;

    std::cout << "===������ ����===" << std::endl;
    Base* p_c = &c;
    p_c->what();

    return 0;*/

    //�ٿ�ĳ������ ���� ����
    /*Base p;
    Derived c;
    std::cout << "===������ ����===" << std::endl;
    Derived* p_p = &p;
    p_p->what();
    return 0;*/
    
    /*Base p;
    Derived c;

    std::cout << "===������ ����===" << std::endl;
    Base* p_p = &c;

    Derived* p_c = static_cast<Derived*>(p_p);
    p_c->what();
    return 0;*/

    Base p;
    Derived c;

    Base* p_p = &p;
    Base* p_c = &c;
    

    std::cout << "==���� ��ü�� Base==" << std::endl;
    p_p->what();

    std::cout << "==���� ��ü�� Derived==" << std::endl;
    p_c->what();

    return 0;
}
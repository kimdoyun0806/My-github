#include <iostream>
#include <string>
#pragma warning (disable:4996)

//protected
/*
class Base {
protected:
    std::string parent_string;

public:
    Base() : parent_string("���") { std::cout << "��� Ŭ����" << std::endl; }
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;

public:
    Derived() : child_string("�Ļ�"), Base() {
        std::cout << "�Ļ� Ŭ����" << std::endl;

        //�׷��ٸ� ���� private �� Base��
        //parent_string �� ������ �� ������?
        parent_string = "�ٲٱ�";
    }
    void what() { std::cout << child_string << std::endl; }
};*/

class Base {
public:
    std::string parent_string;

public:
    Base() : parent_string("���") { std::cout << "��� Ŭ����" << std::endl; }
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;

public:
    Derived() : child_string("�Ļ�"), Base() {
        std::cout << "�Ļ� Ŭ����" << std::endl;
    }
    void what() { std::cout << child_string << std::endl; }
};

int main() {
    Base p;
    //Base ������ parent_string �� public �̹Ƿ�
    //�ܺο��� ���� ����
    std::cout << p.parent_string << std::endl;

    Derived c;
    //Derived ������ parent_string ��
    //private ����� �޾ұ� ������ private ��
    //�Ǿ� �ܺο��� ���� �Ұ���
    std::cout << c.parent_string << std::endl;
}
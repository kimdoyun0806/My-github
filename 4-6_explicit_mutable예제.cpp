#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

//explicit ����

/*class MyString {
    char* string_content; //���ڿ� �����͸� ����Ű�� ������
    int string_length;  //���ڿ� ����

    int memory_capacity;

public:
    // capacity��ŭ �̸� �Ҵ�
    // explicit : C++ �����Ϸ��� �Ͻ��� ��ȯ�� �� �� ������ ���
    explicit MyString(int capacity); 

    MyString(const char* str); // ���ڿ��� ���� ����
    MyString(const MyString& str); //���� ������
    ~MyString();
    int length() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[str.string_length];

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

int main() {
    MyString s(3);
}*/

//mutable ����

class A {
    //const �Լ������� ���� �ٲ� �� ����
    mutable int data_;

public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x;
    }
    void PrintData() const {
        std::cout << "data : " << data_ << std::endl;
    }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}
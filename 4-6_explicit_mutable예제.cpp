#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

//explicit 예제

/*class MyString {
    char* string_content; //문자열 데이터를 가리키는 포인터
    int string_length;  //문자열 길이

    int memory_capacity;

public:
    // capacity만큼 미리 할당
    // explicit : C++ 컴파일러가 암시적 변환을 할 수 없도록 명시
    explicit MyString(int capacity); 

    MyString(const char* str); // 문자열로 부터 생성
    MyString(const MyString& str); //복사 생성자
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

//mutable 예제

class A {
    //const 함수에서도 값을 바꿀 수 있음
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
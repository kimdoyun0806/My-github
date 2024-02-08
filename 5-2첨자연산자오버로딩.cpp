#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

//÷�� ������ (operator[])
class MyString {
    char* string_content; //���ڿ� �����͸� ����Ű�� ������
    int string_length; // ���ڿ� ����

    int memory_capacity; // ���� �Ҵ�� �뷮

public:
    MyString(char c); //���� �ϳ��� ����
    MyString(const char* str); //���ڿ��κ��� ����
    MyString(const MyString& str); //���� ������
    ~MyString();
    int length();
    void print() const;
    void println() const;

    char& operator[](const int index);
};
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() { return string_length; }

void MyString::print() const{ 
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

char& MyString::operator[](const int index) {
    return string_content[index];
}

int main() {
    MyString str("abcdef");
    str[3] = 'c';
    str.println();
}
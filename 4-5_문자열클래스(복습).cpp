#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

//1.����(char) �� ������ ���ڿ� ����, C ���ڿ�(char*) �� ������ ����
//2.���ڿ� ���̸� ���ϴ� �Լ�
//3.���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
//4.���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
//5.���ڿ��� ������ ��
//6.���ڿ� ũ�� ��(���� ��)
class string {
    char* str;
    int len;

public: 
    string(char c, int n);
      string(const char* s, int s_len);
      string(const string& s);
      ~string();

      int str_len(); //���ڿ� ���̸� ���ϴ� �Լ�
      void add_string(const string& s); // ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
      void copy_string(const string& s); // ���ڿ� ���� ��
};

string::string(char c, int n) {
    std::cout << "������ ȣ��" << std::endl;
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = c; //  *(str+1)�� ����
    }
    str[len] = '\0';
}

string::string(const char* s, int s_len) {
    len = s_len;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

string::~string() {
    std::cout << "�Ҹ��� ����" << std::endl;
    if (str)
        delete[] str;
}

string::string(const string& s) {
    std::cout << "���� ������ ȣ��" << std::endl;
    len = s.len;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

void string::add_string(const string& s) {
    char* temp = new char[strlen(s.str) + strlen(str) + 1];
    strcpy(temp, str);
    strcat(temp, s.str);

    delete[] str;
    str = new char[strlen(temp) + 1];
    strcpy(str, temp);
    len = strlen(str);
    std::cout << "���� ���ڴ�" << str << std::endl;
    delete[] temp;
}

void string::copy_string (const string& s) {
    char* temp = new char[strlen(s.str) + strlen(str) + 1];
    strcpy(temp, s.str);

    delete[] str;
    str = new char[strlen(temp) + 1];
    strcpy(str, temp);
    len = strlen(str);

    std::cout << "������ ����" << str << std::endl;
    delete[] temp;
}

int string::str_len() {
    return len;
}

int main() {
    char* arr;
    int length = 0;
    std::cout << "����� �Է�����" << std::endl;
    std::cin >> length;

    arr = new char[length + 1];

    std::cout << "���� �Է� : ";
    std::cin >> arr;

    string string1('f', 5);
    string string2(arr, length);
    string string3(string1);

    string1.add_string(string2);
    std::cout << "���̴�" << string2.str_len() << std::endl;
    string3.copy_string(string2);

    delete[] arr;
    return 0;
}
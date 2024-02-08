#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

class string {
    char* str;
    int len;

public:
    string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
    string(const char* s, int s_len);
    string(const string& s);
    ~string();

    void add_string(const string &s); // str 뒤에 s를 붙인다
    void copy_string(const string&s); // str 뒤에 s를 복사한다
    int str_len();                    //문자열 길이 리턴
};

string::string(char c, int n) {
    std::cout << "생성자 호출" << std::endl;
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = c; //*(str+1)과 동일한 의미
    }
    str[len] = '\0';
}

string::string(const char* s, int s_len) {
    len = s_len;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

string::~string() {
    std::cout << "소멸자 실행" << std::endl;
    if (str)
        delete[] str;
}

string::string(const string& s) {
    std::cout << "복사 생성자 호출" << std::endl;
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
    std::cout << "더한 문자는" << str << std::endl;
    delete[] temp;
}

void string::copy_string(const string& s) {
    char* temp = new char[strlen(s.str) + strlen(str) + 1];
    strcpy(temp, s.str);
    
    delete[] str;
    str = new char[strlen(temp) + 1];
    strcpy(str, temp);
    len = strlen(str);

    std::cout << "복사한 문자는" << str << std::endl;
    delete[] temp;
}

int string::str_len() {
    return len;
}

int main() {
    char* arr;
    int length = 0;

    std::cout << "몇글자 입력할지" << std::endl;
    std::cin >> length;

    arr = new char[length + 1];

    std::cout << "글자 입력 : ";
    std::cin >> arr;

    string string1('f', 5);
    string string2(arr, length);
    string string3(string1);

    string1.add_string(string2);
    std::cout << "길이는" << string2.str_len() << std::endl;
    string3.copy_string(string2);

    delete[] arr;

    return 0;
}
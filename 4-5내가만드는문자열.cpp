#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

class MyString {
    char* string_content; //문자열 데이터를 가리키는 포인터
    int string_length; //문자열 길이
    int memory_capacity; //문자열 길이 저장
public:
    MyString(int capaciry);//capacity 만큼 미리 할당

    MyString(char c); //문자 하나로 생성
    MyString(const char* str);//문자열로 부터 생성
    MyString(const MyString& str);//복사 생성자

    MyString& assign(const MyString& str); //assign 함수 (문자열 지정)
    MyString& assign(const char* str);

    MyString& insert(int loc, const MyString& str); //문장삽입 함수
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    //loc = 해당하는 문자 앞, num = 지우는 문자의 수
    MyString& erase(int loc, int num);

    int find(int find_from, MyString& str) const; //문자열 검색 함수
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;//크기 비교 함수

    ~MyString();
    int length() const;
    void print() const;
    void println() const;
    char at(int i) const; //임의의 위치의 문자를 리턴하는 함수

    int capacity();
    void reserve(int size);
};
MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}


//문자 하나로 생성
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

//문자열로 부터 생성
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
//복사 생성자
MyString::MyString(const MyString& str) {
    std::cout << "복사 생성자" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}

MyString::~MyString() {
    delete[] string_content;
}
int MyString::length() const { return string_length; }

void MyString::print() const {
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

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        //그러면 다시 할당을 해주어야 함
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    //굳이 str.string_length + 1 ~ string_length 부분은 초기화
    //시킬 필요 없다. 왜냐하면 거기 까지는 읽어들이지 않는다
    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        //그러면 다시 할당을 해줘야만 한다.
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;

    return *this;
}

int MyString::capacity() { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
    //만일 예약하려는 size가 현재 capacity보다 작다면
    //아무것도 안해도 된다.
}

char MyString::at(int i) const{  //지정된 문자열 찾기
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
    //이는 i의 위치 바로 앞에 문자를 삽입.
    //ex abc -> insert(1,"d") -> adbc

    //범위를 벗어나는 입력은 삽입 수행하지 않음
    if (loc<0 || loc>string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        //새롭게 동적으로 메모리 할당 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        //insert 되는 부분 직전까지의 내용 복사
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        //그리고 새롭게 insert되는 문자열 넣음
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        //이제 다시 원 문자열의 나머지 뒷부분 복사
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }
    //초과하지 않는 경우 굳이 동적할동 할 필요 없음
    //효율적으로 insert하기위해, 밀리는 부분은 먼저 뒤로 밀어버린다.

    for(int i=string_length-1; i>=loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    //insert되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc의 앞부터 시작해서 num 문자를 지운다
    if (num < 0 || loc <0 || loc > string_length) return *this;

    //지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
    //생각하면 된다.
    //abcd ->erase(1,2) -> ad
    for (int i = loc; i < string_length - num; i++) {
        string_content[i] = string_content[i+num];
    }
    string_length -= num; //문자열 길이를 num만큼 줄임
    return *this;
}

int MyString::find(int find_from, MyString& str)const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }
    return -1;//찾지 못했음
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
    //(*this) - (str) 을 수행해서 1,0,-1로 그 결과를 리턴
    // 1은 (*this)가 사전식으로 더 뒤에 온다는 의미
    // 0은 두 문자열이 같다는 의미
    //-1은 (*this)가 사전식으로 더 앞에 온다는 의미

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }

    //여기까지 했는데 끝나지 않았다면 앞 부분까지 모두 똑같은 것이 됨
    //만일 문자열 길이가 같다면 두 문자열은 같은 문자열이 됨

    if (string_length == str.string_length) return 0;

    //참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 됨
    else if (string_length > str.string_length)
        return 1;

    return -1;
}

int main() {
    MyString str1("very very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
    str1.erase(12, 4);
    str1.println();

    std::cout << "Location of first <very> in the string :" << str1.find(0, "very") << std::endl;
    std::cout << "Location of second <very> in the string : "
        << str1.find(str1.find(0, "very") + 1, "very") << std::endl;

    MyString str3("abcdef");
    MyString str4("abcde");

    std::cout << "str3 and str4 compare : " << str3.compare(str4) << std::endl;
}
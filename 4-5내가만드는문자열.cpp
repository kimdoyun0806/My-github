#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

class MyString {
    char* string_content; //���ڿ� �����͸� ����Ű�� ������
    int string_length; //���ڿ� ����
    int memory_capacity; //���ڿ� ���� ����
public:
    MyString(int capaciry);//capacity ��ŭ �̸� �Ҵ�

    MyString(char c); //���� �ϳ��� ����
    MyString(const char* str);//���ڿ��� ���� ����
    MyString(const MyString& str);//���� ������

    MyString& assign(const MyString& str); //assign �Լ� (���ڿ� ����)
    MyString& assign(const char* str);

    MyString& insert(int loc, const MyString& str); //������� �Լ�
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    //loc = �ش��ϴ� ���� ��, num = ����� ������ ��
    MyString& erase(int loc, int num);

    int find(int find_from, MyString& str) const; //���ڿ� �˻� �Լ�
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;//ũ�� �� �Լ�

    ~MyString();
    int length() const;
    void print() const;
    void println() const;
    char at(int i) const; //������ ��ġ�� ���ڸ� �����ϴ� �Լ�

    int capacity();
    void reserve(int size);
};
MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}


//���� �ϳ��� ����
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

//���ڿ��� ���� ����
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
//���� ������
MyString::MyString(const MyString& str) {
    std::cout << "���� ������" << std::endl;
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
        //�׷��� �ٽ� �Ҵ��� ���־�� ��
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    //���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
    //��ų �ʿ� ����. �ֳ��ϸ� �ű� ������ �о������ �ʴ´�
    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        //�׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
    //���� �����Ϸ��� size�� ���� capacity���� �۴ٸ�
    //�ƹ��͵� ���ص� �ȴ�.
}

char MyString::at(int i) const{  //������ ���ڿ� ã��
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
    //�̴� i�� ��ġ �ٷ� �տ� ���ڸ� ����.
    //ex abc -> insert(1,"d") -> adbc

    //������ ����� �Է��� ���� �������� ����
    if (loc<0 || loc>string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        //���Ӱ� �������� �޸� �Ҵ� 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        //insert �Ǵ� �κ� ���������� ���� ����
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        //�׸��� ���Ӱ� insert�Ǵ� ���ڿ� ����
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        //���� �ٽ� �� ���ڿ��� ������ �޺κ� ����
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }
    //�ʰ����� �ʴ� ��� ���� �����ҵ� �� �ʿ� ����
    //ȿ�������� insert�ϱ�����, �и��� �κ��� ���� �ڷ� �о������.

    for(int i=string_length-1; i>=loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    //insert�Ǵ� ���� �ٽ� ����ֱ�
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
    // loc�� �պ��� �����ؼ� num ���ڸ� �����
    if (num < 0 || loc <0 || loc > string_length) return *this;

    //����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ�
    //�����ϸ� �ȴ�.
    //abcd ->erase(1,2) -> ad
    for (int i = loc; i < string_length - num; i++) {
        string_content[i] = string_content[i+num];
    }
    string_length -= num; //���ڿ� ���̸� num��ŭ ����
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
    return -1;//ã�� ������
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
    //(*this) - (str) �� �����ؼ� 1,0,-1�� �� ����� ����
    // 1�� (*this)�� ���������� �� �ڿ� �´ٴ� �ǹ�
    // 0�� �� ���ڿ��� ���ٴ� �ǹ�
    //-1�� (*this)�� ���������� �� �տ� �´ٴ� �ǹ�

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }

    //������� �ߴµ� ������ �ʾҴٸ� �� �κб��� ��� �Ȱ��� ���� ��
    //���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� ���� ���ڿ��� ��

    if (string_length == str.string_length) return 0;

    //����� abc �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� ��
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
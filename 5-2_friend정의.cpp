#include <iostream>
#include <cstring>
#include <string.h>
#pragma warning (disable:4996)

class A {
private:
    void private_func() {}
    int private_num;

    //B는 A의 친구
    friend class B;

    //func은 A의 친구
    friend void func();
};

class B {
public:
    void b() {
        A a;

        //비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능
        a.private_func();
        a.private_num = 2;
    }
};

void func() {
    A a;

    //비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능
    a.private_func();
    a.private_num = 2;
}

int main() {}
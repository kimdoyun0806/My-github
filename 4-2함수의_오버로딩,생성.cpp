#include <iostream> 

//함수의 오버로딩 (강의 4-2참고)
/*void print(int x) { std::cout << "int :" << x << std::endl; }
//void print(char x) {std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);//자신과 최대로 근접한 함수를 찾게 됨
    print(c);

    return 0;
}*/

//모호한 오버로딩
/*void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;
    print(a);
    print(b);
    print(c);

    return 0;
}*/
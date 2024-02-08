#include<iostream>
//평소 코드
/*int change_val(int* p) {
    *p = 3;
    return 0;
}
int main() {
    int number = 5;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;
    return 0;
}*/

//참조자(래퍼런스-reference) 도입
/*int main() {
    int a = 3;
    int& another_a = a;

    another_a = 5;
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;
    return 0;
}*/

//함수 인자로 레퍼런스 받기
/*    int change_val(int& p) {
        p = 3;
        return 0;
    }
    int main() {
        int number = 5;
        std::cout << number << std::endl;
        change_val(number);
        std::cout << number << std::endl;
        return 0;
    }*/

// 참조자 이해하기

/*int main() {
    int x;
    int& y = x;
    int& z = y;
    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    y = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    z = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}*/
//상수에 대한 참조자
/*int main() {
    const int& ref = 4;
    int a = ref;

    std::cout << ref << std::endl;
}*/

//레퍼런스의 배열과 배열의 레퍼런스
/*int main() {
    int arr[3] = { 1,2,3 };
    int(&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}*/

//레퍼런스를 리턴하는 함수
/*int& function(int& a) {
    a = 5;
    return a;
}

int main() {
    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;
    return 0;
}*/

//참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
int function() {
    int a = 5;
    return a;
}

int main() {
    const int& c = function();
    std::cout << "c : " << c << std::endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <string.h>
#pragma warning (disable:4996)

//참고로 std::complex 복소수가 정의되어 있다
class Complex {
private:
    double real, img;

    //특정 문자열에서 수 부분을 double 값으로 반환하는 함수
    //참고로 stdlib.h 에서 atof 함수 제공
    double get_number(const char* str, int from, int to) const;

public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img;}
    Complex(const char* str);

    //이 부분은 없어도 정상 동작
    
    //컴파일러가 알아서 바꾸어줌
    //  a = a + "-1.1 + i3.923";
    //->a = a.operator+("-1.1 + i3.923");
    Complex operator+(const char* str) const; 
    Complex operator-(const char* str) const;
    Complex operator*(const char* str) const;
    Complex operator/(const char* str) const;


    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    //이 경우 위와 달리 객체 내부의 상태를 변경하기에
    //상수 함수로 선언할 수 없다.
    Complex& operator +=(const Complex& c);
    Complex& operator -=(const Complex& c);
    Complex& operator *=(const Complex& c);
    Complex& operator /=(const Complex& c);

    Complex& operator=(const Complex& c);

    void println() { std::cout << "(" << real << "," << img << ")" << std::endl;  }
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img)
        , (c.real * img - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

Complex& Complex::operator +=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator -=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator *=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator /=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
Complex Complex::operator+(const char* str) const {
    Complex temp(str);
    return (*this) + temp;
}

Complex Complex::operator-(const char* str) const {
    Complex temp(str);
    return (*this) - temp;
}
Complex Complex::operator*(const char* str) const {
    Complex temp(str);
    return (*this) * temp;
}

Complex Complex::operator/(const char* str) const {
    Complex temp(str);
    return (*this) / temp;
}

Complex::Complex(const char* str) {
    //입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 함
    //문자열의 꼴 "[부호](실수부)(부호)i(허수부)"
    //이 때 맨 앞의 부호는 생략 가능(생략시 +라 가정)
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    //먼저 가장 기준의 되는 i 의 위치를 찾는다
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }
    //만일 i 가 없다면 이 수는 실수 뿐이다
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }
    //만일 i 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i+1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-')
        img *= -1.0;
}

double Complex::get_number(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        }
        else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        }
        else
            break;
    }
    if (minus) num *= -1.0;

    return num;
}

int main() {
    //Complex a(1.0, 2.0);
    //Complex b(3.0, -2.0);
    //Complex c(0.0, 0.0);
    //c = a * b + a / b + a + b;
    //c.println();

    //a += b;
    //a.println();
    // b.println();
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    a = a - "1.2 -i1.823";
    a.println();
    a = a * "2.3+i22";
    a.println();
    a = a / "-12+i55";
    a.println();
}
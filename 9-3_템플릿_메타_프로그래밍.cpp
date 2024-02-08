#include <iostream>
#include <typeinfo>
#pragma warning (disable:4996)

//나만의 std::array 구현
/*template <typename T, unsigned N>
class Array {
    T data[N];

public:
    //배열을 받는 래퍼런스 arr
    Array(T(&arr)[N]) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }

    T* get_array() { return data; }

    unsigned int size() { return N; }

    void print_all() {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int arr[3] = { 1,2,3 };

    //배열 wrapper 클래스
    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    //두 개의 클래스는 다른 클래스
    Array<int, 5>;
    Array<int, 3>;
    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << std::endl;
}*/

/*template <int N>
struct Int {
    static const int num = N;
};

template <typename T, typename U>
struct add {
    typedef Int<T::num + U::num> result;
};

int main() {
    typedef Int<1> one;
    typedef Int<2> two;

    typedef add<one, two>::result three;

    std::cout << "Addition result : " << three::num << std::endl;
}*/

//템플릿 메타 프로그래밍
//->템플릿을 사용하면 객체를 생성하지 않더라도 타입에 어떠한 값을
//부여할 수 있고, 그 타입들로 연산을 할 수 있다
//이렇게 타입을 가지고 컴파일 타임에 생성되는 코드로 프로그래밍 하는 것을
// 메타 프로그래밍이라고 한다(C++의 경우 줄여서 TMP)

//컴파일 타임 팩토리얼 계산
/*template <int N>
struct Factorial {
    static const int result = N * Factorial<N - 1>::result;
};

template<>
struct Factorial<1> {
    static const int result = 1;
};

int main() {
    std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
}*/

//두 수의 최대 공약수를 구하기 위해선 보통 유클리드 호제법을 이용
/*int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}*/

//이를 TMP로 바꿔본다
template<int x, int y>
struct GCD {
    static const int value = GCD<y, x% y>::value;
};

template<int x>
struct GCD<x, 0> {
    static const int value = x;
};

//유리수를 오차 없이 표현해주는 클래스
template <int N, int D = 1>
struct Ratio {
    typedef Ratio<N, D> type;
    static const int num = N;  // 분자
    static const int den = D;  // 분모
};
template <class R1, class R2>
struct _Ratio_add {
    typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
    //최대공약수 출력
    //std::cout << "gcd (36,24) :: " << GCD<36, 24>::value << std::endl;

    typedef Ratio<2, 3> rat;
    typedef Ratio<3, 2> rat2;
    typedef Ratio_add<rat, rat2> rat3;

    std::cout << rat3::num << " / " << rat3::den << std::endl;

    return 0;
}
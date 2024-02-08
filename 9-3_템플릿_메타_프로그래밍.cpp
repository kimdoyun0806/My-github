#include <iostream>
#include <typeinfo>
#pragma warning (disable:4996)

//������ std::array ����
/*template <typename T, unsigned N>
class Array {
    T data[N];

public:
    //�迭�� �޴� ���۷��� arr
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

    //�迭 wrapper Ŭ����
    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    //�� ���� Ŭ������ �ٸ� Ŭ����
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

//���ø� ��Ÿ ���α׷���
//->���ø��� ����ϸ� ��ü�� �������� �ʴ��� Ÿ�Կ� ��� ����
//�ο��� �� �ְ�, �� Ÿ�Ե�� ������ �� �� �ִ�
//�̷��� Ÿ���� ������ ������ Ÿ�ӿ� �����Ǵ� �ڵ�� ���α׷��� �ϴ� ����
// ��Ÿ ���α׷����̶�� �Ѵ�(C++�� ��� �ٿ��� TMP)

//������ Ÿ�� ���丮�� ���
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

//�� ���� �ִ� ������� ���ϱ� ���ؼ� ���� ��Ŭ���� ȣ������ �̿�
/*int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}*/

//�̸� TMP�� �ٲ㺻��
template<int x, int y>
struct GCD {
    static const int value = GCD<y, x% y>::value;
};

template<int x>
struct GCD<x, 0> {
    static const int value = x;
};

//�������� ���� ���� ǥ�����ִ� Ŭ����
template <int N, int D = 1>
struct Ratio {
    typedef Ratio<N, D> type;
    static const int num = N;  // ����
    static const int den = D;  // �и�
};
template <class R1, class R2>
struct _Ratio_add {
    typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
    //�ִ����� ���
    //std::cout << "gcd (36,24) :: " << GCD<36, 24>::value << std::endl;

    typedef Ratio<2, 3> rat;
    typedef Ratio<3, 2> rat2;
    typedef Ratio_add<rat, rat2> rat3;

    std::cout << rat3::num << " / " << rat3::den << std::endl;

    return 0;
}
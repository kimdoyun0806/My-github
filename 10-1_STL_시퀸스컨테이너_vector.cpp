#include <iostream>
#pragma warning (disable:4996)

//기초 버블 정렬 코드
/*for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if (arr[i] > arr[j]) {
            swap(arr,i,j)
        }
    }
}*/

//벡터 자료형: 맨 뒤에 새로운 원소를 추가하거나 제거
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10); // 맨 뒤에 10 추가
    vec.push_back(20); // 맨 뒤에 20 추가
    vec.push_back(30); // 맨 뒤에 30 추가
    vec.push_back(40); // 맨 뒤에 40 추가

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << "vec 의" << i + 1 << "번째 원소 :: " << vec[i] << std::endl;
    }
}*/

//반복자 사용 예시
//반복자는 컨테이너에 iterator 멤버 타입으로 정의되어 있음
//vertor.end는 마지막 원소가 아닌 마지막 원소의 뒤를 가리키는
//반복자를 리턴한다
/*
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    //전체 벡터 출력
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    //int arr[4] = {10,20,30,40}
    //*(arr+2) == arr[2] == 30;
    //*(itr+2) == vec[2] == 30;

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "3번째 원소 :: " << *itr << std::endl;
}*/

//insert 와 erase 함수 추가
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //전체 벡터 출력
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);
    std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;

    //vec[2] 앞에 15 추가
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
    //vec[3] 제거
    vec.erase(vec.begin() + 3);
    print_vector(vec);

}*/

//vector에서 반복자로 erase,insert 함수 사용할 때 주의점
//컨테이너에 원소를 추가하거나 제거하게 되면
//기존에 사용하였던 반복자들은 사용 불가능
//vec.vector(itr)을 수행할 시 더이상 itr은 유효한 반복자가 아니게 됨

/*#include<vector> 

template <typename T>
void print_vector(std::vector<T>& vec) {
    //전체 벡터 출력
    std::cout << "[ ";
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "]";
}
int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(20);
    
    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin();

    for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        if (vec[i] == 20) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
    std::cout << "값이 20인 원소를 지운다" << std::endl;
    print_vector(vec);
}*/

//const_iterator : const 포인터라 생각
//가리키고 있는 원소의 값을 바꿀 수 없다
//반복자의 값을 바꾸지 않고 참조만 하는 경우가 많으므로
//const_iterator 를 적절히 이용하는 것이 좋다
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //전체 벡터를 출력하기
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "초기 vec 상태" << std::endl;
    print_vector(vec);

    //itr 은 vec[2]를 가리킨다
    std::vector<int>::iterator itr = vec.begin() + 2;

    //vec[2]의 값을 50으로 바꾼다
    *itr = 50;

    std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
    print_vector(vec);

    //상수 반복자가 가리키는 값은 바꿀 수 없다
    std::vector<int>::const_iterator citr = vec.cbegin() + 2;
    *citr = 30;
}*/

//역반복자(reverse iterator)
//반복자와 똑같지만 벡터 뒤에서부터 앞으로 거꾸로 가는 특징
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //전체 벡터 출력
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "초기 vec 상태" << std::endl;
    print_vector(vec);

    std::cout << "역으로 vec 출력" << std::endl;
    std::vector<int>::reverse_iterator r_itr = vec.rbegin();
    for (; r_itr != vec.rend(); r_itr++) {
        std::cout << *r_itr << std::endl;
    }
}*/

//역반복자 사용 예시(오류)
//vector의 index를 담당하는 타입이 부호 없는 정수
//따라서 i가 0일 때 i-- 를 하게 된다면 -1이 아닌
//해당 타입에서 가장 큰 정수가 된다
//따라서 for문이 영원히 반복

//결론적으로 역으로 원소를 참조하고 싶다면 역반복자를 사용
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    //끝에서 부터 출력
    for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}*/

//범위 기반 for 문
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    //range-based for 문
    // elem = vec[i]와 같은 형태
    for (int elem : vec) {
        std::cout << "원소 : " << elem  << std::endl;
    }
    return 0;
}*/

//복사하기 보다는 레퍼런스를 받고 싶을 때
/*
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //전체 벡터 출력
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
    //전체 벡터를 출력하기
    //변수 elem은 vec의 원소들을 상수 레퍼런스로 접근
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "print_vector" << std::endl;
    print_vector(vec);
    std::cout << "print_vector_range_based" << std::endl;
    print_vector_range_based(vec);
    return 0;
}*/
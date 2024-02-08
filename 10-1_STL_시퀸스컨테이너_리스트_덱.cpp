#include <iostream>
#pragma warning (disable:4996)

//vector와는 달리 임의의 위치에 있는 원소에 접근을 바로 할 수 없다
//list 컨테이너 자체에서는 시작 원소와 마지막 원소의 위치만을 기억
//리스트는 아예 []나 at 함수가 정의되어 있지 않음
//vector의 경우 임의의 위치에 원소를 추가,제거 작업이 O(n)
//리스트의 경우 O(1)으로 빠르게 수행가능
/*
#include <list>

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}*/

//(추가) 반복자의 경우 itr++ or itr-- 같은 연산밖에 수행할 수 없다
//itr + 5 의 경우 불가능
//임의의 위치에 있는 원소를 가리킬 수 없고
//반복자는 오직 한 칸씩 밖에 움직일 수 없다

/*#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";
    //전체 리스트 출력(이 역시 범위 기반 for문을 쓸 수 있다
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "처음 리스트의 상태" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
        //만일 현재 원소가 20이라면
        //그 앞에 50을 집어넣는다
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }
    std::cout << "값이 20인 원소 앞에 50을 추가" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
        //값이 30인 원소를 삭제
        if (*itr == 30) {
        //erase를 하게 되면 해당 반복자가 무효화 된다
        //따라서 해당 반복자의 itr++을 못하므로 break문 사용
            lst.erase(itr);
            break;
        }
    }
    std::cout << "값이 30인 원소를 제거" << std::endl;
    print_list(lst);
}*/

//덱(deque) : 벡터와 비슷하게 O(1)으로 임의의 위치의 원소에 접근 가능
//맨 뒤에 원소를 추가/제거 하는 작업도 O(1) 수행 가능
//벡터와는 다르게 맨 앞에 원소를 추가/제거 하는 작업도 O(1) 가능
//임의의 위치에 있는 원소를 추가/제거 하는 작업은 벡터와 마찬가지로 O(n) 가능
//벡터와는 다르게 덱의 경우 원소들이 실제로 메모리 상에서
//연속적으로 존재하지는 않음

//때문에 원소들이 어디에 저장되어 있는지에 대한 정보를 보관하기 위해
//추가적인 메모리가 더 필요로 하고
//즉 덱은 실행 속도를 위해 메모리를 희생하는 컨테이너
#include <deque>

template <typename T>
void print_deque(std::deque<T>& dq) {
    //전체 덱 출력
    std::cout << "[";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    std::cout << "초기 dq 상태" << std::endl;
    print_deque(dq);

    std::cout << "맨 앞의 원소 제거" << std::endl;
    dq.pop_front();
    print_deque(dq);
}

//그래서 어떤 컨테이너를 사용해야하는지?

//일반적인 상황에서는 그냥 벡터를 사용(거의 만능)

//만약 맨 끝이 아닌 중간에 원소들을 추가/제거하는 일을 많이 하고
//원소들을 순차적으로만 접근한다면 리스트 사용

//만약에 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이하면 덱을 사용

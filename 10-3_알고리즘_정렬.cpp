#include <iostream>

//알고리즘의 함수의 형태는 두 개의 형태를 가짐

//template <typename Iter>
//void do_something(Iter begin, Iter end);
//->알고리즘을 수행할 반복자의 시작점과 끝점 바로 뒤를 받는다

//template <typename Iter, typename Pred>
//void do_something(Iter begin, Iter end, Pred pred)
//전자와 동일하되 '특정한 조건'추가 인자로 받는다
//이를 서술자(Predicate)라고 부르며 pred 에는 보통 bool 을 리턴하는 함수 객체를 전달하게 된다

//정렬 함수

//sort : 일반적인 정렬 하수

//stable_sort : 정렬을 하되 원소들 간의 순서를 보존
//ex)sort의 경우 벡터 [a,b]에서 둘의 크기가 같다면 랜덤으로 [a,b] 혹은 [b,a]
//stable_sort는 순서를 반드시 보존 때문에 sort 보다 좀 더 느리다

//partial_sort : 배열의 일부분만 정렬

#include <algorithm>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
}
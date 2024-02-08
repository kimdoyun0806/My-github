#include <iostream>
#include <string>


//셋과 맵 모두 중복된 원소를 허락하지 않지만
//멀티셋과 멀티맵을 중복된 원소를 허락한다
/*#include <set>
template <typename K>
void print_set(const std::multiset<K>& s) {
    //셋의 모든 원소 출력
    for (const auto& elem : s) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::multiset<std::string> s;

    s.insert("a");
    s.insert("b");
    s.insert("a");
    s.insert("c");
    s.insert("d");
    s.insert("c");

    print_set(s);
}*/

/*#include<map>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
    //맵의 원소들을 출력
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "haba"));

    print_map(m);

    //C++ 표준을 읽어보면 무엇을 리턴하라고 정해지지 않음
    //해당되는 값들 중 아무거나 리턴해도 상관 없다며 실행?
    //std::cout << m.find(1)->second << std::endl;


    //그렇다면 1에 대응되는 값들이 뭐가 있는지 알기 위해
    //멀티맵은 equal_range 함수를 제공

    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->first << " " << itr->second << " " << std::endl;
    }
}
//맵과는 다르게 멀티맵의 경우 []연산자를 사용할 수 없다
//m[1]을 했을 때 "hello"를 리턴해야할지 "hi"를 리턴해야 할지 알 수 없기 때문
*/

//정렬되지 않은 셋과 맵(unordered_set, unordered_map)
//셋이나 맵의 경우 원소들이 순서대로 정렬되어 내부에 저장되지만
//이 경우 원소들이 순서대로 정렬되서 들어가지 않음
/*#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    //셋의모든 원소 출력
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::unordered_set<std::string> s;
    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("psi");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");

    print_unordered_set(s);
}*/

/*#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    //셋의 모든 원소 출력
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
    auto itr = s.find(key);
    if (itr != s.end()) {
        std::cout << key << "가 존재" << std::endl;
    }
    else std::cout << key << "가 없다" << std::endl;
}
int main() {
    std::unordered_set<std::string> s;

    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("psi");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");

    print_unordered_set(s);
    std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
    is_exist(s, std::string("c++"));
    is_exist(s, std::string("c"));

    std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
    std::cout << "'hi'를 삭제" << std::endl;
    s.erase(s.find("hi"));
    is_exist(s, std::string("hi"));

}*/

// 뭘 써야지 적절한지?

// - 데이터의 존재 유무 만 궁금할 경우 → set

// - 중복 데이터를 허락할 경우 → multiset(insert, erase, 
// find 모두 O(logN), 최악의 경우 O(logN))

// 데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

// - 중복 키를 허락할 경우 → multimap(insert, erase, 
// find 모두 O(logN), 최악의 경우 O(logN))

// - 속도가 매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map
// insert, erase,find 모두 O(1), 최악의 경우 O(N))
// 그러므로 해시함수와 상자 개수를 잘 설정해야 한다
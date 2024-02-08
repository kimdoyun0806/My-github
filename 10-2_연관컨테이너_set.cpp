#include <iostream>
#pragma warning (disable:4996)

//시퀸스 컨테이너와는 다르게 키(key)-값(value)의 구조

//셋(set)
/*#include <set>

template <typename T>
void print_set(std::set<T>& s) {
    //셋의 모든 원소 출력
    std::cout << "[";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    //무작위로 하여도 순서대로 정렬됨
    //시퀸스 컨테이너처럼 '어디에'추가할지에 대한 정보가 없기 때문
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬되어 나온다" << std::endl;
    print_set(s);

    std::cout << "20이 s의 원소인가? :: ";
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }


    std::cout << "25가 s의원소인가? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}*/

//셋의 특징으로 셋 안에는 중복된 원소들이 없다
/*#include <set> 

template <typename T>
void print_set(std::set<T>& s) {
    //셋의 모든 원소들을 출력
    std::cout << "[";
    for (const auto elem : s) {
        std::cout << elem << " ";
    }
    std::cout << " ] " << std::endl;
}

int main() {
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(10);
    s.insert(20);

    print_set(s);
}*/

//내가 만든 클래스 객체를 셋에 넣고 싶을 때

#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
    //셋의 모든 원소 출력
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
}
class Todo {
    int priority;
    std::string job_desc;

public:
    Todo(int priority, std::string job_desc)
        :priority(priority), job_desc(job_desc) {}

    bool operator<(const Todo& t) const {
        if (priority == t.priority) {
            return job_desc < t.job_desc;
        }
        return priority > t.priority;
    }
    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[ 중요도: " << td.priority << "]" << td.job_desc;
    return o;
}

int main() {
    std::set<Todo> todos;

    todos.insert(Todo(1, "테스트"));
    todos.insert(Todo(2, "두 번째 실험"));

    print_set(todos);

    std::cout << "ㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
    std::cout << "2번 지우기" << std::endl;
    todos.erase(todos.find(Todo(2, "두 번째 실험")));
    print_set(todos);
}
#include <iostream>
#pragma warning (disable:4996)

//������ �����̳ʿʹ� �ٸ��� Ű(key)-��(value)�� ����

//��(set)
/*#include <set>

template <typename T>
void print_set(std::set<T>& s) {
    //���� ��� ���� ���
    std::cout << "[";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    //�������� �Ͽ��� ������� ���ĵ�
    //������ �����̳�ó�� '���'�߰������� ���� ������ ���� ����
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "������� ���ĵǾ� ���´�" << std::endl;
    print_set(s);

    std::cout << "20�� s�� �����ΰ�? :: ";
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }


    std::cout << "25�� s�ǿ����ΰ�? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}*/

//���� Ư¡���� �� �ȿ��� �ߺ��� ���ҵ��� ����
/*#include <set> 

template <typename T>
void print_set(std::set<T>& s) {
    //���� ��� ���ҵ��� ���
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

//���� ���� Ŭ���� ��ü�� �¿� �ְ� ���� ��

#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
    //���� ��� ���� ���
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
    o << "[ �߿䵵: " << td.priority << "]" << td.job_desc;
    return o;
}

int main() {
    std::set<Todo> todos;

    todos.insert(Todo(1, "�׽�Ʈ"));
    todos.insert(Todo(2, "�� ��° ����"));

    print_set(todos);

    std::cout << "�ѤѤѤѤѤѤ�" << std::endl;
    std::cout << "2�� �����" << std::endl;
    todos.erase(todos.find(Todo(2, "�� ��° ����")));
    print_set(todos);
}
#include <iostream>
#include <string>


//�°� �� ��� �ߺ��� ���Ҹ� ������� ������
//��Ƽ�°� ��Ƽ���� �ߺ��� ���Ҹ� ����Ѵ�
/*#include <set>
template <typename K>
void print_set(const std::multiset<K>& s) {
    //���� ��� ���� ���
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
    //���� ���ҵ��� ���
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

    //C++ ǥ���� �о�� ������ �����϶�� �������� ����
    //�ش�Ǵ� ���� �� �ƹ��ų� �����ص� ��� ���ٸ� ����?
    //std::cout << m.find(1)->second << std::endl;


    //�׷��ٸ� 1�� �����Ǵ� ������ ���� �ִ��� �˱� ����
    //��Ƽ���� equal_range �Լ��� ����

    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->first << " " << itr->second << " " << std::endl;
    }
}
//�ʰ��� �ٸ��� ��Ƽ���� ��� []�����ڸ� ����� �� ����
//m[1]�� ���� �� "hello"�� �����ؾ����� "hi"�� �����ؾ� ���� �� �� ���� ����
*/

//���ĵ��� ���� �°� ��(unordered_set, unordered_map)
//���̳� ���� ��� ���ҵ��� ������� ���ĵǾ� ���ο� ���������
//�� ��� ���ҵ��� ������� ���ĵǼ� ���� ����
/*#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    //���Ǹ�� ���� ���
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
    //���� ��� ���� ���
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
    auto itr = s.find(key);
    if (itr != s.end()) {
        std::cout << key << "�� ����" << std::endl;
    }
    else std::cout << key << "�� ����" << std::endl;
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
    std::cout << "�ѤѤѤѤѤѤѤѤ�" << std::endl;
    is_exist(s, std::string("c++"));
    is_exist(s, std::string("c"));

    std::cout << "�ѤѤѤѤѤѤѤѤ�" << std::endl;
    std::cout << "'hi'�� ����" << std::endl;
    s.erase(s.find("hi"));
    is_exist(s, std::string("hi"));

}*/

// �� ����� ��������?

// - �������� ���� ���� �� �ñ��� ��� �� set

// - �ߺ� �����͸� ����� ��� �� multiset(insert, erase, 
// find ��� O(logN), �־��� ��� O(logN))

// �����Ϳ� �����Ǵ� �����͸� �����ϰ� ���� ��� �� map

// - �ߺ� Ű�� ����� ��� �� multimap(insert, erase, 
// find ��� O(logN), �־��� ��� O(logN))

// - �ӵ��� �ſ� �߿��ؼ� ����ȭ�� �ؾ��ϴ� ��� �� unordered_set, unordered_map
// insert, erase,find ��� O(1), �־��� ��� O(N))
// �׷��Ƿ� �ؽ��Լ��� ���� ������ �� �����ؾ� �Ѵ�
#include <iostream>

//�˰����� �Լ��� ���´� �� ���� ���¸� ����

//template <typename Iter>
//void do_something(Iter begin, Iter end);
//->�˰����� ������ �ݺ����� �������� ���� �ٷ� �ڸ� �޴´�

//template <typename Iter, typename Pred>
//void do_something(Iter begin, Iter end, Pred pred)
//���ڿ� �����ϵ� 'Ư���� ����'�߰� ���ڷ� �޴´�
//�̸� ������(Predicate)��� �θ��� pred ���� ���� bool �� �����ϴ� �Լ� ��ü�� �����ϰ� �ȴ�

//���� �Լ�

//sort : �Ϲ����� ���� �ϼ�

//stable_sort : ������ �ϵ� ���ҵ� ���� ������ ����
//ex)sort�� ��� ���� [a,b]���� ���� ũ�Ⱑ ���ٸ� �������� [a,b] Ȥ�� [b,a]
//stable_sort�� ������ �ݵ�� ���� ������ sort ���� �� �� ������

//partial_sort : �迭�� �Ϻκи� ����

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
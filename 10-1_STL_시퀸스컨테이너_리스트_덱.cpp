#include <iostream>
#pragma warning (disable:4996)

//vector�ʹ� �޸� ������ ��ġ�� �ִ� ���ҿ� ������ �ٷ� �� �� ����
//list �����̳� ��ü������ ���� ���ҿ� ������ ������ ��ġ���� ���
//����Ʈ�� �ƿ� []�� at �Լ��� ���ǵǾ� ���� ����
//vector�� ��� ������ ��ġ�� ���Ҹ� �߰�,���� �۾��� O(n)
//����Ʈ�� ��� O(1)���� ������ ���డ��
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

//(�߰�) �ݺ����� ��� itr++ or itr-- ���� ����ۿ� ������ �� ����
//itr + 5 �� ��� �Ұ���
//������ ��ġ�� �ִ� ���Ҹ� ����ų �� ����
//�ݺ��ڴ� ���� �� ĭ�� �ۿ� ������ �� ����

/*#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";
    //��ü ����Ʈ ���(�� ���� ���� ��� for���� �� �� �ִ�
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

    std::cout << "ó�� ����Ʈ�� ����" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
        //���� ���� ���Ұ� 20�̶��
        //�� �տ� 50�� ����ִ´�
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }
    std::cout << "���� 20�� ���� �տ� 50�� �߰�" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
        //���� 30�� ���Ҹ� ����
        if (*itr == 30) {
        //erase�� �ϰ� �Ǹ� �ش� �ݺ��ڰ� ��ȿȭ �ȴ�
        //���� �ش� �ݺ����� itr++�� ���ϹǷ� break�� ���
            lst.erase(itr);
            break;
        }
    }
    std::cout << "���� 30�� ���Ҹ� ����" << std::endl;
    print_list(lst);
}*/

//��(deque) : ���Ϳ� ����ϰ� O(1)���� ������ ��ġ�� ���ҿ� ���� ����
//�� �ڿ� ���Ҹ� �߰�/���� �ϴ� �۾��� O(1) ���� ����
//���Ϳʹ� �ٸ��� �� �տ� ���Ҹ� �߰�/���� �ϴ� �۾��� O(1) ����
//������ ��ġ�� �ִ� ���Ҹ� �߰�/���� �ϴ� �۾��� ���Ϳ� ���������� O(n) ����
//���Ϳʹ� �ٸ��� ���� ��� ���ҵ��� ������ �޸� �󿡼�
//���������� ���������� ����

//������ ���ҵ��� ��� ����Ǿ� �ִ����� ���� ������ �����ϱ� ����
//�߰����� �޸𸮰� �� �ʿ�� �ϰ�
//�� ���� ���� �ӵ��� ���� �޸𸮸� ����ϴ� �����̳�
#include <deque>

template <typename T>
void print_deque(std::deque<T>& dq) {
    //��ü �� ���
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

    std::cout << "�ʱ� dq ����" << std::endl;
    print_deque(dq);

    std::cout << "�� ���� ���� ����" << std::endl;
    dq.pop_front();
    print_deque(dq);
}

//�׷��� � �����̳ʸ� ����ؾ��ϴ���?

//�Ϲ����� ��Ȳ������ �׳� ���͸� ���(���� ����)

//���� �� ���� �ƴ� �߰��� ���ҵ��� �߰�/�����ϴ� ���� ���� �ϰ�
//���ҵ��� ���������θ� �����Ѵٸ� ����Ʈ ���

//���࿡ �� ó���� �� ��ο� ���ҵ��� �߰��ϴ� �۾��� �����ϸ� ���� ���

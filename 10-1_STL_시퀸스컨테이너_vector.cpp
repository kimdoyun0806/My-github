#include <iostream>
#pragma warning (disable:4996)

//���� ���� ���� �ڵ�
/*for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if (arr[i] > arr[j]) {
            swap(arr,i,j)
        }
    }
}*/

//���� �ڷ���: �� �ڿ� ���ο� ���Ҹ� �߰��ϰų� ����
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10); // �� �ڿ� 10 �߰�
    vec.push_back(20); // �� �ڿ� 20 �߰�
    vec.push_back(30); // �� �ڿ� 30 �߰�
    vec.push_back(40); // �� �ڿ� 40 �߰�

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << "vec ��" << i + 1 << "��° ���� :: " << vec[i] << std::endl;
    }
}*/

//�ݺ��� ��� ����
//�ݺ��ڴ� �����̳ʿ� iterator ��� Ÿ������ ���ǵǾ� ����
//vertor.end�� ������ ���Ұ� �ƴ� ������ ������ �ڸ� ����Ű��
//�ݺ��ڸ� �����Ѵ�
/*
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    //��ü ���� ���
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    //int arr[4] = {10,20,30,40}
    //*(arr+2) == arr[2] == 30;
    //*(itr+2) == vec[2] == 30;

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "3��° ���� :: " << *itr << std::endl;
}*/

//insert �� erase �Լ� �߰�
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //��ü ���� ���
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

    std::cout << "ó�� ���� ����" << std::endl;
    print_vector(vec);
    std::cout << "�ѤѤѤѤѤѤѤѤѤѤѤ�" << std::endl;

    //vec[2] �տ� 15 �߰�
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::cout << "�ѤѤѤѤѤѤѤѤѤѤѤ�" << std::endl;
    //vec[3] ����
    vec.erase(vec.begin() + 3);
    print_vector(vec);

}*/

//vector���� �ݺ��ڷ� erase,insert �Լ� ����� �� ������
//�����̳ʿ� ���Ҹ� �߰��ϰų� �����ϰ� �Ǹ�
//������ ����Ͽ��� �ݺ��ڵ��� ��� �Ұ���
//vec.vector(itr)�� ������ �� ���̻� itr�� ��ȿ�� �ݺ��ڰ� �ƴϰ� ��

/*#include<vector> 

template <typename T>
void print_vector(std::vector<T>& vec) {
    //��ü ���� ���
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
    
    std::cout << "ó�� ���� ����" << std::endl;
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin();

    for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        if (vec[i] == 20) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
    std::cout << "���� 20�� ���Ҹ� �����" << std::endl;
    print_vector(vec);
}*/

//const_iterator : const �����Ͷ� ����
//����Ű�� �ִ� ������ ���� �ٲ� �� ����
//�ݺ����� ���� �ٲ��� �ʰ� ������ �ϴ� ��찡 �����Ƿ�
//const_iterator �� ������ �̿��ϴ� ���� ����
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //��ü ���͸� ����ϱ�
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "�ʱ� vec ����" << std::endl;
    print_vector(vec);

    //itr �� vec[2]�� ����Ų��
    std::vector<int>::iterator itr = vec.begin() + 2;

    //vec[2]�� ���� 50���� �ٲ۴�
    *itr = 50;

    std::cout << "�ѤѤѤѤѤѤѤ�" << std::endl;
    print_vector(vec);

    //��� �ݺ��ڰ� ����Ű�� ���� �ٲ� �� ����
    std::vector<int>::const_iterator citr = vec.cbegin() + 2;
    *citr = 30;
}*/

//���ݺ���(reverse iterator)
//�ݺ��ڿ� �Ȱ����� ���� �ڿ������� ������ �Ųٷ� ���� Ư¡
/*#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //��ü ���� ���
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

    std::cout << "�ʱ� vec ����" << std::endl;
    print_vector(vec);

    std::cout << "������ vec ���" << std::endl;
    std::vector<int>::reverse_iterator r_itr = vec.rbegin();
    for (; r_itr != vec.rend(); r_itr++) {
        std::cout << *r_itr << std::endl;
    }
}*/

//���ݺ��� ��� ����(����)
//vector�� index�� ����ϴ� Ÿ���� ��ȣ ���� ����
//���� i�� 0�� �� i-- �� �ϰ� �ȴٸ� -1�� �ƴ�
//�ش� Ÿ�Կ��� ���� ū ������ �ȴ�
//���� for���� ������ �ݺ�

//��������� ������ ���Ҹ� �����ϰ� �ʹٸ� ���ݺ��ڸ� ���
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    //������ ���� ���
    for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}*/

//���� ��� for ��
/*#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    //range-based for ��
    // elem = vec[i]�� ���� ����
    for (int elem : vec) {
        std::cout << "���� : " << elem  << std::endl;
    }
    return 0;
}*/

//�����ϱ� ���ٴ� ���۷����� �ް� ���� ��
/*
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    //��ü ���� ���
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
    //��ü ���͸� ����ϱ�
    //���� elem�� vec�� ���ҵ��� ��� ���۷����� ����
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
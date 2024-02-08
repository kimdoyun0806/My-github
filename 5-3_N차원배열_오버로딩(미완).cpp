#include <iostream>
#pragma warning (disable:4996)

//N���� �迭 ����
/*int main() {
    int** arr;
    arr = new int* [x1];
    for (int i = 0; i < x1; i++) 
        arr[i] new int[x2];
}*/

//N���� �迭 ����ü ����
/*struct Address {
    int level;
    void* next;
};*/

//N���� Array �迭�� Ŭ���� ����
namespace MyArray {
    class Array;
    class Int;

    class Array {
        friend
    };
    class Array {
        const int dim; // �� ���� �迭����
        int* size; // size[0] * size[1] * ... * size[dim-1]¥�� �迭

        struct Address {
            int level;
            //�� �������� ����(dim-1)�� �������� �迭�� ����Ű��, �� ��
            //�������������� ���� Address �迭�� ����Ų��.
            void* next;
        };
        Address* top; //����� ������ top ����

    public:
        Array(int dim, int* array_size) : dim(dim) {
            size = new int[dim];
            for (int i = 0; i < dim; i++) size[i] = array_size[i];
            top = new Address;
            top->level = 0;
            initialize_address(top);
        }

        Array(const Array& arr) : dim(arr.dim) {
            size = new int[dim];
            for (int i = 0; i < dim; i++) size[i] = arr.size[i];
            top = new Address;
            top->level = 0;
            initialize_address(top);

            //���빰 ����
            copy_address(top, arr.top);
        }
        //dst,src = current
        void copy_address(Address* dst, Address* src) {
            if (dst->level == dim - 1) {
                for (int i = 0; i < size[dst->level]; i++)
                    static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
                return;
            }
            for (int i = 0; i != size[dst->level]; i++) {
                Address* new_dst = static_cast<Address*>(dst->next) + i;
                Address* new_src = static_cast<Address*>(src->next) + i;
                copy_address(new_dst, new_src);
            }
        }
        ~Array() {
            delete_address(top);
            delete[] size;
        }

        //address�� �ʱ�ȭ�ϴ� �Լ�. ��� ȣ��� �����Ǿ� �ִ�.
        void initialize_address(Address* current) {
            //current�� NULL�϶� ���������� ó��
            if (!current) return;
            if (current->level == dim - 1) { //���� �� ��° ���� ���� ����
                //next���� Address�迭�� �ƴ� int �迭�� �����ּҰ� ���� �ȴ�.
                current->next = new int[size[current->level]];
                return;
            }
            //ex) arr[3][4][5]��� current�� 0�����̸�
            //next�� ����� �迭�� ũ��� 3, 1������ 4,
            //2�����̸� 5�� �Ǵ� �Ͱ� ���� ��ġ
            current->next = new Address[size[current->level]];
            for (int i = 0; i != size[current->level]; i++) {
                //���� �ܰ�� �Ѿ�� ����
                //current->next �� ���� �ּҷ� �ϴ� Address �迭��
                //i ��° ���Ҹ� ����Ű�� ������
                (static_cast<Address*>(current->next) + i)->level = current->level + 1;
                initialize_address(static_cast<Address*>(current->next) + i);
            }
        }
        void delete_address(Address* current) {
            if (!current) return;
            for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
                delete_address(static_cast<Address*>(current->next) + i);
            }
            if (current->level == dim - 1) {
                delete[] static_cast<int*>(current->next);
            }
            delete[] static_cast<Address*>(current->next);
        }

        };
    };
class Int {
    void* data;

    //Int�� �� ������ '���� int ����'�� �����ϴ� ��ü����
    // ���Ҹ� ������ ������ �߰� �������� level ������ �ݵ�� �����ؾ� ��
    int level;
    Array* array;
};
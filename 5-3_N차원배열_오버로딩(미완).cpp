#include <iostream>
#pragma warning (disable:4996)

//N차원 배열 예시
/*int main() {
    int** arr;
    arr = new int* [x1];
    for (int i = 0; i < x1; i++) 
        arr[i] new int[x2];
}*/

//N차원 배열 구조체 예시
/*struct Address {
    int level;
    void* next;
};*/

//N차원 Array 배열의 클래스 설계
namespace MyArray {
    class Array;
    class Int;

    class Array {
        friend
    };
    class Array {
        const int dim; // 몇 차원 배열인지
        int* size; // size[0] * size[1] * ... * size[dim-1]짜리 배열

        struct Address {
            int level;
            //맨 마지막의 레벨(dim-1)은 데이터의 배열을 가리키고, 그 위
            //상위레벨에서는 다음 Address 배열을 가리킨다.
            void* next;
        };
        Address* top; //상단의 시작점 top 정의

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

            //내용물 복사
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

        //address를 초기화하는 함수. 재귀 호출로 구성되어 있다.
        void initialize_address(Address* current) {
            //current가 NULL일때 예외적으로 처리
            if (!current) return;
            if (current->level == dim - 1) { //강의 두 번째 질문 종료 조건
                //next에는 Address배열이 아닌 int 배열의 시작주소가 들어가게 된다.
                current->next = new int[size[current->level]];
                return;
            }
            //ex) arr[3][4][5]경우 current가 0레벨이면
            //next에 만드는 배열의 크기는 3, 1레벨은 4,
            //2레벨이면 5가 되는 것과 같은 이치
            current->next = new Address[size[current->level]];
            for (int i = 0; i != size[current->level]; i++) {
                //다음 단계로 넘어가는 과정
                //current->next 를 시작 주소로 하는 Address 배열의
                //i 번째 원소를 가리키는 포인터
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

    //Int가 맨 마지막 '실제 int 정보'를 포함하는 객체인지
    // 원소를 참소해 나가는 중간 과정인지 level 정보는 반드시 포함해야 함
    int level;
    Array* array;
};
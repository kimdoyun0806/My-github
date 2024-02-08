#include <iostream> 

//new �� delete �� ���
/*int main() {
    int* p = new int;//int ũ���� ������ �Ҵ��Ͽ� �� �ּҰ��� p �� �������
    *p = 10;
    std::cout << *p << std::endl;

    delete p;
    return 0;
}*/

/*int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int* list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list;
    return 0;
}*/

typedef struct Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal) {
    std::cout << "������ �̸� : ";
    std::cin >> animal->name;
    std::cout << "������ ���� : ";
    std::cin >> animal->age;
    
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal* animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal* animal) {
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal* animal) {
    std::cout << animal->name << "�� ����" << std::endl;
    std::cout << "ü�� : " << animal->health << std::endl;
    std::cout << "��θ� : " << animal->food << std::endl;
    std::cout << "û�� : " << animal->clean << std::endl;
}

int main() {
    Animal* list[10];
    int animal_num = 0;

    for (;;) {
        std::cout << "1. ���� �߰��ϱ� " << std::endl;
        std::cout << "2. ��� " << std::endl;
        std::cout << "3. ���� ����" << std::endl;

        int input;
        std::cin >> input;
        switch (input) {
            int play_with;
        case 1:
            list[animal_num] = new Animal;
            create_animal(list[animal_num]);
            animal_num++;
            break;
        case 2:
            std::cout << "������ ���? : ";
            std::cin >> play_with;

            if (play_with < animal_num)
                play(list[play_with]);
            break;

        case 3:
            std::cout << "������ ����? : ";
            std::cin >> play_with;
            if (play_with < animal_num)
                show_stat(list[play_with]);
            break;
        }
        for (int i = 0; i != animal_num; i++) {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}
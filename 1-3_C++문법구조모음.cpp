#include<iostream>

//for��
/*int main() {
    int i;

    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}*/
//for�� ��
/*int main() {
    int i, sum = 0;
    for (i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "���� : " << sum << std::endl;
    return 0;
}*/

//while��
/*int main() {
    int i = 1, sum = 0;
    while (i <= 10) {
        sum += i;
        i++;
    }
    std::cout << "���� : " << sum << std::endl;
    return 0;
}*/
/*int main() {
    int lucky_number = 3;
    std::cout << "��� ��" << std::endl;

    int user_input;

    while (1) {
        std::cout << "�Է� : ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "����" << std::endl;
            break;
        }
        else {
            std::cout << "�ٽ� �Է�" << std::endl;
        }
    }
    return 0;
}*/

//switch�� �̿�
using std::cout;
using std::cin;
using std::endl;

int main() {
    int user_input;
    cout << "���� ���� ǥ��" << endl;
    cout << "1. �̸�" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����" << endl;
    cin >> user_input;

    switch (user_input) {
    case 1:
        cout << "Psi" << endl;
        break;
    case 2:
        cout << "25" << endl;
        break;
    case 3:
        cout << "����" << endl;
        break;
    default:
        cout << "nothing" << endl;
        break;
    }
    return 0;
}
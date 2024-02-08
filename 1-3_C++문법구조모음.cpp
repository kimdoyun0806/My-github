#include<iostream>

//for문
/*int main() {
    int i;

    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}*/
//for문 합
/*int main() {
    int i, sum = 0;
    for (i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "합은 : " << sum << std::endl;
    return 0;
}*/

//while문
/*int main() {
    int i = 1, sum = 0;
    while (i <= 10) {
        sum += i;
        i++;
    }
    std::cout << "합은 : " << sum << std::endl;
    return 0;
}*/
/*int main() {
    int lucky_number = 3;
    std::cout << "비밀 수" << std::endl;

    int user_input;

    while (1) {
        std::cout << "입력 : ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "정답" << std::endl;
            break;
        }
        else {
            std::cout << "다시 입력" << std::endl;
        }
    }
    return 0;
}*/

//switch문 이용
using std::cout;
using std::cin;
using std::endl;

int main() {
    int user_input;
    cout << "나의 정보 표시" << endl;
    cout << "1. 이름" << endl;
    cout << "2. 나이" << endl;
    cout << "3. 성별" << endl;
    cin >> user_input;

    switch (user_input) {
    case 1:
        cout << "Psi" << endl;
        break;
    case 2:
        cout << "25" << endl;
        break;
    case 3:
        cout << "남자" << endl;
        break;
    default:
        cout << "nothing" << endl;
        break;
    }
    return 0;
}
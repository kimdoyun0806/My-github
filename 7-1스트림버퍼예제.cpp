#include <iostream>
#pragma warning (disable:4996)

int main() {
    std::string s;
    std::cin >> s;

    //위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다
    //이 때는 움직이지 않음
    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail())std::cout << "failed";
    std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;
}
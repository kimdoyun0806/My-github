#include <iostream>
#pragma warning (disable:4996)

int main() {
    std::string s;
    std::cin >> s;

    //��ġ �����ڸ� �� ĭ �ű��, �� ���� ���ڸ� ���ĺ���
    //�� ���� �������� ����
    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail())std::cout << "failed";
    std::cout << "�� ��° �ܾ� �� �ձ��� : " << peek << std::endl;
    std::cin >> s;
    std::cout << "�ٽ� ������ : " << s << std::endl;
}
#include <iostream>

//���ڵ��� ������ ���ĺ����� ���� ���ڿ�


















// char_traits �� ��� �Լ����� static �Լ� �Դϴ�.
/*#include <cctype>

#include <string>
struct my_char_traits : public std::char_traits<char> {
    static int get_real_rank(char c) {
        // ���ڸ� ������ ��û ����Ʈ����.
        if (isdigit(c)) {
            return c + 256;
        }
        return c;
    }

    static bool lt(char c1, char c2) {
        return get_real_rank(c1) < get_real_rank(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n) {
        while (n-- != 0) {
            if (get_real_rank(*s1) < get_real_rank(*s2)) {
                return -1;
            }
            if (get_real_rank(*s1) > get_real_rank(*s2)) {
                return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
};

int main() {
    std::basic_string<char, my_char_traits> my_s1 = "1a";
    std::basic_string<char, my_char_traits> my_s2 = "a1";

    std::cout << "������ �켱������ �� ���� ���ڿ� : " << std::boolalpha
        << (my_s1 < my_s2) << std::endl;

    std::string s1 = "1a";
    std::string s2 = "a1";

    std::cout << "�Ϲ� ���ڿ� : " << std::boolalpha << (s1 < s2) << std::endl;
}*/

//ª�� ���ڿ� ����ȭ(SSO)

//basing_string�� �����ڵ��� ª�� ���� ���ڿ��� ��� ���� ���� �����͸� ����
//�޸𸮸� �Ҵ��ϴ� ��ſ� �׳� ��ü ��ü�� ����
//�̸� ª�� ���ڿ� ����ȭ(SSO)�̶�� �θ���

#include <string>

//�̿� ���� new�� ���� �Լ��� �����ϸ� ��� new �����ڸ� �����ε� �ع�����
//(� Ŭ������ ��� �Լ��� �����ϸ� �ش� Ŭ������ new�� �����ε���)
void* operator new(std::size_t count) {
    std::cout << count << "bytes �Ҵ�" << std::endl;
    return malloc(count);
}
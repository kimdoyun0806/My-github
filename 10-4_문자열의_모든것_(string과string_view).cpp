#include <iostream>

//숫자들의 순위가 알파벳보다 낮은 문자열


















// char_traits 의 모든 함수들은 static 함수 입니다.
/*#include <cctype>

#include <string>
struct my_char_traits : public std::char_traits<char> {
    static int get_real_rank(char c) {
        // 숫자면 순위를 엄청 떨어트린다.
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

    std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
        << (my_s1 < my_s2) << std::endl;

    std::string s1 = "1a";
    std::string s2 = "a1";

    std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;
}*/

//짧은 문자열 최적화(SSO)

//basing_string의 제작자들은 짧은 길이 문자열의 경우 따로 문자 데이터를 위한
//메모리를 할당하는 대신에 그냥 객체 자체에 저장
//이를 짧은 문자열 최적화(SSO)이라고 부른다

#include <string>

//이와 같이 new를 전역 함수로 정의하면 모든 new 연산자를 오버로딩 해버린다
//(어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new만 오버로딩됨)
void* operator new(std::size_t count) {
    std::cout << count << "bytes 할당" << std::endl;
    return malloc(count);
}
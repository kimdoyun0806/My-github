#include <iostream>
#include <string>
#include <cstring>
#pragma warning (disable:4996)

//가변 길이 템플릿
/*template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

//typename... -> 템플릿 파라미터 팩
template <typename T, typename... Types>
void print(T arg, Types... args) {
    std::cout << arg << ", ";
    print(args...);
}

int main() {
    print(1, 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);
}*/

/*size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    // 먼저 합쳐질 문자열의 총 길이를 구한다.
    size_t total_size = GetStringSize(s, strs...);

    // reserve 를 통해 미리 공간을 할당해 놓는다.
    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;
    AppendToString(&concat_str, strs...);

    return concat_str;
}

int main() {
    // std::string 과 const char* 을 혼합해서 사용 가능하다.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
        " ", std::string("sentence"));
}*/

//재귀 호출 종료를 위한 베이스 케이스
int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums) {
    return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums) {
    return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main() {
    // (1+4+2+3+10)/5
    std::cout << average(1, 4, 2, 3, 10) << std::endl;
}
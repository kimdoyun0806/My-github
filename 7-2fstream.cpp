#include <fstream>
#include <iostream>
#include <string>
#pragma warning (disable:4996)

//ifstream 예제
//C언어에서는 파일 입출력을 한 후에 fclose를 해주어야 헸지만
//ifstream 객체의 소멸자에서 자동적으로 close를 해준다.
/*int main() {
    //파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if(in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    //새로운 파일에서 같은 객체가 입력을 받기 위해서는
    //기존 파일 스트림과의 연결을 종료해야 하므로
    //close를 직접 해주어야 함
    in.close();
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    return 0;
}*/

//이진수로 읽기
/*int main() {
    //파일 읽기 준비
    std::ifstream in("test.txt", std::ios::binary);
    std::string s;

    int x;
    if (in.is_open()) {
        in.read((char*)(&x), 4);
        std::cout << std::hex << x << std::endl;
    } else{
        std::cout << "file is error" << std::endl;
    }
    return 0;
}*/

//파일 전체를 한 번에 읽기
/*int main() {
    //파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        //위치 지정자를 파일 끝으로 옮긴다
        in.seekg(0, std::ios::end); //파일의 끝에서 0만큼 떨어지 것

        //그리고 그 위치를 읽는다. (파일의 크기)
        int size = in.tellg(); //tellg함수는 위치 지정자의 위치를 반환

        //그 크기의 문자열을 할당한다.
        s.resize(size);

        //위치 지정자를 다시 파일 맨 앞으로 옮긴다
        in.seekg(0, std::ios::beg);

        //파일 전체 내용을 읽어서 문자열에 저장
        in.read(&s[0], size);
        std::cout << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    return 0;
}*/

//파일 전체를 한 줄씩 읽기
/*int main() {
    //파일 읽기 준비
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "file is error " << std::endl;
        return 0;
    }

    while (in) {
        //getline 함수는 파일에서 개행문자 \n이 나올 때
        //까지 최대 지정한 크기 -1만큼 읽게된다.
        //(마지막 문자로 널 종료 문자를 넣어줘야 하기 때문)
        //아래의 경우 buf에 최대 99글자 까지 입력 받음
        //in.getline(buf,100,'.')는 해당 문자가 나올 때 까지 입력
        in.getline(buf, 100);
        std::cout << buf << std::endl;
    }
    return 0;
}*/

//getline 함수는 개행문자(혹은 지정한 문자)가 나오기 전에
//지정한 버퍼의 크기가 다 차게 된다면 failbit를 키게 되므로
//버퍼의 크기를 작게 만든다면 정상적으로 데이터를 받을 수 없다
//따라서 이와 같은 한계점을 극복하기 위해 std::string에서 getline함수를 제공하고 있다

//std::string 에 정의된 getline 사용
/*int main() {
    //파일 읽기 준비
    std::ifstream in("test.txt");
    if (!in.is_open()) {
        std::cout << "file is error " << std::endl;
        return 0;
    }
    std::string s;
    while (in) {
        getline(in, s);
        std::cout << s << std::endl;
    }
    return 0;
}*/

//파일에 쓰기와 app을 이용한 덧붙이기
/*int main() {
    //파일 쓰기 준비
    std::ofstream out("test.txt",std::ios::app);

    std::string s;
    if (out.is_open()) {
        out << "텍스트 덧붙이기";
    }
    return 0;
}*/

// ate와 app의 차이
/*int main() {
    //두 파일에는 모두 abc 라고 써져 있다
    std::ofstream out("test.txt",std::ios::app);
    std::ofstream out2("test2.txt", std::ios::ate);

    out.seekp(3, std::ios::beg);
    out2.seekp(3, std::ios::beg);

    out << "추가";
    out2 << "추가";
    return 0;
}*/

//std::ofstream 연산자 오버로딩
/*class Human {
    std::string name;
    int age;
public:
    Human(const std::string& name, int age) : name(name), age(age) {}
    std::string get_info() {
        //to_string : 숫자 타입의 데이터를 안전하게 스트링 타입으로 변경하는 함수
        return "Name :: " + name + "/ Age" + std::to_string(age);
    }
    friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream & o, Human & h) {
    o << h.get_info();
    return o;
}

int main() {
    //파일 쓰기 준비
    std::ofstream out("test.txt");

    Human h("김도윤", 25);
    out << h << std::endl;
    return 0;
}*/

//문자열 스트림(std::istringstream)
/*#include <sstream>
int main() {
    //문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치
    std::istringstream ss("123");
    int x;
    ss >> x;
    std::cout << "입력 받은 데이터 :: " << x << std::endl;
    return 0;
}*/
//이를 통해 atoi와 같은 함수를 사용할 필요 없이
//간편하게 문자열에서 숫자로 변환하는 함수를 만들 수 있다
/*#include <sstream>
double to_number(std::string s) {
    std::istringstream ss(s);
    double x;
    ss >> x;
    return x;
}
int main() {
    std::cout << "변환 :: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

    return 0;
}*/

//거꾸로 숫자에서 문자열로 데이터를 출력할 수 있는 
//std::ostringstream도 있다
//std::ostringstream ss;
//ss << x;
//return ss.str();

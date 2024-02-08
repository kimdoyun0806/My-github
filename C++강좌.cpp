/*#include <iostream>

namespace {
    //이 함수는 이 파일 안에서만 사용가능
    //static int OnlyInThisFile() 과 동일
    int OnlyInThisFile() {}

    // 이 변수 역시 static int x 와 동일
    int only_in_this_file = 0;
}//namespace

int main() {
    OnlyInThisFile();
    only_in_this_file = 3;
}
*/

#include<iostream>
int main() {
    std::cout << "hi" << std::endl
        << "my name is"
        << "Psi" << std::endl;
}

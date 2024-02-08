#include <fstream>
#include <iostream>
#include <string>
#pragma warning (disable:4996)

//ifstream ����
//C������ ���� ������� �� �Ŀ� fclose�� ���־�� �g����
//ifstream ��ü�� �Ҹ��ڿ��� �ڵ������� close�� ���ش�.
/*int main() {
    //���� �б� �غ�
    std::ifstream in("test.txt");
    std::string s;

    if(in.is_open()) {
        in >> s;
        std::cout << "�Է� ���� ���ڿ� :: " << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    //���ο� ���Ͽ��� ���� ��ü�� �Է��� �ޱ� ���ؼ���
    //���� ���� ��Ʈ������ ������ �����ؾ� �ϹǷ�
    //close�� ���� ���־�� ��
    in.close();
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "�Է� ���� ���ڿ� :: " << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    return 0;
}*/

//�������� �б�
/*int main() {
    //���� �б� �غ�
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

//���� ��ü�� �� ���� �б�
/*int main() {
    //���� �б� �غ�
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        //��ġ �����ڸ� ���� ������ �ű��
        in.seekg(0, std::ios::end); //������ ������ 0��ŭ ������ ��

        //�׸��� �� ��ġ�� �д´�. (������ ũ��)
        int size = in.tellg(); //tellg�Լ��� ��ġ �������� ��ġ�� ��ȯ

        //�� ũ���� ���ڿ��� �Ҵ��Ѵ�.
        s.resize(size);

        //��ġ �����ڸ� �ٽ� ���� �� ������ �ű��
        in.seekg(0, std::ios::beg);

        //���� ��ü ������ �о ���ڿ��� ����
        in.read(&s[0], size);
        std::cout << s << std::endl;
    }
    else {
        std::cout << "file is error" << std::endl;
    }
    return 0;
}*/

//���� ��ü�� �� �پ� �б�
/*int main() {
    //���� �б� �غ�
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "file is error " << std::endl;
        return 0;
    }

    while (in) {
        //getline �Լ��� ���Ͽ��� ���๮�� \n�� ���� ��
        //���� �ִ� ������ ũ�� -1��ŭ �аԵȴ�.
        //(������ ���ڷ� �� ���� ���ڸ� �־���� �ϱ� ����)
        //�Ʒ��� ��� buf�� �ִ� 99���� ���� �Է� ����
        //in.getline(buf,100,'.')�� �ش� ���ڰ� ���� �� ���� �Է�
        in.getline(buf, 100);
        std::cout << buf << std::endl;
    }
    return 0;
}*/

//getline �Լ��� ���๮��(Ȥ�� ������ ����)�� ������ ����
//������ ������ ũ�Ⱑ �� ���� �ȴٸ� failbit�� Ű�� �ǹǷ�
//������ ũ�⸦ �۰� ����ٸ� ���������� �����͸� ���� �� ����
//���� �̿� ���� �Ѱ����� �غ��ϱ� ���� std::string���� getline�Լ��� �����ϰ� �ִ�

//std::string �� ���ǵ� getline ���
/*int main() {
    //���� �б� �غ�
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

//���Ͽ� ����� app�� �̿��� �����̱�
/*int main() {
    //���� ���� �غ�
    std::ofstream out("test.txt",std::ios::app);

    std::string s;
    if (out.is_open()) {
        out << "�ؽ�Ʈ �����̱�";
    }
    return 0;
}*/

// ate�� app�� ����
/*int main() {
    //�� ���Ͽ��� ��� abc ��� ���� �ִ�
    std::ofstream out("test.txt",std::ios::app);
    std::ofstream out2("test2.txt", std::ios::ate);

    out.seekp(3, std::ios::beg);
    out2.seekp(3, std::ios::beg);

    out << "�߰�";
    out2 << "�߰�";
    return 0;
}*/

//std::ofstream ������ �����ε�
/*class Human {
    std::string name;
    int age;
public:
    Human(const std::string& name, int age) : name(name), age(age) {}
    std::string get_info() {
        //to_string : ���� Ÿ���� �����͸� �����ϰ� ��Ʈ�� Ÿ������ �����ϴ� �Լ�
        return "Name :: " + name + "/ Age" + std::to_string(age);
    }
    friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream & o, Human & h) {
    o << h.get_info();
    return o;
}

int main() {
    //���� ���� �غ�
    std::ofstream out("test.txt");

    Human h("�赵��", 25);
    out << h << std::endl;
    return 0;
}*/

//���ڿ� ��Ʈ��(std::istringstream)
/*#include <sstream>
int main() {
    //���ڿ��� �ϳ��� ��Ʈ���̶� �����ϰ� ���ִ� ����ȭ ��ġ
    std::istringstream ss("123");
    int x;
    ss >> x;
    std::cout << "�Է� ���� ������ :: " << x << std::endl;
    return 0;
}*/
//�̸� ���� atoi�� ���� �Լ��� ����� �ʿ� ����
//�����ϰ� ���ڿ����� ���ڷ� ��ȯ�ϴ� �Լ��� ���� �� �ִ�
/*#include <sstream>
double to_number(std::string s) {
    std::istringstream ss(s);
    double x;
    ss >> x;
    return x;
}
int main() {
    std::cout << "��ȯ :: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

    return 0;
}*/

//�Ųٷ� ���ڿ��� ���ڿ��� �����͸� ����� �� �ִ� 
//std::ostringstream�� �ִ�
//std::ostringstream ss;
//ss << x;
//return ss.str();

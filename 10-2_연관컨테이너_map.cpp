#include<iostream>
#include<map>
#include<string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    //���� ��� ���ҵ��� ���
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    //���� insert �Լ��� pair ��ü�� ���ڷ� �޴´�
    pitcher_list.insert(std::pair<std::string, double>("�ڼ���", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("��Ŀ", 2.93));

    pitcher_list.insert(std::pair<std::string, double>("�Ǿ���", 2.95));

    //Ÿ���� �������� �ʾƵ� ������ std::make_pair �Լ���
    //std::pair ��ü�� ���� �� �ִ�
    pitcher_list.insert(std::make_pair("������", 3.04));
    pitcher_list.insert(std::make_pair("�����", 3.05));
    pitcher_list.insert(std::make_pair("����", 3.09));

    //Ȥ�� insert�� �Ⱦ����� []�� �ٷ�
    //���Ҹ� �߰��� �� �ִ�
    pitcher_list["����Ʈ"] = 3.56;
    pitcher_list["������"] = 3.76;
    pitcher_list["�̸�"] = 3.90;

    print_map(pitcher_list);

    std::cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << std::endl;

}
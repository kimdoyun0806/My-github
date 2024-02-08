#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

//생성자의 초기화 리스트
/*class Marine {
    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

public:
    Marine();  //기본 생성자
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack(); // 데미지를 리턴
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
    :coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3,10);
    Marine marine2(3, 5,10);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}*/

// static 멤버 변수, 함수의 사용
/*class Marine {
    static int total_marine_num;
    const static int i = 0;
    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << " 전체 마린 수 :" << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}


Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine ***" << std::endl;
    std::cout << " Location : (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_total_marine();
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_total_marine();

    Marine marine2(3, 5, 10);
    marine2.show_total_marine();

    create_marine();

    std::cout << std::endl << "마린 1이 마린 2를 공격" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

}*/

//자기 자신을 가리키는 포인터 this, 상수 멤버 함수
class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack() const;
    Marine& be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
    coord_y(y),
    hp(50),

    default_damage(5),
    is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;

    return *this;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
    std::cout << "현재 총 마린 수  :" << total_marine_num << std::endl;
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1이 마린 2를 두 번 공격" << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}

// 레퍼런스를 리턴하는 함수
/*
class A {
    int x;

public:
    A(int c) : x(c) {}

    int& access_x() { return x; }
    int get_x() { return x; }
    void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    int& c = a.access_x();
    c = 4;
    a.show_x();

    int d = a.access_x();
    d = 3;
    a.show_x();

    // 아래는 오류
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();
    f = 1;
    a.show_x();
}*/
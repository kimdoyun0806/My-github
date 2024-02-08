#include <iostream> 
#include <string.h>
#pragma warning (disable:4996)

/*class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;
  char* name;            // 마린 이름

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y, const char* marine_name);
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  ~Marine();

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() {
    return damage;
}
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << "*** Marine : " << name  << " ***"<< std::endl;
    std::cout << "Location : ( " << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
}
Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    if (name != NULL) {
        delete[] name;
    }
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine (2, 3, "Marine 1");
    marines[1] = new Marine (3, 5, "Marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격" << std::endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}*/

//생성자 소멸자 호출
/*class Test {
    char c;

public:
    Test(char _c) {
        c = _c;
        std::cout << "생성자 호출 " << c << std::endl;
    }
    ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};

void simple_function() {
    Test b('b');
}
int main() {
    Test a('a');
    simple_function();
}*/
//복사 생성자, 디폴트 복사 생성자의 한계, 복사 생성자의 중요성
class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char* name;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char* cannon_name);
    Photon_Cannon(const Photon_Cannon& pc);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출 " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
    // 0 이 아닌 값은 if 문에서 true 처리
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name !=0) 과 동일한 의미를 가질 수 있다.
    if (name) delete[] name;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << "Location : (" << coord_x << "," << coord_y << ")"
        << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    //Photon_Cannon pc2(pc1);
    Photon_Cannon pc2 = pc1;
    Photon_Cannon pc3 = pc2;// = Photon_Cannon pc3(pc2);

    pc1.show_status();
    pc2.show_status();
}


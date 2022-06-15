#include <iostream>

// 배열
// type 이름[갯수]

struct StatInfo
{
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xCCCCCCCC;
};

int main()
{
    // 배열의 크기는 상수여야함 (VC 컴파일러 기준)
    const int monstersCount = 10;
    StatInfo monsters[monstersCount];

    // 여태껏 변수들의 [이름]은 바구니의 이름이였음
    int a = 10;
    int b = a;

    //그런데 배열은 [이름] 조금 다르게 동작한다 
    

    // 배열의 이름은 곧 배열의 시작 주소
    // 정확히는 시작 위치를 가리키는 type* 포인터
    
    auto WhoAmI = monsters;

    // 주소[(100,10,1)] StatInfo[]StatInfo[] StatInfo[]StatInfo[]
    // monster_0[]
    StatInfo* monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    //포인터의 덧셈! Statinfo 타입 바구니 한개씩 이동
    StatInfo* monster_1 = monsters + 1;
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // 포인터와 참조는 자유자재로 변환 가능하다
    StatInfo& monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // 주의 이거는 완전 다른 의미다
    StatInfo temp;
    temp = *(monsters + 2);
    temp.hp = 400;
    temp.attack = 40;
    temp.defence = 4;

    // 이름을 조금 더 자동화 한다!
    for (int i = 0; i < 10; i++)
    {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }

    // 근데 *(monsters + i) 너무 불편하고 가독성이 떨어진다... 더 편한 방법?!
    // 인덱스!
    // 배열 0번부터 시작, n번째 인덱스에 해당하는 데이터에 저근하려면 배열이름[n]
    // *(monsetrs + i) = monsters[i]
    monsters[0].hp = 100;
    monsters[0].attack = 10;
    monsters[0].defence = 1;

    for (int i = 0; i < 10; i++)
    {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = 1 * (i + 1);
    }

    // 배열 초기화 문법 몇가지
    int numbers[5] = {}; //다 0으로 밀어 버린다
    int numbers1[10] = { 1,2,3,4,5 }; // 설정한 애들은 설정한 값들로 나머지값들은 0으로 초기화
    int numbers2[] = {1,2,3,4,5,6,7,8,9,10}; // 데이터 갯수만큼의 크기에 해당하는 배열로 만들어준다

    return 0;
}


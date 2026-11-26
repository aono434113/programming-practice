#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 7
#define view_width 25
#define map_width 250
#define total_jelly 50

/*스토리: 할머니가 젤리 50개를 든 바구니를 들고 집으로 돌아가시는 길에
그 젤리를 바닥에 모두 흘리셨다. 한 아이와 고양이가 바닥에 한 줄로
떨어져있는 젤리들을 보고 그 끝에 무엇이 있을지 궁금해하며 젤리를 모두 줍고자 한다.
아이와 고양이가 장애물을 피해 젤리를 모두 주워 완주하도록 도와주자*/

//열거형
typedef enum {
	empty = 0, ground, obstacle, jelly
}ObjectType;

//캐릭터(player, cat)의 좌표, 연결하는 포인터
typedef struct CharacterNode {
	int x; //가로
	int y; //세로
	struct CharacterNode* link;//구조체 내부에서 자기 자신을 가르킴
}CharacterNode;

typedef struct {
	int jellycount;
	int gameover;
}Game;

//함수 원형 선언
//...

int main() {

	//리스트 생성 (메모리 할당)
	CharacterNode* player = (CharacterNode*)malloc(sizeof(CharacterNode));
	CharacterNode* cat = (CharacterNode*)malloc(sizeof(CharacterNode));

	//player, cat 초기값 설정, player -> cat -> NULL
	player->x = 2; //player 가로 위치 설정
	player->y = HEIGHT - 2; //player 세로 위치 설정
	player->link = cat; //player 뒤에 고양이 연결

	cat->x = 1;
	cat->y = HEIGHT - 2;
	cat->link = NULL; //cat 뒤에는 없음

	//...

	//동적 할당 메모리 해제
	free(cat); //player를 먼저 해제하면 cat이 갈 길을 잃으니까 cat먼저함
	free(player);


	return 0;
}
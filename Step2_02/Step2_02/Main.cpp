#include "Headers.h"


//** 열거형 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** 상수, 정수


//** 전역변수
SCENEID eSCENEID = SCENEID_LOGO;

//** 함수 전방선언
void SetScene(Object* _pPlayer);
char* SetName();
Object* CreateObject();

void InitPlayter(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer);
void PlayerRender(Object* _pPlayer);



int main(void)
{

	//맨앞의 숫자는 부호를 나타낸다.
	//음의 정수 = 1 양의 정수 = 0

	// 00000001 = 1
	// 00000010 = 2
	// 00000100 = 4
	// 00001000 = 8
	// 00010000 = 16
	// 00100000 = 32
	// 01000000 = 64


	/*
	const char STATE_UP		= 1;
	const char STATE_DOWN	= 2;
	const char STATE_LEFT	= 4;
	const char STATE_RIGHT	= 8;
	const char STATE_ATT	= 16;
	const char STATE_DIE	= 32;

	char c = 3;


	if (c& STATE_UP)
	{
		printf_s("STATE_UP\n");
	}

	if (c& STATE_DOWN)
	{
		printf_s("STATE_DOWN\n");
	}

	if (c& STATE_LEFT)
	{
		printf_s("STATE_LEFT\n");
	}

	if (c& STATE_RIGHT)
	{
		printf_s("STATE_RIGHT\n");
	}
*/

	Object* pPlayer = CreateObject();
	InitPlayter(pPlayer);

	while(true)
	{ 
		system("cls");
		SetScene(pPlayer);		
	}

	system("pause");

	return 0;

}





void SetScene(Object* _pPlayer)
{

	switch (eSCENEID)
	{
	case SCENEID_LOGO:

		printf_s("SCENEID_LOGO\n");
		system("pause");

		eSCENEID = SCENEID_MENU;
		break;

	case SCENEID_MENU:

		printf_s("SCENEID_MENU\n");
		system("pause");

		eSCENEID = SCENEID_STAGE;
		break;

	case SCENEID_STAGE:
		PlayerProgress(_pPlayer);
		PlayerRender(_pPlayer);


		break;

	case SCENEID_STORE:

		break;

	case SCENEID_OPTION:

		break;

	case SCENEID_EXIT:

		break;

	}



}


char* SetName()
{
	//** 문자열 입력
	char str[128] = "";



	printf_s("당신은 누구인가요 ?\n");
	Sleep(1000);
	printf_s("입력 : ");
	scanf_s("%s", str, 128);


	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;
}

Object* CreateObject()
{
	Object* pObj = (Object*)malloc(sizeof(Object));

	return pObj;
}

void InitPlayter(Object* _pPlayer)
{


	_pPlayer->pName = SetName();
	_pPlayer->iAtt = 10;
	_pPlayer->iDef = 8;
	_pPlayer->iHP = 20;
	_pPlayer->iMP = 5;


}


void PlayerProgress(Object* _pPlayer)
{
	_pPlayer->iAtt++;
	_pPlayer->iDef++;
	_pPlayer->iHP++;
	_pPlayer->iMP++;

}



void PlayerRender(Object* _pPlayer)
{
	printf_s("닉네임 : %s\n", _pPlayer->pName);
	printf_s("공격력 : %d\n", _pPlayer->iAtt);
	printf_s("방어력 : %d\n", _pPlayer->iDef);
	printf_s("체력 : %d\n", _pPlayer->iHP);
	printf_s("마력 : %d\n", _pPlayer->iMP);
}
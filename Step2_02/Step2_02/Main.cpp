#include "Headers.h"


//** 열거형 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** 상수, 정수


//** 전역변수
SCENEID eSCENEID = SCENEID_LOGO;

//** 함수 전방선언
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _Bullet[]);
char* SetName();
Object* CreateObject();

void InitPlayter(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer);
void PlayerRender(Object* _pPlayer);


void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);

void InitBullet(Object* _Bullet);
void BulletProgress(Object* _Bullet[]);
void BulletRender(Object* _Bullet[]);

/*
 1개의 오브젝트에 3차원 공간에 필요한 세가지 위치값( 포지션), 크기값(스케일), 회전값  (로테이션)
*/

int main(void)
{


	Object* pPlayer = CreateObject();
	InitPlayter(pPlayer);

	Object* pMonster[MONSER_MAX];

	Object* Bullet[Bullet_MAX];

	for (int i = 0; i < MONSER_MAX; i++)
	{
		pMonster[i] = CreateObject();
		InitMonster(pMonster[i]);

	}


	for (int i = 0; i < Bullet_MAX; i++)
	{
		
		Bullet[i] = CreateObject();
		InitBullet(Bullet[i]);
	
	}




	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			SetScene(pPlayer, pMonster, Bullet);
										
		}
	}







	system("pause");

	return 0;

}





void SetScene(Object* _pPlayer, Object* _pMonster[],Object* _Bullet[])
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

		MonsterProgress(_pMonster);
		MonsterRender(_pMonster);


		BulletProgress(_Bullet);
		BulletRender(_Bullet);
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

	_pPlayer->TransPos.Position = Vector3(0.f, 0.f);
	_pPlayer->TransPos.Scale = Vector3(0.f, 0.f);

	_pPlayer->pName = SetName();
	_pPlayer->iAtt = 10;
	_pPlayer->iDef = 8;
	_pPlayer->iHP = 20;
	_pPlayer->iMP = 5;


}


void PlayerProgress(Object* _pPlayer)
{
	
		_pPlayer->TransPos.Position.x++;
		_pPlayer->TransPos.Position.y++;
		_pPlayer->TransPos.Scale.x++;
		_pPlayer->TransPos.Scale.y++;

		_pPlayer->iAtt++;
		_pPlayer->iDef++;
		_pPlayer->iHP++;
		_pPlayer->iMP++;

	

}



void PlayerRender(Object* _pPlayer)
{
	
	printf_s("Position x: %f\n", _pPlayer->TransPos.Position.x);
	printf_s("Position y: %f\n", _pPlayer->TransPos.Position.y);
	printf_s("Scale x: %f\n", _pPlayer->TransPos.Scale.x);
	printf_s("Scale y: %f\n", _pPlayer->TransPos.Scale.y);
	
	printf_s("닉네임 : %s\n", _pPlayer->pName);
	printf_s("공격력 : %d\n", _pPlayer->iAtt);
	printf_s("방어력 : %d\n", _pPlayer->iDef);
	printf_s("체력 : %d\n", _pPlayer->iHP);
	printf_s("마력 : %d\n", _pPlayer->iMP);
}



void InitMonster(Object* _pMonster)
{

	

		_pMonster->TransPos.Position = Vector3(0.f, 0.f);
		_pMonster->TransPos.Scale = Vector3(0.f, 0.f);
		_pMonster->pName = (char*)"Monster";
		_pMonster->iAtt = 10;
		_pMonster->iDef = 8;
		_pMonster->iHP = 20;
		_pMonster->iMP = 5;
	

}


void MonsterProgress(Object* _pMonster[])
{
	for (int i = 0; i < MONSER_MAX; i++)
	{

		_pMonster[i]->TransPos.Position.x++;
		_pMonster[i]->TransPos.Position.y++;
		_pMonster[i]->TransPos.Scale.x++;
		_pMonster[i]->TransPos.Scale.y++;

		_pMonster[i]->iAtt++;
		_pMonster[i]->iDef++;
		_pMonster[i]->iHP++;
		_pMonster[i]->iMP++;

	}
}

void MonsterRender(Object* _pMonster[])
{

	for (int i = 0; i < MONSER_MAX; i++)
	{

		printf_s("Position x: %f\n", _pMonster[i]->TransPos.Position.x);
		printf_s("Position y: %f\n", _pMonster[i]->TransPos.Position.y);
		printf_s("Scale x: %f\n", _pMonster[i]->TransPos.Scale.x);
		printf_s("Scale y: %f\n", _pMonster[i]->TransPos.Scale.y);

		printf_s("닉네임 : %s\n", _pMonster[i]->pName);
		printf_s("공격력 : %d\n", _pMonster[i]->iAtt);
		printf_s("방어력 : %d\n", _pMonster[i]->iDef);
		printf_s("체력 : %d\n", _pMonster[i]->iHP);
		printf_s("마력 : %d\n", _pMonster[i]->iMP);

	}

}


void InitBullet(Object* _Bullet)
{
	_Bullet->TransPos.Position = Vector3(0.f, 0.f);
	_Bullet->TransPos.Scale = Vector3(0.f, 0.f);
	_Bullet->pName = (char*)"Bullet";
	_Bullet->iAtt = 10;
	_Bullet->iDef = 8;
	_Bullet->iHP = 20;
	_Bullet->iMP = 5;
}

void BulletProgress(Object* _Bullet[])
{

	for (int i = 0; i < Bullet_MAX; i++)
	{

		_Bullet[i]->TransPos.Position.x++;
		_Bullet[i]->TransPos.Position.y++;
		_Bullet[i]->TransPos.Scale.x++;
		_Bullet[i]->TransPos.Scale.y++;

		_Bullet[i]->iAtt++;
		_Bullet[i]->iDef++;
		_Bullet[i]->iHP++;
		_Bullet[i]->iMP++;

	}
}

void BulletRender(Object* _Bullet[])
{

	for (int i = 0; i < Bullet_MAX; i++)
	{

		printf_s("Position x: %f\n", _Bullet[i]->TransPos.Position.x);
		printf_s("Position y: %f\n", _Bullet[i]->TransPos.Position.y);
		printf_s("Scale x: %f\n", _Bullet[i]->TransPos.Scale.x);
		printf_s("Scale y: %f\n", _Bullet[i]->TransPos.Scale.y);

		printf_s("닉네임 : %s\n", _Bullet[i]->pName);
		printf_s("공격력 : %d\n", _Bullet[i]->iAtt);
		printf_s("방어력 : %d\n", _Bullet[i]->iDef);
		printf_s("체력 : %d\n", _Bullet[i]->iHP);
		printf_s("마력 : %d\n", _Bullet[i]->iMP);

	}

}
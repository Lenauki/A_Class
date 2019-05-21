#include "Headers.h"

//** 열거형 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** 상수, 정수

//** 전역변수
SCENEID eSCENEID = SCENEID_STAGE;
DWORD dmMonsterTime = 0;

//** 함수 전방선언
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _Bullet[]);
char* SetName();
Object* CreateObject();

void InitPlayter(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer, Object* _Bullet[]);
void PlayerRender(Object* _pPlayer);


void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);
void CreateMonster(Object* _pMonster[]);

void InitBullet(Object* _Bullet);
void BulletProgress(Object* _Bullet[]);
void BulletRender(Object* _Bullet[]);
void CreateBullet(Object* _Bullet[], Object* _pPlayer);

void SetBulletDirection(Object* _Bullet, DWORD _dwDir);


void BackGroundRender();



void SetCurserPosition(int _ix, int _iy, char* _str);

DWORD InputKey();

/*
 1개의 오브젝트에 3차원 공간에 필요한 세가지 
 위치값( 포지션), 크기값(스케일), 회전값  (로테이션)
*/

int main(void)
{
	//** rand Initialize
	srand(GetTickCount());

	//** Player Initialize
	Object* pPlayer = CreateObject();
	InitPlayter(pPlayer);	


	//** BulletList Init (= NULL)
	Object* Bullet[Bullet_MAX];

	for (int i = 0; i < Bullet_MAX; i++)
		Bullet[i] = NULL;

	//** MonsterList Init (= NULL)
	Object* pMonster[MONSTER_MAX];
	for (int i = 0; i < MONSTER_MAX; i++)
		pMonster[i] = NULL;		
	

	//**FrameTime Initialize
	DWORD dwTime = GetTickCount();

	//**Create Monster Time Initialize
	dmMonsterTime = GetTickCount();
	

	while (true)
	{
		if (dwTime + 80 < GetTickCount())
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
		BackGroundRender();
		
		//** Progress
		PlayerProgress(_pPlayer, _Bullet);
		BulletProgress(_Bullet);
		MonsterProgress(_pMonster);

		//** Render
		PlayerRender(_pPlayer);
		BulletRender(_Bullet);
		MonsterRender(_pMonster);
		
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
	_pPlayer->pName = (char*)"옷";
	_pPlayer->TransPos.Position = Vector3(0.f, 0.f);
	_pPlayer->TransPos.Scale = Vector3(strlen(_pPlayer->pName), 0.f);
	_pPlayer->TransPos.eDirection = (DIRID)KEYID_CENTER;
}


void PlayerProgress(Object* _pPlayer, Object* _Bullet[])
{
	DWORD dwKey = InputKey();

	if (dwKey & KEYID_UP)
	{
		_pPlayer->TransPos.Position.y--;
		_pPlayer->TransPos.eDirection = (DIRID)KEYID_UP;
	}
		
	
	if (dwKey & KEYID_DOWN)
	{
		_pPlayer->TransPos.Position.y++;
		_pPlayer->TransPos.eDirection = (DIRID)KEYID_DOWN;
	}

	if (dwKey & KEYID_LEFT)
	{
		_pPlayer->TransPos.Position.x--;
		_pPlayer->TransPos.eDirection = (DIRID)KEYID_LEFT;
	}
	if (dwKey & KEYID_RIGHT)
	{
		_pPlayer->TransPos.Position.x++;
		_pPlayer->TransPos.eDirection = (DIRID)KEYID_RIGHT;
	}
	
	//** 만약 스페이스 키를 입력 했다면...
	if (dwKey & KEYID_SPACE)

		//** 총알을 생성.
		CreateBullet(_Bullet, _pPlayer);
}

void PlayerRender(Object* _pPlayer)
{
	SetCurserPosition(
		_pPlayer->TransPos.Position.x,
		_pPlayer->TransPos.Position.y,
		_pPlayer->pName);
	
	//printf_s("Position x: %f\n", _pPlayer->TransPos.Position.x);
	//printf_s("Position y: %f\n", _pPlayer->TransPos.Position.y);
	//printf_s("Scale x: %f\n", _pPlayer->TransPos.Scale.x);
	//printf_s("Scale y: %f\n", _pPlayer->TransPos.Scale.y);		
}


//몬스터 랜덤출력 해보기
void InitMonster(Object* _pMonster)
{
		_pMonster->pName = (char*)"★";		
		_pMonster->TransPos.Position = Vector3(0.f, 0.f);
		_pMonster->TransPos.Scale = Vector3(strlen(_pMonster->pName), 0.f);
		_pMonster->TransPos.eDirection = (DIRID)KEYID_CENTER;
	

}


void MonsterProgress(Object* _pMonster[])
{
	//** 일정 시간 마다...
	if (dmMonsterTime + 1500 < GetTickCount())
	{
		dmMonsterTime = GetTickCount();
		//** 몬스터 생성.
		CreateMonster(_pMonster);
	}
	
}

void MonsterRender(Object* _pMonster[])
{
	//**  모든 몬스터 리스트를 확인.
	for ( int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약에 몬스터 리스트에 몬스터가 있다면.....
		if (_pMonster[i])
		{
			SetCurserPosition(
				_pMonster[i]->TransPos.Position.x,
				_pMonster[i]->TransPos.Position.y,
				_pMonster[i]->pName);
		}

	}
	
}
void CreateMonster(Object* _pMonster[])
{
	//** 몬스터 리스트를 모두 확인.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약 몬스터 리스트에 몬스터가 없다면 없다면...
		if (!_pMonster[i])
		{
			//** 몬스터를 생성.
			_pMonster[i] = CreateObject();

			//** 생성된 몬스터 초기회.
			InitMonster(_pMonster[i]);

			//** 몬스터의 위치를 랜덤한 좌표로 변경.
			_pMonster[i]->TransPos.Position = Vector3(
				rand() % (WINSIZEX - 5) + 2, rand() % (WINSIZEY - 2) + 1);

			//** 모든 작업이 종료된 후 구문 탈출

			break;
		}
	}


}


void InitBullet(Object* _Bullet)
{

	_Bullet->pName = (char*)"장풍";

	_Bullet->TransPos.eDirection = (DIRID)KEYID_CENTER;
	_Bullet->TransPos.Position = Vector3(0.f, 0.f);	
	_Bullet->TransPos.Scale = Vector3(strlen(_Bullet->pName), 1.f);
	

}

void BulletProgress(Object* _Bullet[])
{
	//** 모든 총알을 확인.
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_Bullet[i])
		{
			//** 총알의 x죄표를 2씩 증가 시킨다.
			

			switch (_Bullet[i]->TransPos.eDirection)
			{
				case KEYID_UP:
					_Bullet[i]->TransPos.Position.y --;
					//** 만약 증가된 후에 y 좌표가 월드좌표 0보다 작다면...
					if ((_Bullet[i]->TransPos.Position.y <= 1))

					{
						//** 동적 할당 해제.
						free(_Bullet[i]);

						//** 초기화/
						_Bullet[i] = NULL;

						
					}
					break;

				case KEYID_DOWN:
					_Bullet[i]->TransPos.Position.y ++;
					//** 만약 증가된 후에 y 좌표가 월드좌표 30보다 크다면...
					if ((_Bullet[i]->TransPos.Position.y >= (WINSIZEY - 1)))

					{
						//** 동적 할당 해제.
						free(_Bullet[i]);

						//** 초기화/
						_Bullet[i] = NULL;
						
					}
					break;

				case KEYID_RIGHT:
					_Bullet[i]->TransPos.Position.x += 2;
					//** 만약 증가된 후에 x 좌표가 월드좌표 95보다 크다면...
					if ((_Bullet[i]->TransPos.Position.x +
						_Bullet[i]->TransPos.Scale.x) > (WINSIZEX - 2))

					{
						//** 동적 할당 해제.
						free(_Bullet[i]);

						//** 초기화/
						_Bullet[i] = NULL;
						
					}
					break;

				case KEYID_LEFT:
					_Bullet[i]->TransPos.Position.x -= 2;
					//** 만약 증가된 후에 x 좌표가 월드좌표 0보다 작다면...
					if ((_Bullet[i]->TransPos.Position.x <= 0))

					{
						//** 동적 할당 해제.
						free(_Bullet[i]);

						//** 초기화/
						_Bullet[i] = NULL;
						
					}
					break;
			}

			//** 만약 증가된 후에 x 좌표가 월드좌표 95보다 크다면...
			//if (_Bullet[i]->TransPos.Position.x + _Bullet[i]->TransPos.Scale.x > (WINSIZEX-2))
				
			//{
			//	//** 동적 할당 해제.
			//	free(_Bullet[i]);

			//	//** 초기화/
			//	_Bullet[i] = NULL;			
			//}
		}				
	}
}

void BulletRender(Object* _Bullet[])
{		
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_Bullet[i])
		{
			//** 총알을 출력해줌.
			SetCurserPosition(
				_Bullet[i]->TransPos.Position.x,
				_Bullet[i]->TransPos.Position.y,
				_Bullet[i]->pName);
		}		
	}
}

//** 총알 생성
void CreateBullet(Object* _Bullet[], Object* _pPlayer )
{
	//** 모든 총알 리스트를 확인.
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** 만약 총알이 없다면...
		if (!_Bullet[i])
		{
			//** 총알을 생성.
			_Bullet[i] = CreateObject();

			//** 생성된 총알 초기회.
			InitBullet(_Bullet[i]);

			//** 총알의 위치를 플레이어의 좌표로 변경.
			_Bullet[i]->TransPos.Position = _pPlayer->TransPos.Position;

			//** 플레이어의 현재 방향에 총알을 설정.
			SetBulletDirection(_Bullet[i], _pPlayer->TransPos.eDirection);

			//** 모든 작업이 종료된 후 해당 구문 탈출.
			break;
		}
	}	
}

void SetBulletDirection(Object* _Bullet, DWORD _dwDir)
{
	_Bullet->TransPos.eDirection = (DIRID)_dwDir;
}



void BackGroundRender()
{
	for (int y = 0; y < WINSIZEY; y++)
	{
		if (y == 0 || y == (WINSIZEY - 1))
		{
			SetCurserPosition(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		}
		
		else
		{
			SetCurserPosition(0, y, (char*)"■");
			SetCurserPosition(WINSIZEX - 2, y, (char*)"■");
		}
		/*for (int x = 0; x < WINSIZEX; x += 2)
		{
			if (y > 0 && y < (WINSIZEX - 1))
			{
				if (x == 0 || x == (WINSIZEX - 2))
				{
					SetCurserPosition(x, y, (char*)"■");
				}
			}

		}*/				
	}


}


//** 입력된 (x, y)좌표에 문자열 출력.
void SetCurserPosition(int _ix, int _iy, char* _str)
{
	//** 좌표를 셋팅 
	COORD pos = { _ix, _iy };

	//** 셋팅된 좌표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//** 이동된 위치에 문자열 출력.
	cout << _str;
}



DWORD InputKey()
{
	DWORD dwInput = 0;

	if (GetAsyncKeyState(VK_UP))
	{
		dwInput |= KEYID_UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		dwInput |= KEYID_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		dwInput |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dwInput |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		dwInput |= KEYID_SPACE;
	}

	return dwInput;
}
#include "Headers.h"




//** 전역변수
SCENEID eSCENEID = SCENEID_STAGE;
DWORD dwMonsterTime = 0;
int Collision = 0;
int iSleep = 0;
int iScore = 0;
int iGameOver = 0;

//** 함수 전방선언
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[]);
char* SetName();
Object* CreateObject();



void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer, Object* _pMonster[]);
void PlayerRender(Object* _pPlayer);

void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);
void CreateMonster(Object* _pMonster[]);

void SetCursorPosiotionInteger(int _ix, int _iy, int _value);
/*
void InitBullet(Object* _pBullet);
void BulletProgress(Object* _pBullet[]);
void BulletRender(Object* _pBullet[]);
void CreateBullet(Object* _pBullet[], Object* _pPlayer);
void SetBulletDirection(Object* _pBullet, DIRID _eDir);
*/

void BackGroundRender();


void SetCursorPosiotion(int _ix, int _iy, char* _str);
DWORD InputKey();



int main(void)
{
	//** rand Initialize
	srand(GetTickCount());

	//** Player Initialize
	Object* pPlayer = CreateObject();
	InitPlayer(pPlayer);


	//** MonsterList Initialize (= NULL)
	Object* pMonster[MONSTER_MAX];

	for (int i = 0; i < MONSTER_MAX; i++)
		pMonster[i] = NULL;


	//** BulletList Initialize (= NULL)
	Object* pBullet[BULLET_MAX];

	for (int i = 0; i < BULLET_MAX; i++)
		pBullet[i] = NULL;

	//** FrameTime Initialize
	DWORD dwTime = GetTickCount();

	//** Create Monster Time Initialize
	dwMonsterTime = GetTickCount();

	while (true)
	{
		if (dwTime + 80 + iSleep < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			if (Collision)
			{
				Collision = 0;

				iSleep = 0;
			}
			
			


			SetScene(pPlayer, pMonster, pBullet);

		}
	}

	system("pause");

	return 0;
}


void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[])
{
	switch (eSCENEID)
	{
	case SCENEID_LOGO:
		printf_s("SCENEID_LOGO\n");
		system("pause");

		eSCENEID = SCENEID_MENU;
		break;

	case SCENEID_MENU:
		iGameOver = 0;
		InitPlayer(_pPlayer);
		printf_s("SCENEID_MENU\n");
		system("pause");

		eSCENEID = SCENEID_STAGE;
		break;

	case SCENEID_STAGE:
		BackGroundRender();

		//** Progress
		PlayerProgress(_pPlayer, _pMonster);
		/*BulletProgress(_pBullet);*/
		MonsterProgress(_pMonster);
		
		//** Render
		PlayerRender(_pPlayer);
		/*BulletRender(_pBullet);*/
		MonsterRender(_pMonster);

		if (iGameOver)
		{

		}

		break;

	case SCENEID_STORE:
		printf_s("SCENEID_STORE\n");
		system("pause");
		break;

	case SCENEID_OPTION:
		printf_s("SCENEID_OPTION\n");
		system("pause");
		break;

	case SCENEID_EXIT:
		printf_s("SCENEID_EXIT\n");
		system("pause");
		break;
	}
}


char* SetName()
{
	char str[128] = "";

	printf_s("당신은 누구인가요 ?\n");	Sleep(1000);
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

void InitPlayer(Object* _pPlayer)
{
	_pPlayer->pName = (char*)"옷";
	_pPlayer->TransPos.eDirection = DIRID_RIGHT;
	_pPlayer->TransPos.Position = Vector3(2.f, 1.f);
	_pPlayer->TransPos.Scale = Vector3(strlen(_pPlayer->pName), 1.f);
}

// eDirection 방향

void PlayerProgress(Object* _pPlayer, Object* _pMonster[])
{
	DWORD dwKey = InputKey();

	if (dwKey & KEYID_UP && _pPlayer->TransPos.eDirection != DIRID_DOWN)
	{
		_pPlayer->TransPos.eDirection = DIRID_UP;			
	}

	if (dwKey & KEYID_DOWN && _pPlayer->TransPos.eDirection != DIRID_UP)
	{	
		_pPlayer->TransPos.eDirection = DIRID_DOWN;
	}

	if (dwKey & KEYID_LEFT && _pPlayer->TransPos.eDirection != DIRID_RIGHT)
	{		
		_pPlayer->TransPos.eDirection = DIRID_LEFT;
	}

	if (dwKey & KEYID_RIGHT && _pPlayer->TransPos.eDirection != DIRID_LEFT)
	{		
		_pPlayer->TransPos.eDirection = DIRID_RIGHT;
	}

	switch (_pPlayer->TransPos.eDirection)
	{

		case DIRID_UP:
			if (_pPlayer->TransPos.Position.y > 1)
				_pPlayer->TransPos.Position.y--;
			else
				iGameOver = 1;
		break;

		case DIRID_DOWN:
			if (_pPlayer->TransPos.Position.y < (WINSIZEY -2))
		_pPlayer->TransPos.Position.y++;
		break;

		case DIRID_RIGHT:
			if (_pPlayer->TransPos.Position.x > 2)
		_pPlayer->TransPos.Position.x++;
		break;

		case DIRID_LEFT:
			if (_pPlayer->TransPos.Position.x < (WINSIZEX-4))
		_pPlayer->TransPos.Position.x--;
		break;

	}

	for (int i = 0; i < MONSTER_MAX; i++)
	{
		if (_pMonster[i])
		{
			if ((_pPlayer->TransPos.Position.x + _pPlayer->TransPos.Scale.x) > _pMonster[i]->TransPos.Position.x 
				&&(_pMonster[i]->TransPos.Position.x + _pMonster[i]->TransPos.Scale.x) > _pPlayer->TransPos.Position.x
				&& _pMonster[i]->TransPos.Position.y == _pPlayer->TransPos.Position.y)
			{
				
				free(_pMonster[i]);
				_pMonster[i] = NULL;
				
				Collision = 1;

				iSleep = 50;
				
				iScore +=3;
			}

	
		}
		
		
		
	}

	
		
	

	


	/*
	//** 만약 스페이스 키를 입력 했다면....
	if (dwKey & KEYID_SPACE)
	{
		//** 총알을 생성.
		CreateBullet(_pBullet, _pPlayer);
	}
	*/
}

void PlayerRender(Object* _pPlayer)
{
	SetCursorPosiotion(
		_pPlayer->TransPos.Position.x,
		_pPlayer->TransPos.Position.y,
		_pPlayer->pName);
}


void InitMonster(Object* _pMonster)
{
	_pMonster->pName = (char*)"★";
	_pMonster->TransPos.Position = Vector3(0.f, 0.f);
	_pMonster->TransPos.Scale = Vector3(strlen(_pMonster->pName), 0.f);
	_pMonster->TransPos.eDirection = DIRID_CENTER;
}

void MonsterProgress(Object* _pMonster[])
{
	//** 일정 시간 마다..
	if (dwMonsterTime + 1500 < GetTickCount())
	{
		dwMonsterTime = GetTickCount();

		//** 몬스터를 생성.
		CreateMonster(_pMonster);
	}
}

void MonsterRender(Object* _pMonster[])
{
	//** 모든 몬스터 리스트를 확인.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약에 몬스터 리스트에 몬스터가 있다면.....
		if (_pMonster[i])
		{
			SetCursorPosiotion(
				_pMonster[i]->TransPos.Position.x,
				_pMonster[i]->TransPos.Position.y,
				_pMonster[i]->pName);
		}
	}
}

void CreateMonster(Object* _pMonster[])
{
	//** 모든 몬스터 리스트를 확인.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** 만약에 몬스터 리스트에 몬스터가 없다면.....
		if (!_pMonster[i])
		{
			//** 몬스터를 생성.
			_pMonster[i] = CreateObject();

			//** 생성된 몬스터를 초기화.
			InitMonster(_pMonster[i]);

			//** 몬스터의 위치를 랜덤한 좌표로 변경.
			_pMonster[i]->TransPos.Position = Vector3(
				rand() % (WINSIZEX - 5) + 2, 
				rand() % (WINSIZEY - 3) + 1);
			
			//** 모든 작업이 종료된 후 구문 탈출.
			break;
		}
	}
}
/*
void InitBullet(Object* _pBullet)
{
	_pBullet->pName = (char*)"장풍";

	_pBullet->TransPos.eDirection = DIRID_CENTER;
	_pBullet->TransPos.Position = Vector3(0.f, 0.f);
	_pBullet->TransPos.Scale = Vector3(strlen(_pBullet->pName), 1.f);
}

void BulletProgress(Object* _pBullet[])
{
	//** 모든 총알을 확인.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_pBullet[i])
		{
			//** 총알의 X 좌표를 2씩 증가 시킨다.


			switch (_pBullet[i]->TransPos.eDirection)
			{
			case DIRID_UP:
				_pBullet[i]->TransPos.Position.y--;

				//** 만약 증가된 후에 Y좌표가 월드좌표 0보다 작다면....
				if ((_pBullet[i]->TransPos.Position.y <= 1) )
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_DOWN:
				_pBullet[i]->TransPos.Position.y++;

				//** 만약 증가된 후에 Y좌표가 월드좌표 25 보다 크다면....
				if ((_pBullet[i]->TransPos.Position.y >= (WINSIZEY - 1)))
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_RIGHT:
				_pBullet[i]->TransPos.Position.x += 2;

				//** 만약 증가된 후에 X좌표가 월드좌표 95 보다 크다면....
				if ((_pBullet[i]->TransPos.Position.x +
					_pBullet[i]->TransPos.Scale.x) > (WINSIZEX - 2))
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_LEFT:
				_pBullet[i]->TransPos.Position.x -= 2;

				//** 만약 증가된 후에 X좌표가 월드좌표 0 보다 작다면....
				if ( (_pBullet[i]->TransPos.Position.x <= 0 ) )
				{
					//** 동적 할당 해제
					free(_pBullet[i]);

					//** 초기화
					_pBullet[i] = NULL;
				}
				break;
			}
		}
	}
}

void BulletRender(Object* _pBullet[])
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약 총알이 있다면....
		if (_pBullet[i])
		{
			//** 총알을 출력해줌...
			SetCursorPosiotion(
				_pBullet[i]->TransPos.Position.x,
				_pBullet[i]->TransPos.Position.y,
				_pBullet[i]->pName);
		}
	}
}

//** 총알 생성
void CreateBullet(Object* _pBullet[], Object* _pPlayer)
{
	//** 모든 총알 리스트를 확인.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** 만약에 총알이 없다면.....
		if (!_pBullet[i])
		{
			//** 총알을 생성.
			_pBullet[i] = CreateObject();

			//** 생성된 총알 초기화.
			InitBullet(_pBullet[i]);

			//** 총알의 위치를 플레이어의 좌표로 변경.
			_pBullet[i]->TransPos.Position = _pPlayer->TransPos.Position;

			//** 플레이어의 현재 방향을 총알에 설정.
			SetBulletDirection(_pBullet[i], _pPlayer->TransPos.eDirection);

			//** 모든작업 종료된후 구문 탈출.
			break;
		}
	}
}

void SetBulletDirection(Object* _pBullet, DIRID _eDir)
{
	_pBullet->TransPos.eDirection = _eDir;
}

*/




void BackGroundRender()
{
	for (int y = 0; y < WINSIZEY; y++)
	{
		if (y == 0 || y == (WINSIZEY - 2))
		{
			SetCursorPosiotion(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		}
		else
		{
			SetCursorPosiotion(0, y, (char*)"■");
			SetCursorPosiotion(WINSIZEX - 2, y, (char*)"■");			
		}
	}
	SetCursorPosiotion(5, WINSIZEY - 1, (char*)"SCORE :");
	
}



//** 입력된 (x, y)좌표에 문자열 출력.
void SetCursorPosiotion(int _ix, int _iy, char* _str)
{
	//** 좌표를 셋팅.
	COORD pos = { _ix, _iy };

	//** 셋팅된 자표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//** 이동된 위치에 문자열 출력.
	cout << _str;
}

//** 입력된 (x, y)좌표에 문자열 출력.
void SetCursorPosiotionInteger(int _ix, int _iy, int _value)
{

	//** 좌표를 셋팅.
	COORD pos = { _ix, _iy };

	//** 셋팅된 자표로 콘솔 커서를 이동시킴.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//** 이동된 위치에 문자열 출력.
	cout << _value;

}

DWORD InputKey()
{
	DWORD dwInput = 0;

	if (GetAsyncKeyState(VK_UP))
		dwInput |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		dwInput |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		dwInput |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		dwInput |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		dwInput |= KEYID_SPACE;

	return dwInput;
}

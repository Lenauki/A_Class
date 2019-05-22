#include "Headers.h"




//** ��������
SCENEID eSCENEID = SCENEID_STAGE;
DWORD dwMonsterTime = 0;
int Collision = 0;
int iSleep = 0;
int iScore = 0;
int iGameOver = 0;

//** �Լ� ���漱��
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

	printf_s("����� �����ΰ��� ?\n");	Sleep(1000);
	printf_s("�Է� : ");
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
	_pPlayer->pName = (char*)"��";
	_pPlayer->TransPos.eDirection = DIRID_RIGHT;
	_pPlayer->TransPos.Position = Vector3(2.f, 1.f);
	_pPlayer->TransPos.Scale = Vector3(strlen(_pPlayer->pName), 1.f);
}

// eDirection ����

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
	//** ���� �����̽� Ű�� �Է� �ߴٸ�....
	if (dwKey & KEYID_SPACE)
	{
		//** �Ѿ��� ����.
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
	_pMonster->pName = (char*)"��";
	_pMonster->TransPos.Position = Vector3(0.f, 0.f);
	_pMonster->TransPos.Scale = Vector3(strlen(_pMonster->pName), 0.f);
	_pMonster->TransPos.eDirection = DIRID_CENTER;
}

void MonsterProgress(Object* _pMonster[])
{
	//** ���� �ð� ����..
	if (dwMonsterTime + 1500 < GetTickCount())
	{
		dwMonsterTime = GetTickCount();

		//** ���͸� ����.
		CreateMonster(_pMonster);
	}
}

void MonsterRender(Object* _pMonster[])
{
	//** ��� ���� ����Ʈ�� Ȯ��.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** ���࿡ ���� ����Ʈ�� ���Ͱ� �ִٸ�.....
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
	//** ��� ���� ����Ʈ�� Ȯ��.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** ���࿡ ���� ����Ʈ�� ���Ͱ� ���ٸ�.....
		if (!_pMonster[i])
		{
			//** ���͸� ����.
			_pMonster[i] = CreateObject();

			//** ������ ���͸� �ʱ�ȭ.
			InitMonster(_pMonster[i]);

			//** ������ ��ġ�� ������ ��ǥ�� ����.
			_pMonster[i]->TransPos.Position = Vector3(
				rand() % (WINSIZEX - 5) + 2, 
				rand() % (WINSIZEY - 3) + 1);
			
			//** ��� �۾��� ����� �� ���� Ż��.
			break;
		}
	}
}
/*
void InitBullet(Object* _pBullet)
{
	_pBullet->pName = (char*)"��ǳ";

	_pBullet->TransPos.eDirection = DIRID_CENTER;
	_pBullet->TransPos.Position = Vector3(0.f, 0.f);
	_pBullet->TransPos.Scale = Vector3(strlen(_pBullet->pName), 1.f);
}

void BulletProgress(Object* _pBullet[])
{
	//** ��� �Ѿ��� Ȯ��.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** ���� �Ѿ��� �ִٸ�....
		if (_pBullet[i])
		{
			//** �Ѿ��� X ��ǥ�� 2�� ���� ��Ų��.


			switch (_pBullet[i]->TransPos.eDirection)
			{
			case DIRID_UP:
				_pBullet[i]->TransPos.Position.y--;

				//** ���� ������ �Ŀ� Y��ǥ�� ������ǥ 0���� �۴ٸ�....
				if ((_pBullet[i]->TransPos.Position.y <= 1) )
				{
					//** ���� �Ҵ� ����
					free(_pBullet[i]);

					//** �ʱ�ȭ
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_DOWN:
				_pBullet[i]->TransPos.Position.y++;

				//** ���� ������ �Ŀ� Y��ǥ�� ������ǥ 25 ���� ũ�ٸ�....
				if ((_pBullet[i]->TransPos.Position.y >= (WINSIZEY - 1)))
				{
					//** ���� �Ҵ� ����
					free(_pBullet[i]);

					//** �ʱ�ȭ
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_RIGHT:
				_pBullet[i]->TransPos.Position.x += 2;

				//** ���� ������ �Ŀ� X��ǥ�� ������ǥ 95 ���� ũ�ٸ�....
				if ((_pBullet[i]->TransPos.Position.x +
					_pBullet[i]->TransPos.Scale.x) > (WINSIZEX - 2))
				{
					//** ���� �Ҵ� ����
					free(_pBullet[i]);

					//** �ʱ�ȭ
					_pBullet[i] = NULL;
				}
				break;
			case DIRID_LEFT:
				_pBullet[i]->TransPos.Position.x -= 2;

				//** ���� ������ �Ŀ� X��ǥ�� ������ǥ 0 ���� �۴ٸ�....
				if ( (_pBullet[i]->TransPos.Position.x <= 0 ) )
				{
					//** ���� �Ҵ� ����
					free(_pBullet[i]);

					//** �ʱ�ȭ
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
		//** ���� �Ѿ��� �ִٸ�....
		if (_pBullet[i])
		{
			//** �Ѿ��� �������...
			SetCursorPosiotion(
				_pBullet[i]->TransPos.Position.x,
				_pBullet[i]->TransPos.Position.y,
				_pBullet[i]->pName);
		}
	}
}

//** �Ѿ� ����
void CreateBullet(Object* _pBullet[], Object* _pPlayer)
{
	//** ��� �Ѿ� ����Ʈ�� Ȯ��.
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//** ���࿡ �Ѿ��� ���ٸ�.....
		if (!_pBullet[i])
		{
			//** �Ѿ��� ����.
			_pBullet[i] = CreateObject();

			//** ������ �Ѿ� �ʱ�ȭ.
			InitBullet(_pBullet[i]);

			//** �Ѿ��� ��ġ�� �÷��̾��� ��ǥ�� ����.
			_pBullet[i]->TransPos.Position = _pPlayer->TransPos.Position;

			//** �÷��̾��� ���� ������ �Ѿ˿� ����.
			SetBulletDirection(_pBullet[i], _pPlayer->TransPos.eDirection);

			//** ����۾� ������� ���� Ż��.
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
			SetCursorPosiotion(0, y, (char*)"���������������������������������������������������");
		}
		else
		{
			SetCursorPosiotion(0, y, (char*)"��");
			SetCursorPosiotion(WINSIZEX - 2, y, (char*)"��");			
		}
	}
	SetCursorPosiotion(5, WINSIZEY - 1, (char*)"SCORE :");
	
}



//** �Էµ� (x, y)��ǥ�� ���ڿ� ���.
void SetCursorPosiotion(int _ix, int _iy, char* _str)
{
	//** ��ǥ�� ����.
	COORD pos = { _ix, _iy };

	//** ���õ� ��ǥ�� �ܼ� Ŀ���� �̵���Ŵ.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//** �̵��� ��ġ�� ���ڿ� ���.
	cout << _str;
}

//** �Էµ� (x, y)��ǥ�� ���ڿ� ���.
void SetCursorPosiotionInteger(int _ix, int _iy, int _value)
{

	//** ��ǥ�� ����.
	COORD pos = { _ix, _iy };

	//** ���õ� ��ǥ�� �ܼ� Ŀ���� �̵���Ŵ.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	//** �̵��� ��ġ�� ���ڿ� ���.
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

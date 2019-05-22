#include "Headers.h"




//** ��������
SCENEID eSCENEID = SCENEID_STAGE;
DWORD dwMonsterTime = 0;


//** �Լ� ���漱��
void SetScene(Object* _pPlayer, Object* _pMonster[], Object* _pBullet[]);
char* SetName();
Object* CreateObject();



void InitPlayer(Object* _pPlayer);
void PlayerProgress(Object* _pPlayer, Object* _pBullet[]);
void PlayerRender(Object* _pPlayer);

void InitMonster(Object* _pMonster);
void MonsterProgress(Object* _pMonster[]);
void MonsterRender(Object* _pMonster[]);
void CreateMonster(Object* _pMonster[]);

void InitBullet(Object* _pBullet);
void BulletProgress(Object* _pBullet[]);
void BulletRender(Object* _pBullet[]);
void CreateBullet(Object* _pBullet[], Object* _pPlayer);
void SetBulletDirection(Object* _pBullet, DWORD _dwDir);

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
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

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
		printf_s("SCENEID_MENU\n");
		system("pause");

		eSCENEID = SCENEID_STAGE;
		break;

	case SCENEID_STAGE:
		BackGroundRender();

		//** Progress
		PlayerProgress(_pPlayer, _pBullet);
		BulletProgress(_pBullet);
		MonsterProgress(_pMonster);
		
		//** Render
		PlayerRender(_pPlayer);
		BulletRender(_pBullet);
		MonsterRender(_pMonster);

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
	_pPlayer->TransPos.eDirection = (DIRID)KEYID_CENTER;
	_pPlayer->TransPos.Position = Vector3(0.f, 0.f);
	_pPlayer->TransPos.Scale = Vector3(strlen(_pPlayer->pName), 1.f);
}

void PlayerProgress(Object* _pPlayer, Object* _pBullet[])
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

	//** ���� �����̽� Ű�� �Է� �ߴٸ�....
	if (dwKey & KEYID_SPACE)
	{
		//** �Ѿ��� ����.
		CreateBullet(_pBullet, _pPlayer);
	}
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
	_pMonster->TransPos.eDirection = (DIRID)KEYID_CENTER;
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
				rand() % (WINSIZEY - 2) + 1);
			
			//** ��� �۾��� ����� �� ���� Ż��.
			break;
		}
	}
}

void InitBullet(Object* _pBullet)
{
	_pBullet->pName = (char*)"��ǳ";

	_pBullet->TransPos.eDirection = (DIRID)KEYID_CENTER;
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
			case KEYID_UP:
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
			case KEYID_DOWN:
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
			case KEYID_RIGHT:
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
			case KEYID_LEFT:
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

void SetBulletDirection(Object* _pBullet, DWORD _dwDir)
{
	_pBullet->TransPos.eDirection = (DIRID)_dwDir;
}




void BackGroundRender()
{
	for (int y = 0; y < WINSIZEY; y++)
	{
		if (y == 0 || y == (WINSIZEY - 1))
		{
			SetCursorPosiotion(0, y, (char*)"���������������������������������������������������");
		}
		else
		{
			SetCursorPosiotion(0, y, (char*)"��");
			SetCursorPosiotion(WINSIZEX - 2, y, (char*)"��");
		}
	}
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

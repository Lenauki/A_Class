#include "Headers.h"

//** ������ 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** ���, ����

//** ��������
SCENEID eSCENEID = SCENEID_STAGE;
DWORD dmMonsterTime = 0;

//** �Լ� ���漱��
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
 1���� ������Ʈ�� 3���� ������ �ʿ��� ������ 
 ��ġ��( ������), ũ�Ⱚ(������), ȸ����  (�����̼�)
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
	//** ���ڿ� �Է�
	char str[128] = "";

	printf_s("����� �����ΰ��� ?\n");
	Sleep(1000);
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

void InitPlayter(Object* _pPlayer)
{
	_pPlayer->pName = (char*)"��";
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
	
	//** ���� �����̽� Ű�� �Է� �ߴٸ�...
	if (dwKey & KEYID_SPACE)

		//** �Ѿ��� ����.
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


//���� ������� �غ���
void InitMonster(Object* _pMonster)
{
		_pMonster->pName = (char*)"��";		
		_pMonster->TransPos.Position = Vector3(0.f, 0.f);
		_pMonster->TransPos.Scale = Vector3(strlen(_pMonster->pName), 0.f);
		_pMonster->TransPos.eDirection = (DIRID)KEYID_CENTER;
	

}


void MonsterProgress(Object* _pMonster[])
{
	//** ���� �ð� ����...
	if (dmMonsterTime + 1500 < GetTickCount())
	{
		dmMonsterTime = GetTickCount();
		//** ���� ����.
		CreateMonster(_pMonster);
	}
	
}

void MonsterRender(Object* _pMonster[])
{
	//**  ��� ���� ����Ʈ�� Ȯ��.
	for ( int i = 0; i < MONSTER_MAX; i++)
	{
		//** ���࿡ ���� ����Ʈ�� ���Ͱ� �ִٸ�.....
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
	//** ���� ����Ʈ�� ��� Ȯ��.
	for (int i = 0; i < MONSTER_MAX; i++)
	{
		//** ���� ���� ����Ʈ�� ���Ͱ� ���ٸ� ���ٸ�...
		if (!_pMonster[i])
		{
			//** ���͸� ����.
			_pMonster[i] = CreateObject();

			//** ������ ���� �ʱ�ȸ.
			InitMonster(_pMonster[i]);

			//** ������ ��ġ�� ������ ��ǥ�� ����.
			_pMonster[i]->TransPos.Position = Vector3(
				rand() % (WINSIZEX - 5) + 2, rand() % (WINSIZEY - 2) + 1);

			//** ��� �۾��� ����� �� ���� Ż��

			break;
		}
	}


}


void InitBullet(Object* _Bullet)
{

	_Bullet->pName = (char*)"��ǳ";

	_Bullet->TransPos.eDirection = (DIRID)KEYID_CENTER;
	_Bullet->TransPos.Position = Vector3(0.f, 0.f);	
	_Bullet->TransPos.Scale = Vector3(strlen(_Bullet->pName), 1.f);
	

}

void BulletProgress(Object* _Bullet[])
{
	//** ��� �Ѿ��� Ȯ��.
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** ���� �Ѿ��� �ִٸ�....
		if (_Bullet[i])
		{
			//** �Ѿ��� x��ǥ�� 2�� ���� ��Ų��.
			

			switch (_Bullet[i]->TransPos.eDirection)
			{
				case KEYID_UP:
					_Bullet[i]->TransPos.Position.y --;
					//** ���� ������ �Ŀ� y ��ǥ�� ������ǥ 0���� �۴ٸ�...
					if ((_Bullet[i]->TransPos.Position.y <= 1))

					{
						//** ���� �Ҵ� ����.
						free(_Bullet[i]);

						//** �ʱ�ȭ/
						_Bullet[i] = NULL;

						
					}
					break;

				case KEYID_DOWN:
					_Bullet[i]->TransPos.Position.y ++;
					//** ���� ������ �Ŀ� y ��ǥ�� ������ǥ 30���� ũ�ٸ�...
					if ((_Bullet[i]->TransPos.Position.y >= (WINSIZEY - 1)))

					{
						//** ���� �Ҵ� ����.
						free(_Bullet[i]);

						//** �ʱ�ȭ/
						_Bullet[i] = NULL;
						
					}
					break;

				case KEYID_RIGHT:
					_Bullet[i]->TransPos.Position.x += 2;
					//** ���� ������ �Ŀ� x ��ǥ�� ������ǥ 95���� ũ�ٸ�...
					if ((_Bullet[i]->TransPos.Position.x +
						_Bullet[i]->TransPos.Scale.x) > (WINSIZEX - 2))

					{
						//** ���� �Ҵ� ����.
						free(_Bullet[i]);

						//** �ʱ�ȭ/
						_Bullet[i] = NULL;
						
					}
					break;

				case KEYID_LEFT:
					_Bullet[i]->TransPos.Position.x -= 2;
					//** ���� ������ �Ŀ� x ��ǥ�� ������ǥ 0���� �۴ٸ�...
					if ((_Bullet[i]->TransPos.Position.x <= 0))

					{
						//** ���� �Ҵ� ����.
						free(_Bullet[i]);

						//** �ʱ�ȭ/
						_Bullet[i] = NULL;
						
					}
					break;
			}

			//** ���� ������ �Ŀ� x ��ǥ�� ������ǥ 95���� ũ�ٸ�...
			//if (_Bullet[i]->TransPos.Position.x + _Bullet[i]->TransPos.Scale.x > (WINSIZEX-2))
				
			//{
			//	//** ���� �Ҵ� ����.
			//	free(_Bullet[i]);

			//	//** �ʱ�ȭ/
			//	_Bullet[i] = NULL;			
			//}
		}				
	}
}

void BulletRender(Object* _Bullet[])
{		
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** ���� �Ѿ��� �ִٸ�....
		if (_Bullet[i])
		{
			//** �Ѿ��� �������.
			SetCurserPosition(
				_Bullet[i]->TransPos.Position.x,
				_Bullet[i]->TransPos.Position.y,
				_Bullet[i]->pName);
		}		
	}
}

//** �Ѿ� ����
void CreateBullet(Object* _Bullet[], Object* _pPlayer )
{
	//** ��� �Ѿ� ����Ʈ�� Ȯ��.
	for (int i = 0; i < Bullet_MAX; i++)
	{
		//** ���� �Ѿ��� ���ٸ�...
		if (!_Bullet[i])
		{
			//** �Ѿ��� ����.
			_Bullet[i] = CreateObject();

			//** ������ �Ѿ� �ʱ�ȸ.
			InitBullet(_Bullet[i]);

			//** �Ѿ��� ��ġ�� �÷��̾��� ��ǥ�� ����.
			_Bullet[i]->TransPos.Position = _pPlayer->TransPos.Position;

			//** �÷��̾��� ���� ���⿡ �Ѿ��� ����.
			SetBulletDirection(_Bullet[i], _pPlayer->TransPos.eDirection);

			//** ��� �۾��� ����� �� �ش� ���� Ż��.
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
			SetCurserPosition(0, y, (char*)"���������������������������������������������������");
		}
		
		else
		{
			SetCurserPosition(0, y, (char*)"��");
			SetCurserPosition(WINSIZEX - 2, y, (char*)"��");
		}
		/*for (int x = 0; x < WINSIZEX; x += 2)
		{
			if (y > 0 && y < (WINSIZEX - 1))
			{
				if (x == 0 || x == (WINSIZEX - 2))
				{
					SetCurserPosition(x, y, (char*)"��");
				}
			}

		}*/				
	}


}


//** �Էµ� (x, y)��ǥ�� ���ڿ� ���.
void SetCurserPosition(int _ix, int _iy, char* _str)
{
	//** ��ǥ�� ���� 
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
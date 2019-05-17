#include "Headers.h"

//** ������ 
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG };

//** ���, ����

//** ��������
SCENEID eSCENEID = SCENEID_LOGO;

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

void InitBullet(Object* _Bullet);
void BulletProgress(Object* _Bullet[]);
void BulletRender(Object* _Bullet[]);
void CreateBullet(Object* _Bullet[], Object* _pPlayer);

void SetCurserPosition(int _ix, int _iy, char* _str);

DWORD InputKey();

/*
 1���� ������Ʈ�� 3���� ������ �ʿ��� ������ 
 ��ġ��( ������), ũ�Ⱚ(������), ȸ����  (�����̼�)
*/

int main(void)
{
	Object* pPlayer = CreateObject();
	InitPlayter(pPlayer);	

	Object* Bullet[Bullet_MAX];

	for (int i = 0; i < Bullet_MAX; i++)
	{
		Bullet[i] = NULL;
	}

	Object* pMonster[MONSER_MAX];
	for (int i = 0; i < MONSER_MAX; i++)
	{
		pMonster[i] = CreateObject();
		InitMonster(pMonster[i]);
	}

	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 50 < GetTickCount())
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
		PlayerProgress(_pPlayer, _Bullet);
		PlayerRender(_pPlayer);

		BulletProgress(_Bullet);
		BulletRender(_Bullet);

		/*
		MonsterProgress(_pMonster);
		MonsterRender(_pMonster);
		*/
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
	_pPlayer->TransPos.Scale = Vector3(0.f, 0.f);
}


void PlayerProgress(Object* _pPlayer, Object* _Bullet[])
{
	DWORD dwKey = InputKey();

	if (dwKey & KEYID_UP)
		_pPlayer->TransPos.Position.y--;
	
	if (dwKey & KEYID_DOWN)
		_pPlayer->TransPos.Position.y++;

	if (dwKey & KEYID_LEFT)
		_pPlayer->TransPos.Position.x--;

	if (dwKey & KEYID_RIGHT)
		_pPlayer->TransPos.Position.x++;
	
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

void InitMonster(Object* _pMonster)
{
		_pMonster->TransPos.Position = Vector3(0.f, 0.f);
		_pMonster->TransPos.Scale = Vector3(0.f, 0.f);
		_pMonster->pName = (char*)"Monster";	
}


void MonsterProgress(Object* _pMonster[])
{
	for (int i = 0; i < MONSER_MAX; i++)
	{
		_pMonster[i]->TransPos.Position.x++;
		_pMonster[i]->TransPos.Position.y++;
		_pMonster[i]->TransPos.Scale.x++;
		_pMonster[i]->TransPos.Scale.y++;	
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

		printf_s("�г��� : %s\n", _pMonster[i]->pName);		
	}
}


void InitBullet(Object* _Bullet)
{
	_Bullet->TransPos.Position = Vector3(0.f, 0.f);
	
	_Bullet->TransPos.Scale = Vector3(0.f, 0.f);

	_Bullet->pName = (char*)"��ǳ";
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
			_Bullet[i]->TransPos.Position.x += 2;

			//** ���� ������ �Ŀ� x ��ǥ�� ������ǥ 95���� ũ�ٸ�...
			if (_Bullet[i]->TransPos.Position.x > 95)
			{
				//** ���� �Ҵ� ����.
				free(_Bullet[i]);

				//** �ʱ�ȭ/
				_Bullet[i] = NULL;			
			}
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

			//** ��� �۾��� ����� �� �ش� ���� Ż��.
			break;
		}
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
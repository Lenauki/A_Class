#include "MainUpdate.h"

class AAA
{
private:
	int Hp;
	int iAtt;
	int iDef;
public:
	void Initilize()
	{
		Hp = 100;
		iAtt = 10;
		iDef = 20;
	}
	int GetAtt() { return iAtt; }

	void SetHp(int iAtt) { Hp -= iAtt; }

};

class BBB
{
private:
	int iAtt;
	int iDef;
public:
};

int main(void)
{
	AAA a;
	BBB b;

	a;
	b;


	/*
	MainUpdate Main;
	Main.Initialize();

	while (true)
	{
		system("cls");

		Main.Progress();
		//Main.Render();

		system("pause");
	}
	*/
	
	return 0;
}

/*

�ּ� �л��� : 3��
�л� �߰� ����.
�л� ���� ����.
�л� ���� ���� ����.

*/
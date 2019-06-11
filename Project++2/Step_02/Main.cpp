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

최소 학생수 : 3명
학생 추가 가능.
학생 삭제 가능.
학생 정보 변경 가능.

*/
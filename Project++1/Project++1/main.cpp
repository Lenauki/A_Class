#include"Student.h"

// namespace std를 사용함 cout/ cin이 std 안에 포함대어있음
/*
namespace A
{
	void Output()
	{
		//printf_s("Player::Initialize\n");
		cout << "A::Output()\n";
	}
}
//using A::Output;

namespace B
{
	void Output()
	{		
		cout << "B::Output()\n";
	}
}
*/

//** :: namespace 연산자
// name space는 같은 이름의 변수(함수)를 같은 지역에서 사용할 수 있게 해준다.

//class는 namespace의 기능을 가지고 있다
//cout 출력 , cin 입력

Scene SceneID;
int iSC = 0;
int iChoice = 0;
int iCount = 0;

void SetScene(Student _Snt[]);

int main(void)
{
/*
	A::Output();
	B::Output();
*/	
	SceneID = 매뉴;
	Student Snt[Student_MAX];	

	while (true)
	{
		SetScene(Snt);
	}
		
	return 0;
}

void SetScene(Student _Snt[])
{
	switch (SceneID)
	{	
	case 매뉴:
		system("cls");
		cout << "1. 학생추가\n2. 학생 정보 변경\n3. 학생삭제\n4. 학생점수\n5. 모든학생점수" << endl;
		cout << "입력"; cin >> iChoice;

		if (iChoice == 1)
			SceneID = 학생추가;
		if (iChoice == 2)
			SceneID = 학생정보변경;
		if (iChoice == 3)
			SceneID = 학생삭제;
		if (iChoice == 4)
			SceneID = 학생점수;
		if (iChoice == 5)
			SceneID = 모든학생점수;
		break;
	
	case 학생추가:
		system("cls");

		/*cout << "\n입력 :"; cin >> iSC;
		
		_Snt[iSC-1].Initialize();*/

		_Snt[iSC - 1].Progress();
		iCount++;
		
		SceneID = 매뉴;
		system("pause");
		break;

	case 학생정보변경:
		system("cls");
	
		cout << "\n입력 :"; cin >> iSC;

			_Snt[iSC-1].Progress();

		SceneID = 매뉴;
		break;

	case 학생삭제:
		system("cls");
		cout << "학생삭제";
		cout << "\n입력 :"; cin >> iSC;
		_Snt[iSC-1].Initialize();
		
		SceneID = 매뉴;
		break;

	case 학생점수:	
		system("cls");	
		cout << "\n입력 :"; cin >> iSC;
			_Snt[iSC-1].Render();

			SceneID = 매뉴;
			system("pause");		
		break;	

	case 모든학생점수:
		system("cls");	
		for (int i = 0; i < iCount; i++)
		{		
				_Snt[i].Render();
		}

		SceneID = 매뉴;
			system("pause");
		break;		
	}
}

/*
최소 학생수 3명
학생추가가능
학생 삭제 가능
학생 정보 변경 가능
*/
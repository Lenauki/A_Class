#include"Student.h"

// namespace std�� ����� cout/ cin�� std �ȿ� ���Դ������
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

//** :: namespace ������
// name space�� ���� �̸��� ������ ���� �������� ����� �� �ְ� ���ش�.

//class�� namespace�� ����� ������ �ִ�

//cout ��� , cin �Է�

Scene SceneID;



void SetScene(Student _Snt[]);

int main(void)
{
/*
	A::Output();
	B::Output();
*/
	
	SceneID = �Ŵ�;
	Student Snt[3];
	
	while (true)
	{
		SetScene(Snt);
	}
	

	return 0;
}


void SetScene(Student _Snt[])
{
	int iChoice = 0;

	switch (SceneID)
	{	
	case �Ŵ�:
		system("cls");
		cout << "1. �л��߰�\n2. �л� ���� ����\n3. �л�����\n4. �л�����" << endl;
		cout << "�Է�"; cin >> iChoice;

		if (iChoice == 1)
			SceneID = �л��߰�;
		if (iChoice == 2)
			SceneID = �л���������;
		if (iChoice == 3)
			SceneID = �л�����;
		if (iChoice == 4)
			SceneID = �л�����;
		break;
	
	case �л��߰�:
		system("cls");
		for (int i = 0; i < 3; i++)
		{

			_Snt[i].Initialize();
		}
		SceneID = �Ŵ�;
		break;

	case �л���������:
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			_Snt[i].Progress();
		}
		
		SceneID = �Ŵ�;
		break;

	case �л�����:
		system("cls");
		cout << "�л�����";

		SceneID = �Ŵ�;
		break;

	case �л�����:
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			_Snt[i].Render();
		}
		break;	
	}
}


/*

�ּ� �л��� 3��
�л��߰�����
�л� ���� ����
�л� ���� ���� ����

*/
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
// name space�� ���� �̸��� ����(�Լ�)�� ���� �������� ����� �� �ְ� ���ش�.

//class�� namespace�� ����� ������ �ִ�
//cout ��� , cin �Է�

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
	SceneID = �Ŵ�;
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
	case �Ŵ�:
		system("cls");
		cout << "1. �л��߰�\n2. �л� ���� ����\n3. �л�����\n4. �л�����\n5. ����л�����" << endl;
		cout << "�Է�"; cin >> iChoice;

		if (iChoice == 1)
			SceneID = �л��߰�;
		if (iChoice == 2)
			SceneID = �л���������;
		if (iChoice == 3)
			SceneID = �л�����;
		if (iChoice == 4)
			SceneID = �л�����;
		if (iChoice == 5)
			SceneID = ����л�����;
		break;
	
	case �л��߰�:
		system("cls");

		/*cout << "\n�Է� :"; cin >> iSC;
		
		_Snt[iSC-1].Initialize();*/

		_Snt[iSC - 1].Progress();
		iCount++;
		
		SceneID = �Ŵ�;
		system("pause");
		break;

	case �л���������:
		system("cls");
	
		cout << "\n�Է� :"; cin >> iSC;

			_Snt[iSC-1].Progress();

		SceneID = �Ŵ�;
		break;

	case �л�����:
		system("cls");
		cout << "�л�����";
		cout << "\n�Է� :"; cin >> iSC;
		_Snt[iSC-1].Initialize();
		
		SceneID = �Ŵ�;
		break;

	case �л�����:	
		system("cls");	
		cout << "\n�Է� :"; cin >> iSC;
			_Snt[iSC-1].Render();

			SceneID = �Ŵ�;
			system("pause");		
		break;	

	case ����л�����:
		system("cls");	
		for (int i = 0; i < iCount; i++)
		{		
				_Snt[i].Render();
		}

		SceneID = �Ŵ�;
			system("pause");
		break;		
	}
}

/*
�ּ� �л��� 3��
�л��߰�����
�л� ���� ����
�л� ���� ���� ����
*/
#include "Heders.h"


//** ������
//enum { AAA, BBB, CCC, DDD, EEE, FFF, GGG }; 
//*** �������� ���,
enum SCENEID 
{ 
	�޴�			,
	�л��߰�		, 
	�л�����		, 
	�л��������� ,
};
//��������
SCENEID eSCENEID = �޴�;

//** �Լ� ���漱��
void SetScene();
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{

	//** ���� �Ҵ�

	//��� ����	
	



	/*
	Student* ptStudent[3];


	for (int i = 0; i < 3; i++)
	{
		ptStudent[i] = CreateStudent();
	}

	for (int i = 0; i < 3; i++)
	{
		Render(ptStudent[i]);
	}
	*/
	/*while (true)

	{

		system("cls");
		SetScene();

	}
	
	*/	
	system("pause");
	

	//printf_s("%d\n", Student.iEng);
	//printf_s("%d\n", Student.iKor);
	//printf_s("%d\n", Student.iMath);

	return 0;
}

void SetScene()
{
	switch (eSCENEID)
	{

	case �޴�:
	{

		printf_s("1, �л� �߰�\n");
		printf_s("2, �л� ����\n");
		printf_s("3, �л� ���� ����\n");

		int iChoice = 0;
		printf_s("�Է� : ");
		scanf_s("%d", &iChoice);




		if (iChoice == 1)
			eSCENEID = �л��߰�;
		else if (iChoice == 2)
			eSCENEID = �л�����;
		else if (iChoice == 3)
			eSCENEID = �л���������;


	}
	break;

	case �л��߰�:
		system("cls");
		printf_s("�л� �߰� �޴�\n");
		eSCENEID = �޴�;
		system("pause");

		break;
	case �л�����:
		system("cls");
		printf_s("�л� ���� �޴�\n");
		eSCENEID = �޴�;
		system("pause");
		break;

	case �л���������:
		system("cls");
		printf_s("�л� ���� ���� �޴�\n");
		eSCENEID = �޴�;
		system("pause");
		break;
	}


}



Student* CreateStudent()
{

	for (int i = 0; i < 3; i++)
	{

		Student* pStudent = (Student*)malloc(sizeof(Student));



		Initialize(pStudent);
		return pStudent;

	}
	

	
	
}

void Initialize(Student* _pStudent)
{

	
		_pStudent->pName = SetName();

		//** �� ���� �Է�
		printf_s("���� ���� �Է� : ");
		scanf_s("%d", &_pStudent->iKor);

		printf_s("���� ���� �Է� : ");
		scanf_s("%d", &_pStudent->iEng);

		printf_s("���� ���� �Է� : ");
		scanf_s("%d", &_pStudent->iMath);
	
	
}





char* SetName()
{

	//** ���ڿ� �Է�
	char str[128] = "";

	printf_s("�̸� �Է� : ");
	scanf_s("%s", str, 128);

	//** ���ڿ� ����
	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;

}




void Render(Student* _pStudent)
{

	//** �� ���� ���
	printf_s("\n\n** ���� ��� **\n\n");
	printf_s("�л� �̸� : %s\n", _pStudent->pName);
	printf_s("���� ���� : %d\n", _pStudent->iKor);
	printf_s("���� ���� : %d\n", _pStudent->iEng);
	printf_s("���� ���� : %d\n", _pStudent->iMath);
	printf_s("\n");


}
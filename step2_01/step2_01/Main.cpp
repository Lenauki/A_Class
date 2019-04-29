#include "Heders.h"




//** �Լ� ���漱��
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{
	//** ���� �Ҵ�
	
	Student* pStudent = CreateStudent();
	
	Render(pStudent);


	


	system("pause");

	return 0;
}





Student* CreateStudent()
{
	Student* pStudent = (Student*)malloc(sizeof(Student));

	Initialize(pStudent);

	return pStudent;
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
#include "Heders.h"




//** 함수 전방선언
char* SetName();
Student* CreateStudent();
void Initialize(Student* _pStudent);
void Render(Student* _pStudent);


int main(void)
{
	//** 동적 할당
	
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

	//** 각 점수 입력
	printf_s("국어 점수 입력 : ");
	scanf_s("%d", &_pStudent->iKor);

	printf_s("영어 점수 입력 : ");
	scanf_s("%d", &_pStudent->iEng);

	printf_s("수학 점수 입력 : ");
	scanf_s("%d", &_pStudent->iMath);
}

char* SetName()
{

	//** 문자열 입력
	char str[128] = "";

	printf_s("이름 입력 : ");
	scanf_s("%s", str, 128);

	//** 문자열 복사
	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;

}




void Render(Student* _pStudent)
{

	//** 각 점수 출력
	printf_s("\n\n** 점수 출력 **\n\n");
	printf_s("학생 이름 : %s\n", _pStudent->pName);
	printf_s("국어 점수 : %d\n", _pStudent->iKor);
	printf_s("영어 점수 : %d\n", _pStudent->iEng);
	printf_s("수학 점수 : %d\n", _pStudent->iMath);
	printf_s("\n");


}
#include<stdio.h>
#include<stdlib.h>


/**********************
���α׷��� ���� ����Ʈ
https://programmers.co.kr/
**********************/



/********************************************
	
		����ü�� ��� �뵵�� ����� �����͵���
	�ϳ��� �������� ���� �� �� �ְ� ���ش�.


********************************************/


// ����ü
struct tagStudent  //����ü �̸�
{

	int iKor;
	int iEng;
	int iMath;


};

//tag �� ����ü �̸��� ���� �̸��� �ߺ��� ����


int main(void)
{
	
	/*tagStudent tStudent;

	tStudent.iKor	= 10;
	tStudent.iEng	= 15;
	tStudent.iMath	= 103;
	

	printf_s("%d\n", tStudent.iKor);
	printf_s("%d\n", tStudent.iEng);
	printf_s("%d\n", tStudent.iMath);



	*/



	tagStudent tStudent[3];
	
	tStudent[0].iKor	= 1;
	tStudent[0].iEng	= 2;
	tStudent[0].iMath	= 3;

	tStudent[1].iKor	= 10;
	tStudent[1].iEng	= 20;
	tStudent[1].iMath	= 30;


	tStudent[2].iKor	= 100;
	tStudent[2].iEng	= 200;
	tStudent[2].iMath	= 300;


	for (int i = 0; i < 3; i++)
	{

		printf_s("���� ���� : %d\n",tStudent[i].iKor);
		printf_s("���� ���� : %d\n",tStudent[i].iEng);
		printf_s("���� ���� : %d\n",tStudent[i].iMath);
		printf_s("\n");

	}


	
	for (int i = 0; i < 3; i++)
	{
		printf_s("���������� �Է����ּ��� : ");
		scanf_s("%d", &tStudent[i].iKor);
		printf_s("���������� �Է����ּ��� : ");
		scanf_s("%d", &tStudent[i].iEng);
		printf_s("���������� �Է����ּ��� : ");
		scanf_s("%d", &tStudent[i].iMath);



	}
	for (int j=0; j < 3; j++)
	{
		printf_s("���� ���� : %d \n", tStudent[j].iKor);
		printf_s("���� ���� : %d \n", tStudent[j].iEng);
		printf_s("���� ���� : %d \n", tStudent[j].iMath);



	}

	system("pause");

	return 0;

}
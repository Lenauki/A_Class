#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct tagStatus
{
	int iValue;
	char cpString[128];

};



/*********************************************

	**	# ���� �����ϴ� ���� ��ó�� ���ù��̴�.

	** [��ó�� ���ù�]


		* #include
		* #define
		* #if, #else, #endif

		\�� �����ٱ��� �����ϴ� ����� �ϱ⵵ �Ѵ�.

		��ũ�μ� �������� �����ݷ��� ���� �ʾƵ� �ȴ�.

*********************************************/

/*
#define DEBUG 0-

#define SUM(x1, x2) printf_s("%d\n", x1 + x2)
#define STRING(str) printf_s("%s\n", str)

*/

/*
#define failed 0

#define ERR_MESSAGE(cond)\
	if( !(cond) )\
	{\
		printf("���� %d, file(%s)\n", __LINE__, __FILE__);\
	}
*/
/*
#define WHILE(cond) \
	{\
		int i = 0; \
		WHILE:\
			i++; \
			  printf_s("goto ���� ����Ͽ� �̷��� �ݺ��� �� �ֽ��ϴ�.\n"); \
\
			  if (i < cond)\
				  goto WHILE; \
			  else\
				  goto EXIT; \
		EXIT:\
			  printf_s("���� �Ǿ����ϴ�.\n");\
	}
*/









int main(void)
{

	/*ERR_MESSAGE(failed);

	
	SUM(10, 20);
	STRING("Hello World!!");
	WHILE(10);
*/
/******************************************

	** do ~ while

	* ������ 1ȸ ����ǰ� ������ Ȯ���Ͽ�
		�ݺ��������� ����.

******************************************/



/*
	int i = 0;

	do
	{

		printf_s("%02d\n", i++);


	} while (i < 10);

*/



/*
	do
	{
		printf_s("�ϴ� �� �� ����˴ϴ�.");
	} while (false);

*/
	



/*************************************
	** [���� ������]

	* (����) ? true ; false


*************************************/


/*
	
	int iTemp = 10;
	int iDest = 20;
	printf_s("%s ���� �� Ů�ϴ�.\n\n", (iTemp < iDest) ? "iTemp" : "iDest");

*/
/*	
	int iTemp = 30;
	int iDest = 25;

	if ((iTemp > iDest) ? true : false)
		printf_s("iTemp ���� �� ũ�Ƿ� �ش� ������ true �Դϴ�. \n\n");


	else
		printf_s("iDest ���� �� ũ�Ƿ� �ش� ������ false �Դϴ�. \n\n");
	
*/
	
/*
int iNumber = 1;

	printf_s("iNumber_01 << 1 : %d\n", iNumber << 1);
	printf_s("iNumber_01 << 2 : %d\n", iNumber << 2);
	printf_s("iNumber_02 << 1 : %d\n", iNumber << 3);
	printf_s("iNumber_02 << 2 : %d\n", iNumber << 4);
	printf_s("\n");



	iNumber <<= 5;
	printf_s("iNumber_01 <<=3 :%d\n", iNumber);
*/
	
	
	for (int i= 0; i < 51; i++)
	{
		printf_s("%d", i);

		if ((i % 3)== 0)
			printf_s(" Fizz");
		if ((i % 5)== 0);
			printf_s(" Buzz");

		printf_s("\n");
	}
	


	FILE *pFile = fopen("../Data/Status.txt", "w");

	fprintf(pFile,"���ݷ� %d\n",100);
	fprintf(pFile,"ü�� %d\n",200);
	fprintf(pFile,"���� %d\n",50);
	fprintf(pFile,"���� %d\n",50);
	fclose(pFile);


	

	tagStatus tUser[4];

	FILE *pFile = fopen("../Data/Status.txt", "r");

	fscanf(pFile, "%s %d", &tUser[0].cpString, &tUser[0].iValue);
	fscanf(pFile, "%s %d", &tUser[1].cpString, &tUser[1].iValue);
	fscanf(pFile, "%s %d", &tUser[2].cpString, &tUser[2].iValue);
	fscanf(pFile, "%s %d", &tUser[3].cpString, &tUser[3].iValue);
	fclose(pFile);


	for (int i = 0; i < 4; i++)
	{
		printf_s("%s : %d\n", tUser[i].cpString, tUser[i].cpString);
	}


	system("pause");			
	return 0;
}
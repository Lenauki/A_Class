#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct tagStatus
{
	int iValue;
	char cpString[128];

};



/*********************************************

	**	# 으로 시작하는 것은 전처리 지시문이다.

	** [전처리 지시문]


		* #include
		* #define
		* #if, #else, #endif

		\은 다음줄까지 연결하는 기능을 하기도 한다.

		매크로성 문구에는 세미콜론을 쓰지 않아도 된다.

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
		printf("에러 %d, file(%s)\n", __LINE__, __FILE__);\
	}
*/
/*
#define WHILE(cond) \
	{\
		int i = 0; \
		WHILE:\
			i++; \
			  printf_s("goto 문을 사용하여 이렇게 반복할 수 있습니다.\n"); \
\
			  if (i < cond)\
				  goto WHILE; \
			  else\
				  goto EXIT; \
		EXIT:\
			  printf_s("종료 되었습니다.\n");\
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

	* 무조건 1회 실행되고 조건을 확인하여
		반복실행할지 결정.

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
		printf_s("일단 한 번 실행됩니다.");
	} while (false);

*/
	



/*************************************
	** [삼항 연산자]

	* (조건) ? true ; false


*************************************/


/*
	
	int iTemp = 10;
	int iDest = 20;
	printf_s("%s 값이 더 큽니다.\n\n", (iTemp < iDest) ? "iTemp" : "iDest");

*/
/*	
	int iTemp = 30;
	int iDest = 25;

	if ((iTemp > iDest) ? true : false)
		printf_s("iTemp 값이 더 크므로 해당 조건은 true 입니다. \n\n");


	else
		printf_s("iDest 값이 더 크므로 해당 조건은 false 입니다. \n\n");
	
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

	fprintf(pFile,"공격력 %d\n",100);
	fprintf(pFile,"체력 %d\n",200);
	fprintf(pFile,"방어력 %d\n",50);
	fprintf(pFile,"마나 %d\n",50);
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
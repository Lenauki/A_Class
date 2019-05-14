#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>//malloc 동적할당 함수를 사용하기 위해 포함
#include<time.h>//time 함수를 사용하기 위해 포함, 컴퓨터에 내장된 시간을 받아오는 함수.



typedef struct tagStudent
{

	int iKor;
	int iEng;
	int iMath;

}Student;

typedef struct tagNumbers
{

	int iNumber[6];
	
}Numbers;

int main(void)
{

	//** 구조체 포인터
	/****************************************************
	구조체 포인터는 구조체 변수의 주소를 가지고 있다.
	****************************************************/

	/*Student* ptStudent = (Student*)malloc(sizeof(Student));

	

	ptStudent->iKor		= 0;
	ptStudent->iEng		= 0;
	ptStudent->iMath	= 0;


	printf_s("%d\n", ptStudent->iKor);
	printf_s("%d\n", ptStudent->iEng);
	printf_s("%d\n", ptStudent->iMath);





	system("pause");
	*/


	//** 구조체 포인터 배열


	/*Student* ptStudent[3];
	

	for(int i = 0; i < 3; i++)
	{ 
	ptStudent[i] = (Student*)malloc(sizeof(Student));
	ptStudent[i]->iKor	= 0;
	ptStudent[i]->iEng	= 0;
	ptStudent[i]->iMath = 0;

	}

	for(int i = 0; i < 3; i++)
	{ 

	printf_s("%d\n", ptStudent[i]->iKor);
	printf_s("%d\n", ptStudent[i]->iEng);
	printf_s("%d\n", ptStudent[i]->iMath);

	}

	system("pause");
	*/

	//srand 난수 생성함수의 기본값을 초기화 하는 함수.
	//rand 난수 생성함수


	//난수 생성
	/*srand(time(NULL));
	
	int iRand = rand();

	printf_s("%d\n", iRand);
	system("pause");
	*/

	/*******************************

		** 실습 : [구조체 포인터 배열 사용]

		*로또 번호 생성 프로그램 만들기

		요구사항
		A. 숫자는 1부터 45까지의 정수로 한다.

		B. 숫자는 하나의 조합당 6개를 포함하고
			중복된 수는 갖지 않는다.

		C. 5개의 조합을 만들고,
			조합간의 중복된 수는 상관없다.

	*******************************/


	srand(time(NULL));

	Numbers* ptNumberList[5];

	for (int i = 0; i < 5; i++)
	{
		ptNumberList[i] = (Numbers*)malloc(sizeof(Numbers));

		for (int j = 0; j < 6; j++)
		{
			ptNumberList[i]->iNumber[j] = rand() % 45 + 1;
		}
	}





	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = j + 1; k < 6; k++)
			{
				if (ptNumberList[i]->iNumber[j] == ptNumberList[i]->iNumber[k])
				{
					int l = 0, iTempNumber = rand() % 45 + 1;

					while (j >= l)
					{
						if (ptNumberList[i]->iNumber[l] == iTempNumber)
						{
							iTempNumber = rand() % 45 + 1;
							l--;
						}
						else
						{
							ptNumberList[i]->iNumber[j] = iTempNumber;
							break;
						}
						l++;
					}
				}
			}
		}
	}






	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = j + 1; k < 6; k++)
			{
				if (ptNumberList[i]->iNumber[j] > ptNumberList[i]->iNumber[k])
				{
					int iTemp = ptNumberList[i]->iNumber[j];
					ptNumberList[i]->iNumber[j] = ptNumberList[i]->iNumber[k];
					ptNumberList[i]->iNumber[k] = iTemp;
				}
			}
		}
	}






	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf_s("%d ", ptNumberList[i]->iNumber[j]);
		}
		printf_s("\n\n");
	}
	
	system("pause");

	return 0;
}
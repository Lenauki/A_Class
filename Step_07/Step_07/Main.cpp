#include<stdio.h>
#include<stdlib.h>


/*
	**구조체 포인터 규칙
	1. *  데이터 & 주소반환
	2. 포인터는 항상 동적할당을 해야한다.
	3.  . 아니면 -> 로 표시된다.
*/




int main(void)


	{
		/*********************
			* 배열과 포인터
		**********************/

		//**  [실습]
		/*
		int iNum1 = 10;
		int iNum2 = 20;

		iNum1 = iNum2;



		int *piNum1 = &iNum1;
		int *piNum2;

		piNum2 = piNum1;
		*/




		/*
		int iArray[5] = { 0, 1, 2, 3, 4 };

		int *piPointer = iArray;

		printf_s("%d\n", *(piPointer++));
		printf_s("%d\n", *(piPointer++));
		printf_s("%d\n", *(piPointer));
		printf_s("%d\n", *(piPointer + 1));
		printf_s("%d\n", *(piPointer + 2));
		printf_s("%d\n", *(piPointer + 3));	// <= 쓰레기 값

		system("pause");
		*/







		/*
		int iArray[5] = { 0, 1, 2, 3, 4 };
		int *piPointer = iArray;

		for (int i = 0; i < 5; i++)
		{
			printf_s("%d\n", *(piPointer + i));
		}
		system("pause");
		*/



		/*
		int iArray[5] = { 0, 1, 2, 3, 4 };
		int* piter = iArray;

		for (int i = 0; i < 5; i++)
		{
			printf_s("%d\n", *(piter + i));
		}
		system("pause");
		*/



		/*
		int iArray[5] = { 0, 1, 2, 3, 4 };
		int *piPointer = iArray;

		for (int i = 0; i < 5; i++)
		{
			printf_s("%d\n", piPointer[i]);
		}
		system("pause");
		*/



		/********************************************************
			** [배열과 문자열]

			* [PPT 참고 ->  (../Resource/배열_문자열.png)]

		********************************************************/

		//**  [실습]

		/*
		char iArray[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
		char* piter = iArray;

		for (int i = 0; i < 6; i++)
		{
			printf_s("%c", *(piter + i));
		}
		printf_s("\n");

		printf_s("%s\n", iArray);

		system("pause");
		*/



		/*
		char cString[] = { 'H', 'i', 0, 'T', 'h', 'e', 'r', 'e', 32 };

		for (int i = 0; i < 9; i++)
		{
			printf_s("%c", cString[i]);
		}
		printf_s("\n");

		printf_s("%s\n", cString);

		system("pause");
		*/


		/********************************************************
			** [포인터 문자열]

			* [PPT 참고 ->  (.. / Resource / 배열_문자열.png)]

		********************************************************/

		//**  [실습]

		/*
		char* pcString = (char*)"홍길동";

		printf_s("%s", pcString);
		printf_s("%d\n", sizeof(pcString));

		printf_s("%d\n", sizeof(__int64));



		system("pause");
		*/



	char* pcString = (char*)"홍길동";

	/*****************************************************
		포인터로 형변환을 하면 배열의 길이와 상관없이 같으며
		운영체제가 64bit면 포인터의 크기는 8Byte이고,
		32bit이면 4Byte 이다.

	*******************************************************/




	printf_s("%s", pcString);
	printf_s("\n");


	system("pause");

}
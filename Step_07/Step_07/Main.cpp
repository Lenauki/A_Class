#include<stdio.h>
#include<stdlib.h>


/*
	**����ü ������ ��Ģ
	1. *  ������ & �ּҹ�ȯ
	2. �����ʹ� �׻� �����Ҵ��� �ؾ��Ѵ�.
	3.  . �ƴϸ� -> �� ǥ�õȴ�.
*/




int main(void)


	{
		/*********************
			* �迭�� ������
		**********************/

		//**  [�ǽ�]
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
		printf_s("%d\n", *(piPointer + 3));	// <= ������ ��

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
			** [�迭�� ���ڿ�]

			* [PPT ���� ->  (../Resource/�迭_���ڿ�.png)]

		********************************************************/

		//**  [�ǽ�]

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
			** [������ ���ڿ�]

			* [PPT ���� ->  (.. / Resource / �迭_���ڿ�.png)]

		********************************************************/

		//**  [�ǽ�]

		/*
		char* pcString = (char*)"ȫ�浿";

		printf_s("%s", pcString);
		printf_s("%d\n", sizeof(pcString));

		printf_s("%d\n", sizeof(__int64));



		system("pause");
		*/



	char* pcString = (char*)"ȫ�浿";

	/*****************************************************
		�����ͷ� ����ȯ�� �ϸ� �迭�� ���̿� ������� ������
		�ü���� 64bit�� �������� ũ��� 8Byte�̰�,
		32bit�̸� 4Byte �̴�.

	*******************************************************/




	printf_s("%s", pcString);
	printf_s("\n");


	system("pause");

}
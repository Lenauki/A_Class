#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>//malloc �����Ҵ� �Լ��� ����ϱ� ���� ����
#include<time.h>//time �Լ��� ����ϱ� ���� ����, ��ǻ�Ϳ� ����� �ð��� �޾ƿ��� �Լ�.



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

	//** ����ü ������
	/****************************************************
	����ü �����ʹ� ����ü ������ �ּҸ� ������ �ִ�.
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


	//** ����ü ������ �迭


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

	//srand ���� �����Լ��� �⺻���� �ʱ�ȭ �ϴ� �Լ�.
	//rand ���� �����Լ�


	//���� ����
	/*srand(time(NULL));
	
	int iRand = rand();

	printf_s("%d\n", iRand);
	system("pause");
	*/

	/*******************************

		** �ǽ� : [����ü ������ �迭 ���]

		*�ζ� ��ȣ ���� ���α׷� �����

		�䱸����
		A. ���ڴ� 1���� 45������ ������ �Ѵ�.

		B. ���ڴ� �ϳ��� ���մ� 6���� �����ϰ�
			�ߺ��� ���� ���� �ʴ´�.

		C. 5���� ������ �����,
			���հ��� �ߺ��� ���� �������.

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
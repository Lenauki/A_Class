#include<stdio.h>
#include<stdlib.h>
#include<windows.h>// Sleep, GetTickCount (�ð��� õ���� �Ϸ� ��ȯ�ϴ� �Լ�) �Լ��� ����� �� �ִ�




/*
if((�ð��� �ܸ� + 1��)<����ð�)
{
	�ð��� �ܸ� = ���� �ð�
}
*/



int main(void)
{
	DWORD dwTime = GetTickCount();
	int iCount = 0;

	//�ð��� �ܸ� = ���� �ð� 
	while (true)
	{


		if (dwTime +1000 < GetTickCount())
		{			
			dwTime = GetTickCount();
			system("cls");
			printf_s("%d\n", iCount++);
		}

		 

	}


	system("pause");

	return 0;
}
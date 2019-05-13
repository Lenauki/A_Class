#include<stdio.h>
#include<stdlib.h>
#include<windows.h>// Sleep, GetTickCount (시간을 천분의 일로 반환하는 함수) 함수를 사용할 수 있다




/*
if((시간의 단면 + 1초)<현재시간)
{
	시간의 단면 = 현재 시간
}
*/



int main(void)
{
	DWORD dwTime = GetTickCount();
	int iCount = 0;

	//시간의 단면 = 현재 시간 
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
#include<stdio.h>
#include<stdlib.h>



int main(void)
{


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
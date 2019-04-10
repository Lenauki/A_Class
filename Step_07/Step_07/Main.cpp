#include<stdio.h>
#include<stdlib.h>



int main(void)
{


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
#include <stdio.h>
#include <stdlib.h> //** system() = 함수 사용이 가능




int main(void)
{
	//** [주석] - 컴파일러가 코드로 인식하지 않는 메모 수단


	//한줄 주석 입니다.

	/*
		여러줄 주석 입니다.
	*/
	
	
	
	/****************************************************************
		Data Type

		** [정수형]
	
		signed	 - 부호가 있음
		unsigned - 부호가 없음

		* signed char	- 1 Byte
		* signed short  - 2 Byte
		* signed int    - 4 Byte
		* signed long   - 4 Byte

		* unsigned char  - 1 Byte
		* unsigned short - 2 Byte
		* unsigned int   - 4 Byte
		* unsigned long  - 4 Byte



		**[실수형]

		* float
		* double
		* long double

		[signed, unsigned] - 실수형에는 별도로 없음.

		** 아래쪽에서 확인해보자

		부동소수점, 고정소수점 검색


	****************************************************************/
	
	
	
	
	
	
	//** sizeof() - 데이터를 바이트 단위로 반환. (반환시 정수형태)
	printf_s("[정수형] singed type\n");
	printf_s("char Type : %d Byte 입니다.\n", sizeof(char));
	printf_s("short Type : %d Byte 입니다.\n", sizeof(short));
	printf_s("int Type : %d Byte 입니다.\n", sizeof(int));
	printf_s("long Type : %d Byte 입니다.\n", sizeof(long));
	printf_s("\n");
	printf_s("[정수형] unsinged type\n");
	printf_s("char Type : %d Byte 입니다.\n", sizeof(unsigned char));
	printf_s("short Type : %d Byte 입니다.\n", sizeof(unsigned short));
	printf_s("int Type : %d Byte 입니다.\n", sizeof(unsigned int));
	printf_s("long Type : %d Byte 입니다.\n", sizeof(unsigned long));
	printf_s("\n");
	printf_s("[실수형]\n");
	printf_s("float Type : %d Byte 입니다.\n", sizeof(float));
	printf_s("double Type : %d Byte 입니다.\n", sizeof(double));
	

	system("pause"); //** 일시 정지 함수
	system("cls"); //** 화면을 지워주는 함수



	/*******************************************************************
		선언

		1.널리 펴서 말함. 또는 그런 내용.
		2. 국가나 집단이 자기의 방침, 의견 , 주장 따위를 말함.


		정의

		1. 어떤 말이나 사물의 뜻을 명백히 밝혀 규정하다


	*******************************************************************/

	/******************************************************************
		Data 단위 확인

		https://indevgame.tistory.com/9?category-831189

	******************************************************************/


	//** 선언
	int a;

	//** 초기화
	a = 0;

	// 00000000 00000000 00000000 00000000

	//** 선언과 동시에 초기화
	int b = 0;
	
	//** 여러개의 변수를 선언할 수 있다.
	int c, d;

	//** 여러개의 변수를 초기화 할 수 있다.
	c = 0, d = 0;

	//** 여러개의 변수를 선언과 동시에 초기화 할 수 있다.
	int e = 0, f = 0;

	/*************************************************************
	
		헝가리안 표기법

		1. 네이버 검색창에서 [헝가리안 표기법] 검색
		2. 이미지 클릭
		3. 헝가리안 표기법 표 확인.

		변수 생성 주의 사항
		
		1. 동일한 이름으로 생성 불가.
		2. 변수 이름을 특수문자로 시작 할 수 없다.
		3. 변수 이름을 숫자로 시작 할 수 없다.
		4. 변수 이름 사이에 띄워쓰기를 할 수 없다.
	
	***********************************************************/

	//** 잘못된 예
	/****************************************************************************

		int [#Attack = 10] 과 같이 특수 문자로 시작 할 수 없다.
		int [10Attack = 10] 과 같이 숫자로 시작 될 수 없다.
		int [Player Attack = 10] 과 같이 변수 이름 사이에 띄워쓰기를 할 수 없다.

	*****************************************************************************/

	//** 좋은 예


	printf_s("\n");


	int iScore = 0;

	printf_s("Score : %d 점 입니다.\n", iScore);

	system("pause");



	return 0;


}
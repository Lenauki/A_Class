#include<stdio.h>
#include<stdlib.h>


/**********************
프로그래밍 연습 사이트
https://programmers.co.kr/
**********************/



/********************************************
	
		구조체는 사용 용도가 비슷한 데이터들을
	하나의 묶음으로 관리 할 수 있게 해준다.


********************************************/


// 구조체
struct tagStudent  //구조체 이름
{

	int iKor;
	int iEng;
	int iMath;


};

//tag 를 구조체 이름에 적어 이름의 중복을 방지


int main(void)
{
	
	/*tagStudent tStudent;

	tStudent.iKor	= 10;
	tStudent.iEng	= 15;
	tStudent.iMath	= 103;
	

	printf_s("%d\n", tStudent.iKor);
	printf_s("%d\n", tStudent.iEng);
	printf_s("%d\n", tStudent.iMath);



	*/



	tagStudent tStudent[3];
	
	tStudent[0].iKor	= 1;
	tStudent[0].iEng	= 2;
	tStudent[0].iMath	= 3;

	tStudent[1].iKor	= 10;
	tStudent[1].iEng	= 20;
	tStudent[1].iMath	= 30;


	tStudent[2].iKor	= 100;
	tStudent[2].iEng	= 200;
	tStudent[2].iMath	= 300;


	for (int i = 0; i < 3; i++)
	{

		printf_s("국어 점수 : %d\n",tStudent[i].iKor);
		printf_s("영어 점수 : %d\n",tStudent[i].iEng);
		printf_s("수학 점수 : %d\n",tStudent[i].iMath);
		printf_s("\n");

	}


	
	for (int i = 0; i < 3; i++)
	{
		printf_s("국어점수를 입력해주세요 : ");
		scanf_s("%d", &tStudent[i].iKor);
		printf_s("영어점수를 입력해주세요 : ");
		scanf_s("%d", &tStudent[i].iEng);
		printf_s("수학점수를 입력해주세요 : ");
		scanf_s("%d", &tStudent[i].iMath);



	}
	for (int j=0; j < 3; j++)
	{
		printf_s("국어 점수 : %d \n", tStudent[j].iKor);
		printf_s("수학 점수 : %d \n", tStudent[j].iEng);
		printf_s("영어 점수 : %d \n", tStudent[j].iMath);



	}

	system("pause");

	return 0;

}
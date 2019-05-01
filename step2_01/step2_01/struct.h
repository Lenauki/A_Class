#pragma once

typedef struct tagStudent
{
	char* pName;
	int iKor;
	int iEng;
	int iMath;

	//** 생성됨과 동시에 호출 됨.
	//** 생성자. 호출하지 않아도 알아서 생성되는 것
	tagStudent() 
	{	
		iKor	= 0;
		iEng	= 0;
		iMath	= 0;
		printf_s("생성되었습니다.\n");
	};

	//** 복사 생성자 
	// 사용자가 호출할 때 호출됨.
	// 같은형태를 같은 개수로 할 수 없다.
	tagStudent(int _iKor, int _iEng, int _iMath)
	{
		iKor	= _iKor;
		iEng	= _iEng;
		iMath	= _iMath;
		printf_s("복사생성 되었습니다.\n");
	};


}Student;

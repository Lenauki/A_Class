#pragma once

typedef struct tagObject
{
	char* pName;


	int iAtt;
	int iDef;

	int iHP;
	int iMP;

	

	//** 생성됨과 동시에 호출 됨.
	tagObject() //** 생성자.
	{
		
	};

	//** 사용자가 호출 할 때 호출 됨.
	tagObject(int _iAtt, int _iDef, int _iHP, int _iMP)
		: iAtt(_iAtt), iDef(_iDef), iHP(_iHP), iMP(_iMP)	{};

}Object;


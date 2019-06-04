#pragma once
#include"Headers.h"





//헝가리안표기법 m_ 클래스의 멤버 변수를 의미
class Student
{
private:
	//**변수선언

	Score m_tInfo;
	

	//protected: 상속
public:
	//** 함수 선언
	void Initialize();
	void Progress();
	void Render();
	void Release();

public:
	Student();
	~Student();
};
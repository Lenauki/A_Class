#pragma once
#include "Headers.h"

class Student
{
private:
	//** 변수선언
	Score m_tInfo;
public:
	//** 함수 선언
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	Score GetInfo() { return m_tInfo; }
public:
	Student();
	~Student();
};
#pragma once
#include "Headers.h"

class Student
{
private:
	//** ��������
	Score m_tInfo;
public:
	//** �Լ� ����
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
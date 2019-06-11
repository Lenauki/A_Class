#pragma once
#include "Headers.h"

class Student;
class MainUpdate
{
private:
	Student* m_ptInfo[MAX_STUDENT];
	int m_iCount; 
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};


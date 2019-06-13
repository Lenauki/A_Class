#pragma once
#include"Headers.h"

class Student;
class MainUpdate
{

private:
	Student* m_ptInfo[MAX_STUDENT];
	int m_iCount;


public:
	void Initalize();
	void Progress();
	void Render();
	void Releze();



public:
		MainUpdate() ;
		~MainUpdate() ;	
};


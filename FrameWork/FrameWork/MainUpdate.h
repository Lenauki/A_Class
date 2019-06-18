#pragma once
#include"Headers.h"

class Object;
class MainUpdate
{

private:

	Object* m_ptInfo[MAX_STUDENT];
	int m_iCount;
	int iChoice, i;

public:
	void Initalize();
	void Progress();
	void Render();
	void Releze();
	void StudentRender();
	void StudentDelete();
	void StudentProgress();
	void StudentAverage();
	void StudentALLAverage();


public:
		MainUpdate() ;
		~MainUpdate() ;	
};


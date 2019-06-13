#pragma once
#include"Headers.h"
class Object
{
private:
	//** 변수선언
	INFO m_tInfo;
public:
	void Initalize();
	void Progress();
	void Render();
	void Releze();



public:
	Object() ;
	~Object() ;


};
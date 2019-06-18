#pragma once
#include"Headers.h"
class Object
{
private:
	//** 변수선언
	INFO m_tInfo;
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render();
	virtual void Releze();
	virtual	void Average();
	
public:
	INFO GetInfo() { return m_tInfo; }

public:
	Object() ;
	~Object() ;


};
#pragma once
#include"Headers.h"
class Object
{
private:
	//** ��������
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
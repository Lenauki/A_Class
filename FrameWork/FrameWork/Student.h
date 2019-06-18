#pragma once

#include "Object.h"
class Student : public Object
{

private:
	INFO m_tInfo;
	int iTotal;
	int iAverage;
	int iATotal;
	int iAAR;
public:
	virtual void  Initalize()override;
	virtual void  Progress()override;
	virtual void  Render()override;
	virtual void  Releze()override;
	virtual	void Average()override;
	


public:
	INFO GetInfo() { return m_tInfo; }
public:
	Student();
	~Student() ;
};


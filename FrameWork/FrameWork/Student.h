#pragma once

#include "Object.h"
class Student : public Object
{

private:
	//** ��������
	INFO m_tInfo;

public:
	void Initalize();
	void Progress();
	void Render();
	void Releze();

public:
	INFO GetInfo() { return m_tInfo; }

public:
	Student();
	~Student() ;



};


#pragma once
#include"Headers.h"





//�밡����ǥ��� m_ Ŭ������ ��� ������ �ǹ�
class Student
{
private:
	//**��������

	Score m_tInfo;
	

	//protected: ���
public:
	//** �Լ� ����
	void Initialize();
	void Progress();
	void Render();
	void Release();

public:
	Student();
	~Student();
};
#pragma once

typedef struct tagStudent
{
	char* pName;
	int iKor;
	int iEng;
	int iMath;

	//** �����ʰ� ���ÿ� ȣ�� ��.
	//** ������. ȣ������ �ʾƵ� �˾Ƽ� �����Ǵ� ��
	tagStudent() 
	{	
		iKor	= 0;
		iEng	= 0;
		iMath	= 0;
		printf_s("�����Ǿ����ϴ�.\n");
	};

	//** ���� ������ 
	// ����ڰ� ȣ���� �� ȣ���.
	// �������¸� ���� ������ �� �� ����.
	tagStudent(int _iKor, int _iEng, int _iMath)
	{
		iKor	= _iKor;
		iEng	= _iEng;
		iMath	= _iMath;
		printf_s("������� �Ǿ����ϴ�.\n");
	};


}Student;

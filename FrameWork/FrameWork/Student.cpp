#include "Student.h"


Student::Student()
{

}
Student::~Student()
{
	Releze();
}
void Student::Initalize()
{
	char str[128] = "";
	cout << "�̸� �Է� : ";
	cin >> str;
	
	

	m_tInfo.pName = new char[strlen(str) + 1];
	strcpy(m_tInfo.pName, str);

	cout << "���� ���� �Է� : ";
	cin >> m_tInfo.iKor;

	cout << "���� ���� �Է� : ";
	cin >> m_tInfo.iEng;

	cout << "���� ���� �Է� : ";
	cin >> m_tInfo.iMath;
	

	
}

void Student::Progress()
{
	char str[128] = "";
	cout << "������ �̸� �Է� : ";
	cin >> str;

	m_tInfo.pName = new char[strlen(str) + 1];
	strcpy(m_tInfo.pName, str);

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iKor;

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iEng;

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iMath;

	
}

void Student::Render()
{
	cout << "�л� �̸� : " << m_tInfo.pName << endl;
	cout << "���� ���� : " << m_tInfo.iKor << endl;
	cout << "���� ���� : " << m_tInfo.iEng << endl;
	cout << "���� ���� : " << m_tInfo.iMath << endl;

	
}

void Student::Releze()
{
}


void Student::Average()
{
	iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	iAverage = iTotal / 3;
	cout << "���� ���� : " << iTotal << endl;
	cout << "��� ���� : " << iAverage << endl;

}





#include "Student.h"

Student::Student()
{

}

Student::~Student()
{

}


void Student::Initialize()
{
	char str[128] = "";
	cout << "�̸� �Է� : ";
	cin >> str;

	m_tInfo.szName = new char[strlen(str) + 1];
	strcpy(m_tInfo.szName, str);


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

	m_tInfo.szName = new char[strlen(str) + 1];
	strcpy(m_tInfo.szName, str);

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iKor;

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iEng;

	cout << "������ ���� ���� �Է� : ";
	cin >> m_tInfo.iMath;
}

void Student::Render()
{
	cout << "�л� �̸� : " << m_tInfo.szName << endl;
	cout << "���� ���� : " << m_tInfo.iKor << endl;
	cout << "���� ���� : " << m_tInfo.iEng << endl;
	cout << "���� ���� : " << m_tInfo.iMath << endl;
}

void Student::Release()
{

}

#include "Object.h"

Object::Object()
{}
Object::~Object()
{
	Releze();
}

void Object::Initalize()
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

void Object::Progress()
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

void Object::Render()
{
	cout << "�л� �̸� : " << m_tInfo.pName << endl;
	cout << "���� ���� : " << m_tInfo.iKor << endl;
	cout << "���� ���� : " << m_tInfo.iEng << endl;
	cout << "���� ���� : " << m_tInfo.iMath << endl;
}

void Object::Releze()
{
}

#include"Student.h"


Student::Student()
{

};
Student ::~Student()
{

};

//�Լ� ����
void Student::Initialize()
{
	m_tInfo.iKor;
	m_tInfo.iEng;
	m_tInfo.iMath;
}

void Student::Progress()
{
	cout << "���������Է�:";
	cin >> m_tInfo.iKor;

	cout << "���������Է�:";
	cin >> m_tInfo.iEng;

	cout << "���������Է�:";
	cin >> m_tInfo.iMath;

}
void Student::Render()
{
	cout << "���� ���� : " << m_tInfo.iKor << endl;
	cout << "���� ���� : " << m_tInfo.iEng << endl;
	cout << "���� ���� : " << m_tInfo.iMath << endl;
}
void Student::Release()
{

}

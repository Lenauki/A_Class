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
	cout << "이름 입력 : ";
	cin >> str;

	m_tInfo.szName = new char[strlen(str) + 1];
	strcpy(m_tInfo.szName, str);


	cout << "국어 점수 입력 : ";
	cin >> m_tInfo.iKor;

	cout << "영어 점수 입력 : ";
	cin >> m_tInfo.iEng;

	cout << "수학 점수 입력 : ";
	cin >> m_tInfo.iMath;
}

void Student::Progress()
{
	char str[128] = "";
	cout << "변경할 이름 입력 : ";
	cin >> str;

	m_tInfo.szName = new char[strlen(str) + 1];
	strcpy(m_tInfo.szName, str);

	cout << "변경할 국어 점수 입력 : ";
	cin >> m_tInfo.iKor;

	cout << "변경할 영어 점수 입력 : ";
	cin >> m_tInfo.iEng;

	cout << "변경할 수학 점수 입력 : ";
	cin >> m_tInfo.iMath;
}

void Student::Render()
{
	cout << "학생 이름 : " << m_tInfo.szName << endl;
	cout << "국어 점수 : " << m_tInfo.iKor << endl;
	cout << "영어 점수 : " << m_tInfo.iEng << endl;
	cout << "수학 점수 : " << m_tInfo.iMath << endl;
}

void Student::Release()
{

}

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
	cout << "이름 입력 : ";
	cin >> str;
	
	

	m_tInfo.pName = new char[strlen(str) + 1];
	strcpy(m_tInfo.pName, str);

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

	m_tInfo.pName = new char[strlen(str) + 1];
	strcpy(m_tInfo.pName, str);

	cout << "변경할 국어 점수 입력 : ";
	cin >> m_tInfo.iKor;

	cout << "변경할 영어 점수 입력 : ";
	cin >> m_tInfo.iEng;

	cout << "변경할 수학 점수 입력 : ";
	cin >> m_tInfo.iMath;

	
}

void Student::Render()
{
	cout << "학생 이름 : " << m_tInfo.pName << endl;
	cout << "국어 점수 : " << m_tInfo.iKor << endl;
	cout << "영어 점수 : " << m_tInfo.iEng << endl;
	cout << "수학 점수 : " << m_tInfo.iMath << endl;

	
}

void Student::Releze()
{
}


void Student::Average()
{
	iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	iAverage = iTotal / 3;
	cout << "총합 점수 : " << iTotal << endl;
	cout << "평균 점수 : " << iAverage << endl;

}





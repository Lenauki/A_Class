#include"Student.h"

Student::Student()
{
		
};	
		
Student ::~Student()
{
	
};

//함수 정의
void Student::Initialize()
{
	m_tInfo.iNum = 0;
	m_tInfo.iKor =0;
	m_tInfo.iEng =0;
	m_tInfo.iMath =0;
}

void Student::Progress()
{	
	cout << "학생 번호 입력 :";
	cin >> m_tInfo.iNum;

	char str[128] = "";
	cout << "이름 입력";
	

	cout << "국어점수입력:";
	cin >> m_tInfo.iKor;

	cout << "영어점수입력:";
	cin >> m_tInfo.iEng;

	cout << "수학점수입력:";
	cin >> m_tInfo.iMath;
}
void Student::Render()
{
	if (m_tInfo.iNum > 0)
	{
		cout << "학생 번호 : " << m_tInfo.iNum << endl;
		cout << "국어 점수 : " << m_tInfo.iKor << endl;
		cout << "영어 점수 : " << m_tInfo.iEng << endl;
		cout << "수학 점수 : " << m_tInfo.iMath << endl;
		cout << endl;
	}
}
void Student::Release()
{

}


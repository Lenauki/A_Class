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
	m_tInfo.iKor;
	m_tInfo.iEng;
	m_tInfo.iMath;
}

void Student::Progress()
{
	cout << "국어점수입력:";
	cin >> m_tInfo.iKor;

	cout << "영어점수입력:";
	cin >> m_tInfo.iEng;

	cout << "수학점수입력:";
	cin >> m_tInfo.iMath;

}
void Student::Render()
{
	cout << "국어 점수 : " << m_tInfo.iKor << endl;
	cout << "영어 점수 : " << m_tInfo.iEng << endl;
	cout << "수학 점수 : " << m_tInfo.iMath << endl;
}
void Student::Release()
{

}

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
	m_tInfo.iNum = 0;
	m_tInfo.iKor =0;
	m_tInfo.iEng =0;
	m_tInfo.iMath =0;
}

void Student::Progress()
{	
	cout << "�л� ��ȣ �Է� :";
	cin >> m_tInfo.iNum;

	char str[128] = "";
	cout << "�̸� �Է�";
	

	cout << "���������Է�:";
	cin >> m_tInfo.iKor;

	cout << "���������Է�:";
	cin >> m_tInfo.iEng;

	cout << "���������Է�:";
	cin >> m_tInfo.iMath;
}
void Student::Render()
{
	if (m_tInfo.iNum > 0)
	{
		cout << "�л� ��ȣ : " << m_tInfo.iNum << endl;
		cout << "���� ���� : " << m_tInfo.iKor << endl;
		cout << "���� ���� : " << m_tInfo.iEng << endl;
		cout << "���� ���� : " << m_tInfo.iMath << endl;
		cout << endl;
	}
}
void Student::Release()
{

}


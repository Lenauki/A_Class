#include "MainUpdate.h"
#include "Student.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize()
{
	/*
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		m_ptInfo[i] = new Student;
		m_ptInfo[i]->Initialize();
	}
	*/
	m_iCount = 0;

}

void MainUpdate::Progress()
{
	//** 현 위치에서 각각의 데이터를 추가, 변경, 삭제 가능.
	
	cout << "1. 학생 추가\n";
	cout << "2. 학생 변경\n";
	cout << "3. 학생 삭제\n";
	cout << "4. 선택 출력\n";
	cout << "5. 모두 출력\n";
	cout << "입력 : ";


	int iChoice, i;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		//** 추가
		m_ptInfo[m_iCount] = new Student;
		m_ptInfo[m_iCount]->Initialize();
		m_iCount++;
		break;
	case 2:
		//** 변경
		if (!m_iCount)
			cout << "변경할 대상이 없습니다." << endl;

		while (m_iCount != 0)
		{
			if (m_iCount == 1)
			{
				m_ptInfo[m_iCount - 1]->Progress();
				break;
			}
			else
			{
				cout << "( 1 ~ " << m_iCount << " )\n";
				cout << "변경 대상 선택 : ";
				cin >> i;

				if (i > 0 && i <= m_iCount)
				{
					m_ptInfo[i - 1]->Progress();
					break;
				}
				else
					continue;
			}
		}
		break;
	case 3:
		//** 삭제
		if (!m_iCount)
			cout << "삭제할 대상이 없습니다." << endl;

		while (m_iCount != 0)
		{
			if (m_iCount == 1)
			{
				delete m_ptInfo[m_iCount - 1];
				m_ptInfo[m_iCount - 1] = NULL;
				m_iCount--;
				break;
			}
			else
			{
				cout << "( 1 ~ " << m_iCount << " )\n";
				cout << "삭제 대상 선택 : ";
				cin >> i;

				if (i > 0 && i <= m_iCount)
				{
					delete m_ptInfo[i - 1];
					m_ptInfo[i - 1] = NULL;

					for (int j = i - 1; j < m_iCount - 1; j++)
					{
						Student* pTemp = m_ptInfo[j];
						m_ptInfo[j] = m_ptInfo[j + 1];
						m_ptInfo[j + 1] = pTemp;
					}
					m_iCount--;
					break;
				}
				else
					continue;
			}
		}
		break;
	case 4:
		//** 선택 출력
		if (!m_iCount)
			cout << "출력할 대상이 없습니다." << endl;

		while (m_iCount != 0)
		{
			if (m_iCount == 1)
			{
				m_ptInfo[m_iCount - 1]->Render();
				break;
			}
			else
			{
				cout << "( 1 ~ " << m_iCount << " )\n";
				cout << "출력 대상 선택 : ";
				cin >> i;
				// i = 2;

				if (i > 0 && i <= m_iCount)
				{
					m_ptInfo[i - 1]->Render();
					break;
				}
				else
					continue;
			}
		}
		break;
	case 5:
		//** 모두 출력
		if (!m_iCount)
			cout << "출력할 대상이 1명이라도 있어야 합니다." << endl;
		else
			Render();
		break;
	}
}

void MainUpdate::Render()
{
	//** 현 위치에서 각각의 데이터 출력.
	for (int i = 0; i < m_iCount; i++)
	{
		m_ptInfo[i]->Render();
		cout << endl;
	}
}

void MainUpdate::Release()
{
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		delete m_ptInfo[i];
		m_ptInfo[i] = NULL;
	}
}

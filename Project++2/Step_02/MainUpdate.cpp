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
	//** �� ��ġ���� ������ �����͸� �߰�, ����, ���� ����.
	
	cout << "1. �л� �߰�\n";
	cout << "2. �л� ����\n";
	cout << "3. �л� ����\n";
	cout << "4. ���� ���\n";
	cout << "5. ��� ���\n";
	cout << "�Է� : ";


	int iChoice, i;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		//** �߰�
		m_ptInfo[m_iCount] = new Student;
		m_ptInfo[m_iCount]->Initialize();
		m_iCount++;
		break;
	case 2:
		//** ����
		if (!m_iCount)
			cout << "������ ����� �����ϴ�." << endl;

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
				cout << "���� ��� ���� : ";
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
		//** ����
		if (!m_iCount)
			cout << "������ ����� �����ϴ�." << endl;

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
				cout << "���� ��� ���� : ";
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
		//** ���� ���
		if (!m_iCount)
			cout << "����� ����� �����ϴ�." << endl;

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
				cout << "��� ��� ���� : ";
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
		//** ��� ���
		if (!m_iCount)
			cout << "����� ����� 1���̶� �־�� �մϴ�." << endl;
		else
			Render();
		break;
	}
}

void MainUpdate::Render()
{
	//** �� ��ġ���� ������ ������ ���.
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

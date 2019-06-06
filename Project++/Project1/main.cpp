#include"Headers.h"


//class

//** c		��������
//** c++	��ü����


/***********************************
	** ��ü���� ���(OOP) Ư¡ 5 ����

	1. ��������
	2. ĸ��ȭ
	3. �߻�ȭ
	4. ���
	5. ������

***********************************/


//��ü�� ��� ���� �ǹ�. ���� ��� ��� �繰�� ��ü�̴�. Ű���嵵 ��ü�̰� Ű������ ��ư�� ��ü�̴�.

//��ü���� ��� Ư¡ ���� �˻� �غ���.

/*

typedef struct tagObject
{
	Transform tTransPos;


}Object;
*/

//class�� private ���¸� �⺻������ ������ �ִ�.
//struct�� public ���¸� �⺻������ ������ �ִ�.


class Object
{
	private:
	Transform tTransPos;
	public:
		void Initialize()
		{
			tTransPos.Position = Vector3(0.f, 0.f);
			tTransPos.Scale = Vector3(0.f, 0.f);

		}
		void Render()
		{
			printf_s("X: %f\nY: %f\n",
				tTransPos.Position.x,
				tTransPos.Position.y);
		};
public:
	Object() //** ������ ���� ȣ��
	
	{
		tTransPos.Position.x = 100.f;
		tTransPos.Position.y = 100.f;
		printf_s("������\n");
		

	};

	Object(const Transform _rinfo) : tTransPos(_rinfo)
	
	{};

	~Object() //** �Ҹ�Ǳ� ����
	{	
		printf_s("�Ҹ���\n");
	};
};


int main(void)
{

	//Object* pObj = (Object*)malloc(sizeof(Object)); ������ ����
	Object* pPlayer = new Object;
	Object* pMonster = new Object;

	printf_s("����\n");
	Object b;
	b.Initialize();


	printf_s("�߰�\n");
	Object BB = Object(b);
	BB.Render();
	printf_s("��\n");
	//�����ڸ� �̿�
	
	//pPlayer->Initialize();
	pPlayer->Render();

	//pMonster->Initialize();
	pMonster->Render();
	

	
	//free(pObj);
	
	


	system("pause");

	return 0;
}
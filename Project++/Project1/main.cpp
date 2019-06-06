#include"Headers.h"


//class

//** c		절차지향
//** c++	객체지향


/***********************************
	** 객체지향 언어(OOP) 특징 5 가지

	1. 정보은닉
	2. 캡슐화
	3. 추상화
	4. 상속
	5. 다형성

***********************************/


//객체는 모든 것을 의미. 예를 들면 모든 사물은 객체이다. 키보드도 객체이고 키보드의 버튼도 객체이다.

//객체지향 언어 특징 구글 검색 해보기.

/*

typedef struct tagObject
{
	Transform tTransPos;


}Object;
*/

//class는 private 형태를 기본적으로 가지고 있다.
//struct는 public 형태를 기본적으로 가지고 있다.


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
	Object() //** 생성된 직후 호출
	
	{
		tTransPos.Position.x = 100.f;
		tTransPos.Position.y = 100.f;
		printf_s("생성자\n");
		

	};

	Object(const Transform _rinfo) : tTransPos(_rinfo)
	
	{};

	~Object() //** 소멸되기 직전
	{	
		printf_s("소멸자\n");
	};
};


int main(void)
{

	//Object* pObj = (Object*)malloc(sizeof(Object)); 역참조 형태
	Object* pPlayer = new Object;
	Object* pMonster = new Object;

	printf_s("시작\n");
	Object b;
	b.Initialize();


	printf_s("중간\n");
	Object BB = Object(b);
	BB.Render();
	printf_s("끝\n");
	//생성자를 이용
	
	//pPlayer->Initialize();
	pPlayer->Render();

	//pMonster->Initialize();
	pMonster->Render();
	

	
	//free(pObj);
	
	


	system("pause");

	return 0;
}
#include <iostream>

using namespace std;


class Parent
{
protected:
	int m_iNumber;
public:
	void ParentOutput() { cout << m_iNumber << endl; }
	
	Parent() : m_iNumber(0) {};
	Parent(int _i) : m_iNumber(_i) {};
	~Parent() {};
};

class Child : public Parent
{
	/*
private:
	int m_iNumber;
	*/

public:

	//범위가 작은 함수 여러개를 같은 이름으로 만듦. 오버 로딩 (불러오는 함수)
	void ChildOutput(){cout << m_iNumber << endl;}

	/*
	int Sum(int _i, int _j)
	{
		return _i + _j;
	}
	int Sum(int _i, int _j, int _k)
	{
		return _i + _j+_k;
	}
	int Sum(int _i, int _j, int _k, int _l)
	{
		return _i + _j + _k + _l;
	}

	int Sum(int _i, int _j, int _k, int _l,int _m)
	{
		return _i + _j + _k + _l+_m;
	}

	int Sum(int _i, int _j, int _k, int _l, int _m, int _n)
	{
		return _i + _j +_k + _l + _m + _n;
	}
	*/
	/*	
	void ChildOutput(int _i)
	{
		cout << m_iNumber << endl;
	}
	void ChildOutput(char _c)
	{
		cout << m_iNumber << endl;
	}
	void ChildOutput(int _i, int _j)
	{
		cout << m_iNumber << endl;
	}
	*/



public:
	Child()
	{
		cout << "생성자" << endl;
	};
	Child(int _i) : Parent(_i)
	{
		cout << "복사 생성자" << endl;

	};
	~Child() 
	{
		cout << "소멸자" << endl;
	};
};



int main(void)
{

	/*
	Parent* parent =new Parent;
	Child* child= new Child;

	parent->ParentOutput();
	((Parent*)child)->ParentOutput();
	*/


	/*
	Parent parent;
	Child child;

	parent.ParentOutput();
	child.ChildOutput();
	child.ParentOutput();
	*/

	/*
	Child child;
	int iResult = child.Sum(100, 200, 300, 400, 500, 600);
	cout << iResult << endl;
	*/

	
	Child child = Child(50);
	child.ChildOutput();
	


	system("pause");

	return 0;
}
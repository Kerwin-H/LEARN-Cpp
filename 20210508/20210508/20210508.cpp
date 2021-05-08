#include<iostream>
using namespace std;


class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}

//==========================

class A{};
class B : public A {};
class Person {
public:
	virtual A* f() { return new A; }
};
class Student : public Person {
public:
	virtual B* f() { return new B; }
};


//===========================

class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-����" << endl; }
};


//=====================

class Car{
public:
	virtual void Drive(){}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-����" << endl; }
};


//===============
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-����" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-�ٿ�" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	
		Car* pBMW = new BMW;
	pBMW->Drive();
}
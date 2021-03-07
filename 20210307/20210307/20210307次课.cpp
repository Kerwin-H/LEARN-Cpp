#include<iostream>
#include"Date.h"
using namespace std;


//====1.有元函数
//有元的关系是单向的
class Date{	

	//友元函数的声明
	friend ostream&  operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		
	}

private:
	int _year;
	int _month;
	int _day;
};


//返回值ostream可以支持连续的输出
ostream&  operator<<(ostream& _cout, const Date& d) {

	_cout << d._year << "-" << d._month << "-" << d._day;

	return _cout;
}
istream& operator>>(istream& _cin, Date& d){

	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
//==输出
void test(){
	
	
	Date d(2021, 3, 7);
	//简写形式
	cout << d << endl;
	//完整形式
	//operator<<(cout, d);
	////连续输出
	//cout << d << endl;
	//operator<<(cout, d)<<endl;

	cout << d << d << d << endl;;
}

//==输入
//耦合度大
void test(){

	Date d(2021, 3, 7);
	//输入
	cin >> d >> d >> d;

}


class Time;
class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void Date:: SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t.second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
}

class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成

public:
	Time::Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
	void fun(){
	
	}

private:
	int _hour;
	int _minute;
	int _second;

};

//==友元关系是单向的
//==有元类不能传递

//========内部类
class A{
	
	public:
	//有元类的声明
	friend class C;
	//==内部类
	//作用: 类似于有元类
	//相比于有元类:在内部类直接可以访问外部类static成员
	//因为这里的B类在A类中没有进行public 的操作,所以是一个私有类,无法访问
	//内部类可以通过外部类的访问权限限制内部类的可见范围
	//定义的位置会影响内部类的可见范围
	//==内部类是独立于外部类的,不从属与外部类
	//外部类不是内部类的有元类
	class B{

	public:
		void setA(A& a){
			
			a._a = _b;
		}
	private:
		int _b = 2;
	};


private:
	int _a = 1;
	static int _sa;
};

//有元类
class C{

public:
	void setA(A& a){
	
		a._a = _c;

		a._sa = 20;
		A::_sa = 5;
	}

private:
	int _c = 3;
	
};

int A::_sa = 10;


//void test(){
//	//判断是否从属
//	int a = sizeof(A);
//
//	int b = sizeof(A::B);
//
//	cout << a <<"--"<< b << endl;
//}






int main()
{
	test();
	
	system("pause");
	return 0;
}
#include<iostream>

using namespace std;

//========1.再谈构造函数
class Date{
public:

	Date(int year, int month, int day)
		//====初始化列表: 真正初始化的位置
		//在构造列表写完的时候初始化已经完成了
		
		:_year(year)
		, _month(month)
		, _day(day)
		//没有写这个初始化列表的时候就是一个随机值
	{
		//不是初始化
		//赋值的地方
		/*_year = year;
		_month = month;
		_day = day;*/
	}

private:
	int _year;
	int _month;
	int _day;
};
//============================
class Time{
public:
	/*Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}*/
	//全缺省默认构造
	Time(int hour=1, int minute=5, int second=30)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
		
	{
		//内部不是初始化,只是对随机值的一个赋值
		cout << "Time()" << endl;
	}

	Time& operator=(const Time& t){
		
		cout << "operator()" << endl;
		return *this;
	}
private:
	int  _hour;
	int  _minute;
	int  _second;
	
};
//=======================
class Date{
public:

	Date(int year, int month, int day)
		//1.const,引用成员必须要在初始化列表中进行初始化
		//2.const,必须在定义的时候进行初始化
		//const,定义的地方为初始化列表
		//3.如果自定义函数中没有默认构造,自定义会在初始化列表中显式初始化
		:_year(year)
		, _month(month)
		, _day(day)
		, _hour(12)
		, _time(9,50,59)
	{
		
	}

private:
	int& _year;
	int& _month;
	int& _day;
	const int _hour;
	Time _time;
};

void test(){

	Time t;
	/*Date d(2021, 03, 03);*/
}

//=========================
class A {
public:

	//A(int a)
	//	:_a1(_a2)		//这样写刚好将值进行链式的赋予,都为1
	//	, _a2(a)

	A(int a)
		:_a1(a)
		, _a2(_a1)	//逆序,进行初始化,从下往上
					//在未进行赋值的时候,所有的都是随机值
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
void test4() {
	A aa(1);
	aa.Print();
}

//=======================
class A{

public:
	explicit A(int a);	//====加入explicit可以禁止 单参构造隐式类型转换

	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

private:
	int _a;
};

void test(){
	
	A aobj(10);		//简单构造
	A aobj2 = aobj;	//拷贝构造

	A aobj3 = A(20);	
	//A aobj4 = 40;		//先创建匿名对象,然后调用赋值运算符,将匿名
					//对象的内容赋予aobj3
					//单参构造隐式类型转换
}

//========2.static成员

class A{
public:
	A(){
		
		++_count;
	}
	A(const A& a){
		
		++_count;
	}

	//this指针:指向当前调用此函数的对象
	//====static成员函数不包含this指针
	//因为static函数可以通过类名访问,没有对象,this没有指向
	static int getCount(){
		
		//缺少this指针,不能调用非static成员函数
		//fun();
		return _count;
	}
	//普通的成员函数包含this 指针
	void fun(){
		
		//可以调用static成员函数
		this->getCount();
		cout << "fun()" << endl;
	}

//private:
	//static成员属于所有对象
	//static成员变量: 必须在类外进行初始化
	static int _count;
};

int A::_count = 0;		//不属于任何一个对象

A funA(A a){
	
	return a;
}

void test3(){
	
	cout << A::_count << endl;
	A a1;
	A a2;
	A a3 = funA(a1);
	cout << a1.getCount() << endl;
	cout << a2.getCount() << endl;
	cout << a3.getCount() << endl;
	cout << A::getCount() << endl;
	//static成员访问的形式
	//1.对象 .static成员
	cout << a1._count << endl;
	//2.类型+ :: +static成员
	cout << A::_count << endl;

}

//========3.C++11 的成员初始化新玩法
class A{

public:

	A(int a=1)
		:_a(a)
	{}
private:

	//C++11新的初始化方式,在成员变量生命的时候,给一个缺省值
	//此处声明的缺省值,在没有其他值可选的时候,才会用
	//仅限于非static成员
	int _a=0;
	//int _a;		//随机值

	//static int _b = 10;		报错,静态的必须在类外进行初始化
};

void test2(){
	
	A a(10);
	A a2;

	
}

//4.========有元
//相当于定义的这个函数相当于Linux的root用户一样,权利比较大
class Date{

public:
	//有元函数的声明:此函数可以访问当前类的私有成员
	//不属于类的成员
	//可以放在类的任何地方,不影响使用
	friend void operator<<(ostream& _cout, const Date& d);

	Date(int y = 1, int m = 2, int d = 3)
		:_y(y)
		, _m(m)
		, _d(d)
	{}

	//可访问私有成员
	void operator<<(ostream& _cout,const Date& d){
		
		_cout << d._y << "-" << d._m << "-" << d._d << endl;
	}

private:
	int _y;
	int _m;
	int _d;
};

void test(){


	Date d(2021, 03, 03);

	//怎样支持连续的输出?
	cout << d << endl;
	//两种表达方式
	/*d.operator<<(cout);
	d << cout;*/
	cout << d;

}








int main(){
	
	test();

	system("pause");
	return 0;
}
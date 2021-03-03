#include<iostream>

using namespace std;

//========1.��̸���캯��
class Date{
public:

	Date(int year, int month, int day)
		//====��ʼ���б�: ������ʼ����λ��
		//�ڹ����б�д���ʱ���ʼ���Ѿ������
		
		:_year(year)
		, _month(month)
		, _day(day)
		//û��д�����ʼ���б��ʱ�����һ�����ֵ
	{
		//���ǳ�ʼ��
		//��ֵ�ĵط�
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
	//ȫȱʡĬ�Ϲ���
	Time(int hour=1, int minute=5, int second=30)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
		
	{
		//�ڲ����ǳ�ʼ��,ֻ�Ƕ����ֵ��һ����ֵ
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
		//1.const,���ó�Ա����Ҫ�ڳ�ʼ���б��н��г�ʼ��
		//2.const,�����ڶ����ʱ����г�ʼ��
		//const,����ĵط�Ϊ��ʼ���б�
		//3.����Զ��庯����û��Ĭ�Ϲ���,�Զ�����ڳ�ʼ���б�����ʽ��ʼ��
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
	//	:_a1(_a2)		//����д�պý�ֵ������ʽ�ĸ���,��Ϊ1
	//	, _a2(a)

	A(int a)
		:_a1(a)
		, _a2(_a1)	//����,���г�ʼ��,��������
					//��δ���и�ֵ��ʱ��,���еĶ������ֵ
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
	explicit A(int a);	//====����explicit���Խ�ֹ ���ι�����ʽ����ת��

	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

private:
	int _a;
};

void test(){
	
	A aobj(10);		//�򵥹���
	A aobj2 = aobj;	//��������

	A aobj3 = A(20);	
	//A aobj4 = 40;		//�ȴ�����������,Ȼ����ø�ֵ�����,������
					//��������ݸ���aobj3
					//���ι�����ʽ����ת��
}

//========2.static��Ա

class A{
public:
	A(){
		
		++_count;
	}
	A(const A& a){
		
		++_count;
	}

	//thisָ��:ָ��ǰ���ô˺����Ķ���
	//====static��Ա����������thisָ��
	//��Ϊstatic��������ͨ����������,û�ж���,thisû��ָ��
	static int getCount(){
		
		//ȱ��thisָ��,���ܵ��÷�static��Ա����
		//fun();
		return _count;
	}
	//��ͨ�ĳ�Ա��������this ָ��
	void fun(){
		
		//���Ե���static��Ա����
		this->getCount();
		cout << "fun()" << endl;
	}

//private:
	//static��Ա�������ж���
	//static��Ա����: ������������г�ʼ��
	static int _count;
};

int A::_count = 0;		//�������κ�һ������

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
	//static��Ա���ʵ���ʽ
	//1.���� .static��Ա
	cout << a1._count << endl;
	//2.����+ :: +static��Ա
	cout << A::_count << endl;

}

//========3.C++11 �ĳ�Ա��ʼ�����淨
class A{

public:

	A(int a=1)
		:_a(a)
	{}
private:

	//C++11�µĳ�ʼ����ʽ,�ڳ�Ա����������ʱ��,��һ��ȱʡֵ
	//�˴�������ȱʡֵ,��û������ֵ��ѡ��ʱ��,�Ż���
	//�����ڷ�static��Ա
	int _a=0;
	//int _a;		//���ֵ

	//static int _b = 10;		����,��̬�ı�����������г�ʼ��
};

void test2(){
	
	A a(10);
	A a2;

	
}

//4.========��Ԫ
//�൱�ڶ������������൱��Linux��root�û�һ��,Ȩ���Ƚϴ�
class Date{

public:
	//��Ԫ����������:�˺������Է��ʵ�ǰ���˽�г�Ա
	//��������ĳ�Ա
	//���Է�������κεط�,��Ӱ��ʹ��
	friend void operator<<(ostream& _cout, const Date& d);

	Date(int y = 1, int m = 2, int d = 3)
		:_y(y)
		, _m(m)
		, _d(d)
	{}

	//�ɷ���˽�г�Ա
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

	//����֧�����������?
	cout << d << endl;
	//���ֱ�﷽ʽ
	/*d.operator<<(cout);
	d << cout;*/
	cout << d;

}








int main(){
	
	test();

	system("pause");
	return 0;
}
#include<iostream>
#include"Date.h"
using namespace std;


//====1.��Ԫ����
//��Ԫ�Ĺ�ϵ�ǵ����
class Date{	

	//��Ԫ����������
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


//����ֵostream����֧�����������
ostream&  operator<<(ostream& _cout, const Date& d) {

	_cout << d._year << "-" << d._month << "-" << d._day;

	return _cout;
}
istream& operator>>(istream& _cin, Date& d){

	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
//==���
void test(){
	
	
	Date d(2021, 3, 7);
	//��д��ʽ
	cout << d << endl;
	//������ʽ
	//operator<<(cout, d);
	////�������
	//cout << d << endl;
	//operator<<(cout, d)<<endl;

	cout << d << d << d << endl;;
}

//==����
//��϶ȴ�
void test(){

	Date d(2021, 3, 7);
	//����
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
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�

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

//==��Ԫ��ϵ�ǵ����
//==��Ԫ�಻�ܴ���

//========�ڲ���
class A{
	
	public:
	//��Ԫ�������
	friend class C;
	//==�ڲ���
	//����: ��������Ԫ��
	//�������Ԫ��:���ڲ���ֱ�ӿ��Է����ⲿ��static��Ա
	//��Ϊ�����B����A����û�н���public �Ĳ���,������һ��˽����,�޷�����
	//�ڲ������ͨ���ⲿ��ķ���Ȩ�������ڲ���Ŀɼ���Χ
	//�����λ�û�Ӱ���ڲ���Ŀɼ���Χ
	//==�ڲ����Ƕ������ⲿ���,���������ⲿ��
	//�ⲿ�಻���ڲ������Ԫ��
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

//��Ԫ��
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
//	//�ж��Ƿ����
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
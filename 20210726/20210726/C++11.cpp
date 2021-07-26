#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
#include<stdlib.h>
#include <algorithm>
#include <functional>
//#include<map>
//#include <typeinfo>
//#include<set>
using namespace std;
//
//
//struct A{
//
//public:
//
//	A(int a = 10)
//		:_a(a)
//	{}
//
//	A(int a, int b, int c)
//		:_a(a)
//	{}
//
//
//
//	int _a;
//};
//
//template<class T>
//class Vector{
//
//public:
//	Vector(size_t n)
//		:_arr(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//
//	//��ʼ���б��ʼ,���ٶ�Ӧ�Ŀռ�
//	Vector(const initializer_list<T>& lst)
//		:_arr(new T(lst.size()))
//		, _size(lst.size()
//		, _capacity(_size)
//	{
//			int idx = 0;
//			for (const auto& e : lst){
//				
//				_arr[idx++] = e;
//			}
//
//	}
//
//private:
//	T* _arr;
//	size_t _size;
//	size_t _capacity;
//};
//
//
//
//void test1(){
//
//	//��Ӧ�ļ�ֵ�Խ��г�ʼ��
//	vector<int> v = { 1, 2, 3, 4 };
//	map<int, int> m = { { 1, 1 }, { 2, 3 } };
//	set<int> s = { 1, 2, 3, 4, 4, 4, 4, 6 };
//	pair<int, int> p = { 1, 3 };
//	//��Ҫ�Զ���
//	Vector<int> v2 = { 1, 2, 3 };
//}
//
//
//void test(){
//	
//	int a = 10;
//	int b = 20;
//
//	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	
//}
//
//
//
//int Add(int a, int b) {
//	return a + b;
//}
//int main()
//{
//	const int&& ra = 10;
//
//	// ���ú�������ֵ������ֵ��һ����ʱ������Ϊ��ֵ
//	int&& rRet = Add(10, 20);
//	return 0;
//}

//
////��Ҫ������ͨ���ú�const����
//int main()
//{
//	// ��ͨ��������ֻ��������ֵ������������ֵ
//	int a = 10;
//	int& ra1 = a; // raΪa�ı���
//	//int& ra2 = 10; // ����ʧ�ܣ���Ϊ10����ֵ
//
//	const int& ra3 = 10;
//	const int& ra4 = a;
//
//	int && ra = 10;	//��C++11�п��Խ�����ֵ����,���ǲ�����������ֵ
//	//int && re = a;
//	cout << ra << endl;
//
//	system("pause");
//	return 0;
//}

class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);				//��������ö�Ӧ�ĸ�ֵ��������ص�ʱ��,���Ҫ������+�Ĳ���
											//��Ӧ�ľͻῪ�ٳ��µ���ʱ�ռ�,��������ַ���,��ԭ���ľͻᱻ
											//����,ֱ��ƴ�ճ��µ���ʱ�Ŀռ�,��ȥ�������,�������������������ٵ������Ŀռ�
											//��������������Դ�������ʹ���,��Ҫ���м�

											//���ǿ���ʹ��C++11�е���ֵ�������������Ľ��,������ֵ���ú�,���ǾͻὫԭ��Ҫƴ�յ�
											//�ַ�����Ӧ��nameֱ���ÿ�,���´�����������������ʹ��,����Ҫ�����µĿռ�,�����ϻ�����
											//��ԭ���Ŀռ��С�����в���,ֻ�����ǻ���һ������,��������Ҫ�����µĿռ�,Ч�ʾʹ�����
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
		
	}
private:
	char* _str;
};
//
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	String s3(s1 + s2);
//	system("pause");
//	return 0;
//}

//��C++11�д���move����,�����Ͼ���ʵ����ֵ����������ֵ,��������ǿ��ת���ķ�ʽ��ʵ�ֵ�,�Ӷ��ƶ���Ӧ�����

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}

	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}

#if 0

	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}

#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}

#endif

private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}
//
//int main()
//{
//	Person p(GetTempPerson());
//	return 0;
//}

struct Goods{
	string _name;
	double _price;
};

//====c98��﷽ʽ
struct Compare{		//�����Զ���Ԫ�صĴ�С�Ƚ�������Ҫ�Զ������еıȽϺ���   lambda���ʽ
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main(){
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	return 0;
}

int main()
{
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		//!!!!!=========================================
		[](const Goods& l, const Goods& r)
		->bool						//��C++11�����ȶ���������ֵ��������,�Ӷ�ʵ���Զ���Ƚϴ�С
	{
		return l._price < r._price;
	});
	//===============================
	return 0;
}
//[]()->{};		//lambadb���ʽ		ʹ�õ�ʱ����Ҫauto��ֵ������һ������

//lambda���ʽҲ���Ժͺ�������ֱ�ӷ�������,ֱ�Ӳ��񵽶�Ӧ�ı���


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
//	//初始化列表初始,开辟对应的空间
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
//	//对应的键值对进行初始化
//	vector<int> v = { 1, 2, 3, 4 };
//	map<int, int> m = { { 1, 1 }, { 2, 3 } };
//	set<int> s = { 1, 2, 3, 4, 4, 4, 4, 6 };
//	pair<int, int> p = { 1, 3 };
//	//需要自定义
//	Vector<int> v2 = { 1, 2, 3 };
//}
//
//
//void test(){
//	
//	int a = 10;
//	int b = 20;
//
//	// 用decltype推演a+b的实际类型，作为定义c的类型
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
//	// 引用函数返回值，返回值是一个临时变量，为右值
//	int&& rRet = Add(10, 20);
//	return 0;
//}

//
////主要区分普通引用和const引用
//int main()
//{
//	// 普通类型引用只能引用左值，不能引用右值
//	int a = 10;
//	int& ra1 = a; // ra为a的别名
//	//int& ra2 = 10; // 编译失败，因为10是右值
//
//	const int& ra3 = 10;
//	const int& ra4 = a;
//
//	int && ra = 10;	//在C++11中可以进行右值引用,但是不可以引用左值
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
		strcpy(pTemp, _str);				//在这里调用对应的赋值运算符重载的时候,如果要将进行+的操作
											//对应的就会开辟出新的临时空间,用来存放字符串,而原来的就会被
											//销毁,直到拼凑成新的临时的空间,再去将它输出,并且利用析构函数销毁掉其他的空间
											//但是这样对于资源的利用率过大,需要进行简化

											//我们可以使用C++11中的右值引用来化简具体的结果,引用右值引用后,我们就会将原来要拼凑的
											//字符串对应的name直接置空,让新创建出的引用来代替使用,不需要开辟新的空间,本质上还是利
											//用原来的空间大小来进行操作,只不过是换了一个名字,这样不需要申请新的空间,效率就大大提高
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

//在C++11中存在move函数,本质上就是实现右值引用引用左值,是类似于强制转换的方式来实现的,从而移动对应的语句

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

//====c98表达方式
struct Compare{		//对于自定义元素的大小比较我们需要自定义其中的比较函数   lambda表达式
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main(){
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	return 0;
}

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		//!!!!!=========================================
		[](const Goods& l, const Goods& r)
		->bool						//在C++11中首先对于这两个值进行引用,从而实现自定义比较大小
	{
		return l._price < r._price;
	});
	//===============================
	return 0;
}
//[]()->{};		//lambadb表达式		使用得时候需要auto赋值给其中一个变量

//lambda表达式也可以和函数对象直接发生交互,直接捕获到对应的变量


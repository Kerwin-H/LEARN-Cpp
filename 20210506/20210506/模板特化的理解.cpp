#include<iostream>
#include<array>
using namespace std;


//====1.模板的特化
template <class T>
bool isEqual(T a, T b){

	return a == b;
}

template <>
bool isEqual<char*>(char* a, char* b){

	return strcmp(a, b) == 0;
}

//
//
//void test(){
//	
//	bool ret = isEqual(1, 2);
//	ret = isEqual(2.3, 2.3);
//	ret = isEqual("123", "123");
//
//	char* ptr = "123";
//	char ptr2[] = "123";
//	ret = isEqual(ptr, ptr2);
//
//}


//void test1(){
//	
//	//array<T,size_t>: size_t --->非类型模板参数
//	//只能是整数类型,不能给浮点数或者自定义类型的数据
//	array<int, 10> arr;
//
//}


//=====2.类模板的特化  应用场景: 类型萃取
//先初始化一个简单的模板
template<class T1, class T2>
struct D{

public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1,T2)" << endl;
	}

	T1 _d1;
	T2 _d2;
};
//特化: 全特化: 所有的类型都是具体类型
template <>
struct D<char, double>{

	D(const char& d1, const double& d2)
	:_d1(d1)
	, _d2(d2)
	{
		cout << "D(char,double)" << endl;
	}

	char _d1;
	double _d2;
};


//====3.偏特化
//1.只特化部分的类型
template <class T1>
struct D<T1, char>{

	D(const T1& d1, const double& d2)
	:_d1(d1)
	, _d2(d2)
	{
		cout << "D(T1,char)" << endl;
	}

	T1 _d1;
	double _d2;
};
//2.给模板参数做进一步的限制
template <class T1, class T2>
struct D<T1*, T2*>{

public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1*,T2*)" << endl;
	}

	T1 _d1;
	T2 _d2;
};


void test(){

	D<int, int> d(1, 1);		//对于通用模板的实例化

	D<char, double> d2('a', 1.1);		//全特化模板的实例化

	D<int, char> d3(1, 'a');	//偏特化的模板实例化

	D<int*, int* > d4(1, 2);	//偏特化的模板实例化
}


int main(){

	test();

	system("pause");
	return 0;
}

//模板的作用:
//1.必须包含于同一个文件中
//2.可以防止程序员在编程的时候重复的操作,提高效率
//3.节省资源,更快的迭代开发
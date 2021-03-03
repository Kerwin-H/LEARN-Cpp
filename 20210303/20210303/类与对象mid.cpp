//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//
//class A{
//
//public:
//	int _a; 
//	A(int a = 10){
//		_a = a;
//		cout << "A()" << endl;
//	}
//};
//
////=========类的6种默认的成员函数
//
////=========1.构造函数
////对已经创建的函数进行初始化
//class Date{
//
//public:
//	//构造函数可以重载
//	//无参:默认构造
//	//编译器自动生成的也是默认构造
//
//	//Date(){
//	//	
//	//	cout << "Date()" << endl;
//	//}
//
//	//====!!!上面和下面这两中默认构造只能存在一种,不能多次出现
//	//====无参构造或者全缺省构造
//
//	//全缺省	也是一种默认的构造
//	Date(int year=1, int month=1, int day=1){
//		
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//
//	Date(int  year, int month, int day, int num){
//		
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int,int)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//自定义类型成员
//	A _a;
//};
//
//void test3(){
//	//编译器在创建对象时,自动调用构造函数
//	//完成对象内容的初始化,并不是创建对象
//	//调用无参的构造
//
//
//	Date d;		//因为在上面这个类的里面插入了A的类,所以
//				//我们会优先访问到A所对应的类,然后再访问到Date对应的默认类
//				//如果自定义的类没有对应的默认构造,系统就会报错!
//
//	//调用带参数的构造(自动调用)
//	Date d1(1998, 12, 25);
//	Date d2(1999, 06, 28);		//参数列表中对应的个数和类型要一致,不然就会报错找不到
//
//	//Date d3(2019, 20, 25, 35);//编译器会自动对你定义的函数类型和
//							 // 变量的数目自动定义你要调用的函数
//	//不能显示调用函数
//	//d.Date(2020, 2, 2);		//报错
//
//	//不是调用无参的构造,而是声明一个函数
//	//函数名:d4
//	//参数列表: 空
//	//返回值:Date
//	Date d4();		//对于无参数的直接是 Date d4;即可
//
//	
//}
//
////=========2.析构函数
////不是用来销毁对象,而是用来对于资源的清理
//class Date{
//
//public:
//
//	Date(int year = 1, int month = 1, int day = 1){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//	void Display()	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//不显示定义的析构,编译器会自动生成默认的析构函数
//	//编译器自动会调用自定义成员的析构函数,完成自定义成员的清理
//	~Date(){}
//private:
//	int _year;
//	int _month;
//	int _day;
//	
//};
//
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//
//		_size = 0;
//		_capacity = capacity;
//	}
//	//对象销毁的时候,编译器自动调用析构,完成资源的清理
//	~SeqList()
//	{
//		if (_pData) 
//		{
//			free(_pData); // 释放堆上的空间
//			_pData = NULL; // 将指针置为空
//			_capacity = 0;
//			_size = 0;
//			cout << "~SeqList" << endl;
//		}
//	}
//
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//int* p = nullptr;
//void test5(){
//	//Date d(2020, 2, 3);
//
//	//动态开辟一个对应的空间,可以存放10个元素
//	//将对应的首地址保存在_pData中
//	SeqList sq(10);		//这里匹配的空间没有保存在顺序表中,是将空间开辟在堆上,然后用指针进行调用
//
//	cout << sizeof(sq) << endl;
//	
//}
//
//void test6(){
//	
//	Date d(2021, 20, 5);
//}
//
////========3.拷贝构造函数
//class Date{
//
//public:
//	
//	Date(int year = 1, int month = 1, int day = 1){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//	//如果不显示定义拷贝构造,编译器会自动生成拷贝构造
//	Date(const Date& d){		//如果这里没有加取地址的符号的时候, 它只会
//								//无限的进行拷贝调用下去,而一致无法对其中的值进行拷贝
//		
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		cout << "参数的拷贝" << endl;		//在这里添加一个检验,看是否会直接调用拷贝的这个函数
//	}
//
//	Date(int  year, int month, int day, int num){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int,int)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void test(){
//	
//	Date date(2020, 02, 20);
//	//创建拷贝构造,创建copy对象,内容和date完全一致
//	Date copy(date);
//}
////====这种利用编译器进行自动拷贝的形式叫做  !浅拷贝!
////它只能应用于一些简单的拷贝方式上,不会拷贝对象的资源!
////对于一些有资源的类,必须进行显示定义,比如如果其中一个个含有free的操作符,而拷贝的
////地址又是指向同一个区域的,这样的话free操作就会执行两次,造成代码错误,
////所以对于这种有资源的,我们就要单独拎出来进行操作
//
//
//int main(){
//	
//	test();
//
//	system("pause");
//	return 0;
//}

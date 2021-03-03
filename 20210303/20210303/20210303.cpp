//#pragma pack(1)		//默认对齐改成1byte
//
//#include<iostream>
//
//using namespace std;
//
//
////========结构体内存对齐规则
//struct A{
//	int a;
//	int b;
//	double d;
//	int e;
//
//};
//
//void test1(){
//	
//	cout << sizeof(A) << endl;
//
//	A oa;
//	cout << (char*)&oa.d - (char*)&oa << endl;		//求出某个成员相对于结构体起始位置的偏移量
//}
//
////========大端小端字节序
//void test2(){
//
//	int a = 1;
//	char* pa = (char*)&a;
//
//	if (*pa)
//		cout << "small"<< endl;
//	else
//		cout << "big" << endl;
//}
////========this 指针
//
//class D{
//
//	int a;
//};
//class Date
//{
//public:
//	//每一个非静态成员函数中,都含有一个this 指针
//	//作为函数的第一个形参
//	//this 指针指向调用此函数的对象
//	//this 类型: 类类型*  const this
//	//只存在于成员函数中,在外面无法进行访问
//	//一般存放于寄存器
//	void Display()	//void Display (this)		这里的this 指针在成员函数中是一个形参,使用之后会进行销毁
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		
//		D d;
//		//this = &d;	//因为这里的this指针是一个const 类型的数据,他所指的数据是无法改变的
//	}
//
//	void SetDate(int year, int month, int day)  //void SetDate( this ,int year, int month, int day)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//
//void test()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display();
//	d2.Display();
//
//	//外面无法进行访问
//	//cout << this << endl;
//}
////====空指针无法进行解引用的操作
////====this指针在没有进行解引用的条件下可以进行解引用
//
//
//int main(){
//
//	test1();
//
//	system("pause");
//	return 0;
//}
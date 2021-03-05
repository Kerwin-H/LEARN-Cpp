#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


//========5.赋值运算符重载
//====(1)运算符重载
class Date{

public:
	Date(int y = 1, int m = 1, int d = 1){
		
		_y = y;
		_m = m;
		_d = d;
	}
	
	bool isEqual(const Date& d){
		
		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}

	Date(const Date& d){
		
		_y == d._y;
		_m == d._m;
		_d == d._d;
		cout << "Date(const Date&)" << endl;
	}

	//成员函数都有隐藏的this指针
	//作为成员函数,必须比实际的少一个

	//这里出现的this 指针时钟指向从左往右的的第一个指针
	bool operator==(const Date& d){
		
		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}


	//如果需要进行连续赋值,则返回值类型不能为空
	//返回值类型为当前类型 
	Date& operator=(const Date& d){
		
		//优化,判断对象是否是同一个对象: 通过指针进行判断
		if (this != &d){

			_y == d._y;
			_m == d._m;
			_d == d._d;
			cout << "operator=" << endl;
		}
		return *this;	//返回当前被处理好的对象的对应指针,再处理下一位变量
		//return d;
	}

	~Date(){
		cout << "~Date()" << endl;
	}

private:
	int _y;
	int _m;
	int _d;
};

//==运算符重载
//函数名: operator==
//1.只能重载已经存在的运算符,像@这样的符号就不行
//5.  * :: sizeof ?: . 都不能重载,经常在笔试题中出现

bool operator==(const Date& d1, const Date& d2){}

//==2.3.内置类型的不能进行修改--->运算符的所有参数都为内置类型
//int operator+(int a, int b){	//对于一些内部的最基本的元素不能进行重载
//	return a*b;					//就像+-*/这种的
//}

void test1(){

	Date d1(2021,12,25);
	Date d2(2021,12,25);
	//判断日期是否相等
	if (d1 == d2){	//当你在这里进行了运算符重载的时候这里就不报错了

					//因为这里的==运算符判断不清楚内部的是年还是月还是日的
					//判断,所以我们要将这个==运算符进行重载,对其内部进行重
					//新定义,让==符合日期进行比较的方式,才能进行日期的比较! 
	}
	//====调用运算符重载的完整形式
	//if (d1.operator==(d2))
		//如果运算符重载函数不是成员内部的函数
		//if (operator==(d1,d2))

	//一般用这里的简写形式,比较方便,看起来简洁明了
		if(d1==d2)
	{
		cout << "==" << endl;
	}
	else{
		cout << "!=" << endl;
	}
	
	//if (d1.isEqual(d2)){	//直接在类的内部定义一个成员函数,直接是进行日期类代码的比较	
	//}
}

//====(2)赋值运算符重载
void test(){
	
	Date d1(2021, 12, 25);
	Date d2(2091, 12, 25);
	Date d3(2031, 12, 25);


	//赋值操作
	////简写
	//d1 = d2;
	////全写
	//d2.operator=(d3);		//如果没有显示定义,编译器会自动修改生成

	//d2 = d2;	//如果是自己对自己进行定义,我们可以通过函数成员的优化来规避这一种情况


	int a, b, c;
	//连续赋值:从右向左
	a = b = c = 100;

	//完整形式
	d1.operator=(d2.operator=(d3));
	//简写形式
	d1 = d2 = d3;		//====这里接收到的参数类型不同

	//不是赋值,为拷贝构造
	Date d4 = d1;	//用已经存在的变量对新的变量进行初始化,完成拷贝构造
}


class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
void test()
{
	String s1("hello");		//当类中有资源的时候,需要显示定义赋值,显示定义拷贝构造
	String s2("world");		//防止其中的空间无法进行释放,造成巨大的损失

	s1 = s2;
}


int main(){
	
	test();

	system("pause");
	return 0;
}






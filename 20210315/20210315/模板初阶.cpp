#include<iostream>

using namespace std;

//========1.泛型编程(模板编程)
//大大的提高了效率

//$====1.函数模板
//首先定义出函数的模板,实际在执行的时候内部会进行推演,形成需要的函数
//这里的T就是一个模板参数
template<typename T>

void Swap(T& a, T& b){
	
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>	//!!在这里不可以用struct 
T add(T a, T b){
	
	return a + b;
}

template<class T1,class T2,class T3>
void print(const T1& a, const T2& b, const T3&c){
	
	cout << a <<"-"<< b <<"-"<< c << endl;
}
//为进行模板实例化的普通函数
void print(const int& a, const int& b, const double& c){

	cout << a << "-" << b << "-" << c << endl;
}

void test(){
	
	int a = 1, b = 2;
	char d = 'm', e = 'n';
	double f = 1.3;
	double g = 5.94;
	
	//这里的执行的不是调用的同一个函数,它的template内部会自动生成新的程序来进行调用
	//类型推演:
	//隐式实例化(一般)
	Swap(a, b);
	Swap(d, e);
	Swap(f, g);

	//显式实例化
	add(a, b);

	add<int>(a, e);	//在执行ae的时候,由于存在两个不同的参数类型,我们就要对于其中的类型进行声明,才能实现
					//这种进行声明的过程就叫做显示实例化

	//强制类型
	add(a, (int)e);

	print(a, b, d);
	print(b, f, a);

	//匹配规则:
	//1.优先匹配普通函数
	//2.如果函数模板可以实例化一个更加匹配的函数,走实例化
	//3.如果指明需要进行实例化,则直接实例化
	print(a, b, f);

	print<int,int,double>(a, b, f);
}

//$====2.类模板
template <class T>
class seqList{
public:
	seqList(int n)
		:_data(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	T seqListAt(size_t pos);

private:
	//int* _data;
	T* _data;
	size_t _size;
	size_t _capacity;
};
//==在类的外面进行函数的定义,也要加泛型的声明
template <class T>
T seqList::seqListAt(size_t pos){
	
	return _data[pos];
}


void test(){

	//错误写法,不能进行实例化
	//seqList sq;
	//类模板实例化之后,真正的类型-->类名<模板参数类型>
	//只能走显式实例化
	seqList<int>sq(10);

	seqList<double>sq2(10);
}

int main(){
	
	//test();

	system("pause");
	return 0;
}
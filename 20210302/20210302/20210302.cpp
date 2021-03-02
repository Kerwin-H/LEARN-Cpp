#include<iostream>

using namespace std;

//========内联函数(类似于宏)
//inline + 函数
//对于比较简单的函数,会直接进行展开,不会进行函数的调用
//但是对于相对于来说比较复杂的函数,就不一定会有作用的
inline int add(int a, int b){
	return a + b;
}

inline int fun1(int n){
	
	for (int i = 1; i < n; ++i)
		n += i*n / (i + 1)*n;
	return n;
}

void test2(){
	
	int a = add(10, 20);	//实际编译时: int a=10+20
	
	int n = 10000;
	n = fun1(n);

}

//========auto关键字
void test1(){
	
	//auto: 自动类型推导(自动识别你输入数据的类型)
	//相当于一个类型的调用符
	auto a = 10;
	auto b = 2.0;
	auto c = 'a';
	auto d = 'a' + b;
	//定义指针:都可以,因为你可以从右边的&符号看出来
	auto pa = &a;		//指针
	auto* pb = &a;

	//定义引用:必须加&
	auto& rc = b;
	auto f = b;


	int j, k, l;
	//auto a = 10, b = 60, c = 'a';	//报错,同一行必须是同一个类型


	cout << typeid(a).name() << endl;		//显示出类型
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;


	cout << typeid(pa).name() << endl;
	cout << typeid(rc).name() << endl;
	cout << typeid(f).name() << endl;

}

//========基于范围的for循环
//范围for
void test3(){
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		
		cout << arr[i] << " ";
	}
	cout << endl;


	//范围for:   当前的数据 : 循环的范围
	//只是循环的条件发生了变化,其他的都是一样的
	for (const int& e : arr){		//如果在这里加了const 则值不会被修改,后面的赋值也没有办法
		cout << e << " ";
		//e = 10;
	}
	cout << endl;

	for (int e : arr){
		cout << e << " ";
	}
	cout << endl;


	for (const auto& e : arr){
		cout << e << " ";
	}
}

//在数组作为参数的时候,数组名会退化成指针,范围无法确定,故---不能使用范围for
//void fun(int arr[], int n){
//	
//	for (const auto& e : arr){
//		cout << e << " ";
//	}
//	cout << endl;
//}

//========指针空值
void fun(int a){
	cout << "fun(int)" << endl;
}
void fun(int* a){
	cout << "fun(int*)" << endl;
}

void test(){

	int* p = NULL;	//在预处理的时候,宏替换: int* p=0;
	int* p2 = 0;

	fun(NULL);		//在为空的时候,编译器会有限将NULL转换成整型,而不是指针类型
	

	fun((int*)NULL);//==
	fun(nullptr);	//建议使用下面的这个方式
	
	cout << typeid(nullptr).name() << endl;
}

int main(){

	test();

	system("pause");
	return 0;
}
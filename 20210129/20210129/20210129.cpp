#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<iostream>

using namespace std;

//函数重载:
//当参数名相同,函数内部的类型不同的时候
//
//extern "C" int add(int a,int b);  //在C++中将代码按照C的方式进行编译
//
//extern "C" char add(char a, char b);
//
//int main(){
//
//	int a = add(10, 20);
//	char b = add('a','b');
//	return 0;
//}

//不构成函数重载(不符合函数的语法)
void TestFunc1(int a = 10) {
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a) {
	cout << "void TestFunc(int)" << endl;
}



//================6.引用
//1.必须进行初始化


struct A{
	int a;
	int b;
	int c;
	int d;
};


//void test(){
//
//	int a = 10;
//
//	//ra是一个引用,称为a的别名,它和a指向相同的一个实体
//	int& ra = a;
//
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//
//	//引用:不分配新的空间
//	A& rsa = sa;  //相当于别名
//	//拷贝:分配新的空间
//	A copy = sa;
//	copy.a = 100;
//	rsa.a = 5;
//	 
//}

//===========
//常引用:引用指向实体不能修改
//const 类型&
//void test(){
//
//	const int a = 10;
//	const int& ra = a;
//
//	const int& ra2 = 100;
//
//	double d = 2.5;
//	int c = 10;
//	 
//	c = d;
//
//	//!!!
//	const int& ra3 = d;
//}

//void Swap(int* a, int* b){
//	int tmp = a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Swap(int& a, int b){
//	int tmp = a;
//	a = b;
//	b = a;
//}
//================
//int& add(int& a, int&b){
//	return a += b;  
//}
//void test(){
//	int a = 10;
//	int b = 20;
//	int& ra = add(a, b);
//	add(a, b);
//	cout << a <<" "<< b << endl;
//	cout << ra << endl;
//
//}

struct A{

	int a[10000];
};

A globalA;

void fun1(A a){}

void fun2(A& ra){}

void test(){
	int n;
	cout << "循环次数:" << endl;
	cin >> n;

	size_t begin = clock();
	for (int i = 0; i < n; ++i)
		fun1(globalA);
	size_t end = clock();
	cout << "time:" << end - begin << endl;

	 begin = clock();
	for (int i = 0; i < n; ++i)
		fun2(globalA);
	 end = clock();
	cout << "time:" << end - begin << endl;

}



int main(){
	test();


	system("pause");
	return 0;
}





















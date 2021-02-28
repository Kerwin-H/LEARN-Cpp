#include<time.h>
#include<iostream>
using namespace std;

//========按照C语言的规则来进行编译
//extern "C" int add(int a, int b);
//
//extern "C"{}		//括号内部都可以按照C编译
//
//char add(char a, char b);
//
//int main(){
//	
//	int a = add(10, 20);
//	char b = add('a', 'b');
//	return 0;
//}

//========引用
//1.必须进行初始化
//2.一对一
//3.变量有多个引用

//struct A{
//
//	int a;
//	int b;
//	int c;
//	int d;
//	int e;
//};
//
//void test1(){
//	
//	int a = 10;
//	//ra是一个引用,a的别名,指向和a相同的实体
//	int& ra = a;
//
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//	sa.e = 1;
//	//引用:不分配新的空间,相当于多了一个指针的意思
//	A& rsa = sa; 
//	//拷贝: 需要分配空间
//	A copy = sa;
//
//	copy.a = 100;
//	rsa.a = 5;
//}
//
//void test2(){
//
//	//常引用:引用指向的实体不能修改
//	//const 类型&
//
//	const int a = 10;
//	//int& ra = a;
//	const int& ra = a;
//
//	//int& ra2 = 100;
//	const int& ra2 = 100;
//
//	double d = 2.5;
//	int c = 10;
//
//	c = d;		//转换后这里是一个临时变量,不能直接强制转化
//
//	//int& ra3 = d;
//	const int& ra3 = d;
//	//临时变量具有常性,需要有const 对其进行转换
//
//
//
//}

//=====================
//void Swap(int* a, int* b){
//	
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Swap(int&a, int&b){
//
//	int tmp = a;
//	a = b;
//	b = a;
//}
//
//void test(){
//	
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);		//操作简单,方便利用
//	Swap(a, b);
//}


//引用作为返回值的时候,返回值的生命周期要大于函数的,不然会越界
//int& add(int& a, int& b){
//	return a += b;
//}
//void test(){
//	
//	int a = 10;
//	int b = 20;
//	int& ra = add(a, b);
//	
//	add(a, b);
//
//	cout << a << b << endl;
//	cout << ra << endl;
//
//}
//
//


//struct A{
//
//	int a[10000];
//};
//
//A globalA;
//
//void fun1(A a){}
//
//void fun2(A& a){}
//
//void test(){
//	
//	int n;
//	cout << "循环次数" << endl;
//	cin >> n;
//
//	size_t begin = clock();
//	for (int i = 0; i < n; ++i)
//		fun1(globalA);
//	size_t end = clock();
//	cout << end - begin << endl;
//}

void test(){

	int a = 10;
	int&ra = a;
	ra = 100;

	int al = 10;
	int*ral = &al;
	*ral = 100;


	int* c;
	//const指针在定义的时候必须进行初始化
	int* const c2 = &al;

	//引用++,实体内容的++
	++ra;
	//指针++,地址的偏移
	++ral;
}


int main(){

	test();
	system("pause");
	return 0;
}
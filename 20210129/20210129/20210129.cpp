#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<iostream>

using namespace std;

//��������:
//����������ͬ,�����ڲ������Ͳ�ͬ��ʱ��
//
//extern "C" int add(int a,int b);  //��C++�н����밴��C�ķ�ʽ���б���
//
//extern "C" char add(char a, char b);
//
//int main(){
//
//	int a = add(10, 20);
//	char b = add('a','b');
//	return 0;
//}

//�����ɺ�������(�����Ϻ������﷨)
void TestFunc1(int a = 10) {
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a) {
	cout << "void TestFunc(int)" << endl;
}



//================6.����
//1.������г�ʼ��


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
//	//ra��һ������,��Ϊa�ı���,����aָ����ͬ��һ��ʵ��
//	int& ra = a;
//
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//
//	//����:�������µĿռ�
//	A& rsa = sa;  //�൱�ڱ���
//	//����:�����µĿռ�
//	A copy = sa;
//	copy.a = 100;
//	rsa.a = 5;
//	 
//}

//===========
//������:����ָ��ʵ�岻���޸�
//const ����&
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
	cout << "ѭ������:" << endl;
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





















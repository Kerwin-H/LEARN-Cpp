#include<time.h>
#include<iostream>
using namespace std;

//========����C���ԵĹ��������б���
//extern "C" int add(int a, int b);
//
//extern "C"{}		//�����ڲ������԰���C����
//
//char add(char a, char b);
//
//int main(){
//	
//	int a = add(10, 20);
//	char b = add('a', 'b');
//	return 0;
//}

//========����
//1.������г�ʼ��
//2.һ��һ
//3.�����ж������

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
//	//ra��һ������,a�ı���,ָ���a��ͬ��ʵ��
//	int& ra = a;
//
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//	sa.e = 1;
//	//����:�������µĿռ�,�൱�ڶ���һ��ָ�����˼
//	A& rsa = sa; 
//	//����: ��Ҫ����ռ�
//	A copy = sa;
//
//	copy.a = 100;
//	rsa.a = 5;
//}
//
//void test2(){
//
//	//������:����ָ���ʵ�岻���޸�
//	//const ����&
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
//	c = d;		//ת����������һ����ʱ����,����ֱ��ǿ��ת��
//
//	//int& ra3 = d;
//	const int& ra3 = d;
//	//��ʱ�������г���,��Ҫ��const �������ת��
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
//	Swap(&a, &b);		//������,��������
//	Swap(a, b);
//}


//������Ϊ����ֵ��ʱ��,����ֵ����������Ҫ���ں�����,��Ȼ��Խ��
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
//	cout << "ѭ������" << endl;
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
	//constָ���ڶ����ʱ�������г�ʼ��
	int* const c2 = &al;

	//����++,ʵ�����ݵ�++
	++ra;
	//ָ��++,��ַ��ƫ��
	++ral;
}


int main(){

	test();
	system("pause");
	return 0;
}
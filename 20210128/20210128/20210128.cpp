#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>  //C++��û��.h

//====1
//====2
//namespace + �����ռ�����{����,����}
namespace N1{
	
	int a=5;
	void fun1(){
	
		printf("fun1()\n");
	}

	//����Ƕ��
	namespace N2{
		int a=3;
		void fun1(){
			printf("N1:N2:fun1()\n");
		}
	
	}
}


//�ֶζ���,������N1�Ŀռ�
namespace N1{
	
	//int a;	//�ֲ��������,���ǲ��ܶ�����ͬ�ı���

	int b=55;
	void fun2(){
		printf("N1:fun2()\n");
	}
}



int a = 10;  //ȫ��
void fun1(){

	printf("fun1()\n");
}



using namespace std;

void fun2(int a){

	cout << a << endl;

}

void fun3(int a=10){  //����һ��Ĭ��ֵ,��δ���д���,ʹ��Ĭ��ֵ

	cout << a << endl;

}

//ȫȱʡ(��������)
void fun4(int a = 1, int b = 2,int c=3,int d=4){
	cout << a <<" "<< b <<" "<< c <<" "<< d << endl;

}

//ȫȱʡ:���еĲ�������Ĭ��ֵ
//��ȱʡ:���ֲ�����Ĭ��ֵ(����������ֵ!!!!!!!!!!!!!!!!)



//�ض���Ĭ�ϲ���
//void fun6(int a = 10);
//
//void fun6(int a = 5){}


//====��������
//����ĺ���������˼����cpp�п��Դ���ͬ���ĺ���,���Ǻ���������Ҫ����һ���Ĳ���


int  add(int x, int y){ return x + y; }
//int  add(int x, int y){}
char  add(char x, char y){ return x + y; }
double add(double x, double y){ return x + y; }






void test(){

	//fun2(100);
	//fun3();   //������һ��Ĭ��ֵ(��̥)
	//fun3(50);

	/*fun4();
	fun4(55);
	fun4(4, 6);*/

	double a = 1;
	double b = 849.4894;
	cout<<add(a,b)<<endl;


}

//void test(){

	//====3

	//printf("%d\n",98);
	//printf("%c\n",99);

	//int a=10;
	//scanf("%d",&a);
	////scanf("%c",a);   //���û�м�ȡ��ַ,�������ʱ����ж�

	////C++ͷ�ļ���������г�Ա������std�����ռ�
	//std::cin >> a;  //����
	
	//std::cout << a;	//���
	//cin >> a;
	//cout << a;

	//cin֧����������,������
	//cout֧����������,������
	//int b, c, d, e;
	//cin >> a >> b >> c >> d >> e;
	//cout << a << b << c << d << e <<"\n";
	//
	//cout << endl;  //����
	


//}









//void test(){//��û�н���usingʱ,����Ҫ������������������ܽ��з���
//
//	//ȫ��:a
//	printf("a=%d\n",a);
//	//�����ռ�ķ�����ʽ
//	
//	//1.�����ռ�  ::  ��Ա(ֻ���ڶ��ź���ʹ��)
//	printf("N1::a %d\n",N1::a);
//	
//
//
//	//2.using �����ռ�  ::  ��Ա
//	N1::fun2;  //ֱ������
//	using N1::b;
//	printf("b::%d\n",b);
//	
//	//3.չ�������ռ�: using  namespace�����ռ�
//	//ע��,����������������ռ�չ��,��ô�ͻ�����еı������ȫ�ֱ���,�Ӷ��޷���ȷa���׶�Ӧ����һ��ֵ
//	using namespace N1;
//	//printf("%d\n",a);  //����
//	fun2();
//
//}



int main(){
	test();


	system("pause");
	return 0;
}

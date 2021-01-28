#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>  //C++都没有.h

//====1
//====2
//namespace + 命名空间名称{变量,函数}
namespace N1{
	
	int a=5;
	void fun1(){
	
		printf("fun1()\n");
	}

	//可以嵌套
	namespace N2{
		int a=3;
		void fun1(){
			printf("N1:N2:fun1()\n");
		}
	
	}
}


//分段定义,都属于N1的空间
namespace N1{
	
	//int a;	//分部定义可以,但是不能定义相同的变量

	int b=55;
	void fun2(){
		printf("N1:fun2()\n");
	}
}



int a = 10;  //全局
void fun1(){

	printf("fun1()\n");
}



using namespace std;

void fun2(int a){

	cout << a << endl;

}

void fun3(int a=10){  //给定一个默认值,在未进行传参,使用默认值

	cout << a << endl;

}

//全缺省(从左往右)
void fun4(int a = 1, int b = 2,int c=3,int d=4){
	cout << a <<" "<< b <<" "<< c <<" "<< d << endl;

}

//全缺省:所有的参数都有默认值
//半缺省:部分参数有默认值(必须连续赋值!!!!!!!!!!!!!!!!)



//重定义默认参数
//void fun6(int a = 10);
//
//void fun6(int a = 5){}


//====函数重载
//这里的函数重载意思是在cpp中可以存在同名的函数,但是函数的类型要存在一定的差议


int  add(int x, int y){ return x + y; }
//int  add(int x, int y){}
char  add(char x, char y){ return x + y; }
double add(double x, double y){ return x + y; }






void test(){

	//fun2(100);
	//fun3();   //这里是一个默认值(备胎)
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
	////scanf("%c",a);   //如果没有加取地址,在输入的时候会中断

	////C++头文件定义的所有成员都属于std命名空间
	//std::cin >> a;  //输入
	
	//std::cout << a;	//输出
	//cin >> a;
	//cout << a;

	//cin支持连续输入,从左到右
	//cout支持连续输入,从左到右
	//int b, c, d, e;
	//cin >> a >> b >> c >> d >> e;
	//cout << a << b << c << d << e <<"\n";
	//
	//cout << endl;  //换行
	


//}









//void test(){//在没有进行using时,你需要加上完整的作用域才能进行访问
//
//	//全局:a
//	printf("a=%d\n",a);
//	//命名空间的访问形式
//	
//	//1.命名空间  ::  成员(只用在逗号后面使用)
//	printf("N1::a %d\n",N1::a);
//	
//
//
//	//2.using 命名空间  ::  成员
//	N1::fun2;  //直接引用
//	using N1::b;
//	printf("b::%d\n",b);
//	
//	//3.展开命名空间: using  namespace命名空间
//	//注意,在这里如果将命名空间展开,那么就会把其中的变量变成全局变量,从而无法明确a到底对应的那一个值
//	using namespace N1;
//	//printf("%d\n",a);  //报错
//	fun2();
//
//}



int main(){
	test();


	system("pause");
	return 0;
}

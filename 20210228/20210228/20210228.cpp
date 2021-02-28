#include<stdio.h>
//c++无 .h
#include<iostream>


//========I.命名空间的定义
//========(1)普通定义

//namespace + 命名空间名称 (变量,函数)
namespace N1{		
	
	int a=0;
	void fun1(){
		printf("N1:fun1()\n");
	}

//========(2)嵌套定义
	//可嵌套
	namespace N2{
		
		int a=1;
		void fun1(){
			
			printf("N1:N2:fun1()\n");
		}
	}
}
//========(3)分段定义

//分段定义,可将N1定义两次,只不过内部的数据是连接的
//不会因为分开定义就各是各的
namespace N1{
	
	//int a;	//重定义
	int b=66;
	void fun2(){
		
		printf("N1:fun2()\n");
	}
}

//虽然名字相同,但是作用域不同,故可以共存
int a = 10;

void fun1(){
	
	printf("fun1()\n");
}

void test1(){
	//全局:a
	printf("a:  %d\n",a);
	//命名空间中成员的访问形式:
	//1.命名空间+ :: +成员
	printf("N1::a:  %d\n",N1::a);
	//2.using 命名空间::成员

	using N1::b;		//需要在输出之前,不然还是要加全部的
	
	printf("N1::b: %d\n",b);
	//3.展开成员空间:  using namespace  命名空间
	//如果全局中有重名,则会发生混淆
	using namespace N1;
	//printf("n1::a:  %d\n",a);		//不确定,存在多个
	fun2();

	//========推荐1 2
}
//========II.输入输出
//========cpp中的输入输出更为简洁
using namespace std;
void test2(){
	
	//C++中的头文件定义的所有成员都属于std命名空间
	
	//std::cin >> a;		//输入
	//std::cout << a;		//输出
	//========如果不想加std的这个前面的格式,我们就需要将std的命名空间进行展开
	//在代码之前  using namespace std;

	//========支持连续的输入输出,也不用表示其明确的类型
	//输出顺序: 从左往右
	//输入顺序: 从左往右

	//cin >> a>>a>>a;
	//cout << a<<"123"<<"\n";
	
	int b, c, d, e;
	cin >> a >> b >> c >> d>>e;
	cout << a << b << c << d << e << "\n";

	cout << endl;	//表示换行

}
//========III.缺省参数
void fun3(int a){
	cout << a << endl;
}

//全缺省: 所有的参数都存在默认值
//半缺省: 部分存在默认值==========(必须从右往左依次,必须连续)

void fun4(int a = 10){		//====在定义函数的时候,传一个备用值,如果没有传值,则使用备用值,不会报错
	cout << a << endl;		//如果传值则不用备用值
}

void fun5(int a = 10, int b = 20, int c = 30, int d = 40){
	cout << a << b << c << d << endl;
}
void test3(){
	
	//fun3(1);
	fun3(100);
	fun4();
	fun4(50);

	fun5(3,6,9);
}

//函数声明
void fun7(int a = 10);
//函数定义
void fun7(int a){
	cout << a << endl;
}

//========IIII.函数重载
//允许重名函数存在,但是需要存在一定的差异
//C 会报错重定义
char add(char a, char b){
	return a + b;
}
int add(int a, int b){
	return a + b;
}
double add(double a, double b){
	return a + b;
}

void fun8(char a, int b){
	cout << "fun7(char,int)" << endl;
}
//参数顺序不同
void fun8(int b, char a){
	cout << "fun7(int,char)" << endl;
}
//参数个数不同
void fun8(char a,int b,char c){
	cout << "fun7(char,int,char)" << endl;
}
//不能通过返回值类型的不同来区分函数重载


int main(){
	
	//test1();
	//test2();
	test3();
	fun7();
	int a = 1;
	char b = 'a';

	fun8(a,b);
	fun8(b,a);
	fun8(b,a,b);




	system("pause");
	return 0;
}
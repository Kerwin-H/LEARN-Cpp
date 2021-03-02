#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//在C++中,结构体不光可以定义出变量,还可以定义出函数
//所以这里的结构体就不仅仅是一个结构体,它是一个"类"
//因为它其中包含了结构体的定义,和结构体相关的函数
//========类的引入+定义

//class Student{};//常用//这两种定义方式是一样的,除了最前面的单词不一样
//C++中常用的定义方式:    class + 类名 + {所有的成员};
struct Student{

public:		//========访问权限
	//作用域: 从修饰符开始到下一个修饰符遇到时结束

	//成员函数
	void SetStudentInfo(const char* name, const char* gender, int age){
		
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo(){
		cout << _name << " " << _gender << " " << _age << endl;
	}

	//成员变量
	char _name[20];
	char _gender[3];
	int _age;
};

void test1(){
	
	Student stu;	
	//类成员的使用,不需要通过作用域限定符的方式使用
	//通过"."的方式,如果是指针,通过"->"的形式

	stu.SetStudentInfo("hu", "男", 20);
	stu.PrintStudentInfo();
	cout << stu._gender << endl;
}

//========struct class区别
//struct 定义的类  ,默认访问权限为public
class A{
public:
	int _a;
};
//class 默认访问权限为private
class B{
public:
	int fun1(int a, int b){
		return a + b;
	}
public:
	int _b;
};

class C{
public:
	int fun2(int a, int b){
		
		return a + b;
	}

};

class D{};
void test(){
	
	//定义一个类类型的变量:称为类的实例化
	//实例化的变量称为类的对象
	A oa;	//oa是类A实例化的一个对象
	oa._a = 10;

	B ob;
	//ob._b = 5;


	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

}


int main(){
	
	test();

	system("pause");
	return 0;
}

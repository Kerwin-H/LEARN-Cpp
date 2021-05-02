#include<iostream>
using namespace std;
//多态的条件
//0.前提: 继承
//1.有虚函数
//2.子类重写父类的虚函数
//3.调用此函数的类型是基类的指针,引用

//
//class Person{
//
//public:
//	//虚函数: vritual +正常的函数定义
//	virtual void BuyTicket(){ cout << "买票-全价" << endl; }
//};
//
//class Student:public Person{
//
//	//虚函数的重写: 子类定义了一个和父类接口完全相同的函数
//	//重写的虚函数函数名,参数列表,返回值和父类对应的函数完全一致
//public:
//	//虚函数: vritual +正常的函数定义
//	virtual void BuyTicket(){ cout << "买票-半价" << endl; }
//};
//
////多态看对象
//void fun(Person& p){
//	
//	p.BuyTicket();
//}
////看参数的类型来判断是否是多态
//void fun2(Person p){
//	p.BuyTicket();
//}
//
//void test(){
//
//	Person p;
//	Student s;
//
//	fun(p);
//	fun(s);
//
//	fun2(p);
//	fun2(s);
//}
////协变:返回值类型可以不同,但是必须是有继承关系的指针/引用
//
////析构函数的理解
//
///*class A final{};
//
//class B :public A{};*/	//报错,加了final类似于最终的子类,无法再进行扩展
//
//
//class A{
//
//public:
//	virtual void fun() final{
//		
//		cout << "A::fun() final" << endl;	//还是无法被继承
//	}
//};

//强制重写
//override //检查在子类中有没有重写对应的虚函数,如果没有重写则会报错


//纯虚函数: 函数=0
//抽象类不能发生实例化
//抽象类: 类中定义了纯虚函数

//=====接口的实现

//class A{
//
//public:
//	virtual void fun(){
//		
//		cout << "A::fun()" << endl;
//	}
//
//private:
//	int _a = 1;
//};
//void test(){
//
//	cout << sizeof(A) << endl;
//} 

//继承关系的虚函数表

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//void test(){
//	
//	Base b;
//	Derive d;
//}

//多继承

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
//一个子类继承了两个基类

typedef void(*vfptr)();
void printVTable(vfptr vfTable[]){

	cout << "虚表地址:" << vfTable << endl;
	vfptr* fptr = vfTable;
	while (*fptr != nullptr){

		(*fptr)();
		++fptr;
	}
}


void test(){

	Base1 b;
	Base2 b2;
	Derive d;

	cout << "Base1 vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&b);
	printVTable(vftable);

	cout << "Base2 vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&b2);
	printVTable(vftable);

	cout << "Derive vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&d + sizeof(Base1));
	printVTable(vftable);

	cout << "Derive vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&d + sizeof(Base1));
	printVTable(vftable);
}



int main(){

	test();

	system("pause");
	return 0;
}
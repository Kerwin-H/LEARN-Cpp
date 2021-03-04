#include<iostream>
using namespace std;


//========7.const 成员


//class A{
//
//public:
//	int setI(int i){
//		
//		_i = i;
//		//==非const成员函数中,可以调用const成员函数
//		getI();		//可以实现  const *=*
//	}
//	//==const修饰this指针:this指针指向的对象内容不能变
//	int getI()const{		//const this :const A* const
//		
//		//_i = 100;
//		//this->_i = 100;
//		//setI(10);		类型不匹配
//		return _i;
//	}
//
//private:
//	int _i;
//};
//
////==这里是非成员函数,不允许加const 类型的函数
//void fun(int a)//const
//{
//
//	a = 100;
//}
//void test1(){
//
//	A a;
//	//原则:权限够不够(读写)--->权限不能放大,但是可以缩小
//	//非const对象可以调用const成员函数:可以
//	a.setI(10);
//	a.getI();
//
//	const A b; 
//	
//	//const对象可以调用非const成员函数:不能
//	
//	//b.setI(10); 
//	b.getI();
//
//}

//========8.取地址及const取地址操作符重载
class A{

public:
	int setI(int i){

		_i = i;
	}
	int getI()const{		

		return _i;
	}
	//==this: A* const
	A* operator&(){
		
		return this;
	}
	//==this: const A* const
	A* operator&()const{	//表示内部的指针是一个const指针
		
		//return this;	报错
	}

private:
	int _i;
};


void test(){

	A obja;
	A* pa = &obja;
	pa->setI(10);

	const A objb;
	const A* pb = &objb;
}



int main(){

	test();

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

//==========1.C++ 继承方式


//class Person{
//
//public:
//	void Print(){
//		
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "peter";
//	int _age = 18;
//};


//继承==派生类: 继承方式  继承类(如果不写继承方式,则会直接默认私有的继承方式)
//这里的public就是支持继承类内部的成员的访问

//class Student :protected Person  保护类继承
//class Student :private Person	   私有类继承
//class Student :public Person
//{};
//
//class Empty{};

//
//void test(){
//
//
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Person s;
//
//	s._age = 5;
//	s.Print();		//如果不public则会报错
//}
//!!!主要就是根据访问方式的不同,将对应的公有类进行改变


//2.==========基类和派生类的赋值转换

//void test(){
//	
//	Person p;
//	Student stu;
//
//	//切片:子类对象,指针,引用赋值给父类的对象,指针,引用
//	p = stu;
//	Person& rs = stu;
//	Student& rs2 = stu;
//	Person& rs3 = rs2;
//	Person* ps = &stu; 
//	Student* ps2 = &stu;
//
//	//不能父类对象赋值给子类对象
//	//stu=(Student)p;
//	//父类指针,引用不能直接赋值给子类指针,需要进行引用
//	//但是可以进行强制类型转换来进行赋值
//
//	rs.Print();
//
//
//	int a = 10;
//	float b = 1.1;
//	a = b;	//隐式类型转换
//	Student stu;
//	stu.Person::Print();
//
//}


//==========对应的四种函数
//class A{
//
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& a)
//		:_a(a._a)
//	{	
//		cout << "A(const A&)" << endl;
//	}
//
//	A& operator=(const A& a){
//		
//		if (this != &a){
//			
//			_a = a._a;
//		}
//		cout << "A& operator=" << endl;
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//protected:
//	int _a;
//};
//
//class B:public A{
//
//public:
//	B(int a, int b)
//		:A(a)		//将A写在初始化列表
//		, _b(b)
//	{
//		cout << "B(int,int) " << endl;
//	}
//
//	//显示定义的拷贝构造,默认调用A的默认构造
//	B(const B& b)
//		:_b(b._b)
//	{
//		cout << " B(const B&)" << endl;
//	}
//
//	//显示定义的赋值运算符,不会调用父类的赋值运算符
//	B& operator=(const B& b){
//		
//		if (this != &b){
//			
//
//			//A::operator=(b);	//调用父类的赋值运算符
//
//			_a = b._a;
//			_b = b._b;
//		}
//		cout << "B& operator=" << endl;
//		return *this;
//	}
//
//	//显示定义的析构函数,在函数体执行完的视乎,会自动调用父类的析构 
//
//	//析构函数的名称: destructor
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//
//protected:
//	int _b;
//};

//void test(){
//	
//	//子类默认的构造函数,自动调用父类构造函数
//	//完成父类成员的初始化,如果子类没有对新的成员进行构造,就会产生随机值
//	B b(10,100);
//	
//	//B copy(b);	//子类也会默认调用父类的拷贝构造完成拷贝
//
//	
//
//	//B copy(b);
//	//子类默认的赋值运算符,自动调用父类的赋值运算符
//	//b = copy;
//	 
//}

//有元
//基类的静态成员,在整个继承体系中是共享的
struct A{

	static int _i;
};

int A::_i = 0;

struct B :public A
{};

void test(){

	A a;
	B b;
	a._i = 1;
	b._i = 2;
	A::_i = 3;
	B::_i = 4;

}

//class A:public B,public C,.......//多继承的方式

//菱形继承: 数据冗余,二义性
//virtual :改变底层的数据_name 只有一份








int main(){

	test();

	system("pause");
	return 0;
}
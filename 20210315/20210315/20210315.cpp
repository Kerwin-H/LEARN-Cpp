#include<iostream>

using namespace std;

//========3.C++ 内存管理方式
//====3.1 new/delete操作内置类型
//void test(){
//	//对于使用new申请的空间,直接用delete进行释放
//	//对于malloc申请的空间直接使用free
//	//对应释放,一致
//
//	int* mptr = (int*)malloc(sizeof(int));
//	
//	free(mptr);
//
//	int* ptr = new int;//直接申请
//	delete ptr;
//	int* ptr2 = new int(10); //申请+初始化
//	delete ptr2;
//	//连续
//	int* arr = new int[10];//申请连续的空间
//	 
//	delete[] arr;//对于使用delete进行连续的空间释放,直接如左边
//
//}
//====3.2自定义类型 
//class A{
//public:
//
//	A(){
//		cout << "A()" << endl;
//	}
//	~A(){
//		
//		cout << "~A()" << endl;
//	}
//private:
//
//	int _a = 10;
//};
//
//void test(){
//
//	A* mpa = (A*)malloc(sizeof(A));	//1.只进行申请空间
//
//	free(mpa);
//	cout << "------------" << endl;
//
//
//	//自定义类型: new: 申请空间+调用构造函数进行空间内容的初始化
//	//需要存在默认构造,(无参)
//	A* pal = new A;	//1.先申请空间=2.调用构造函数进行初始化
//
//
//	A* pal2 = new A;
//	//首先调用析构函数完成资源的清理,+再进行空间的释放
//	//1.先对于顺序表中所指的资源进行释放
//	//2.再对于顺序表本身进行释放
//	delete pal;	
//	delete pal2;
//
//	//不能使用带参构造对多个对象进行空间申请和初始化
//	//不存在默认构造
//	A* arrA = new A[6];
//	delete[] arrA;		//这里的调用函数是根据数组的大小进行调用构造函数
//}

//=====4.operator new/operator delete函数
//C++中的全局函数

//void test(){
//	
//	//operator new 不是new的运算符重载函数
//	//void* operator new(size_t n);
//	//全写
//	//void* ptr = operator new(sizeof(int));
//	////简写
//	//void* ptr2 = new sizeof(int);
//
//	//operator delete不是delete的运算符重载函数
//	//void operator delete(void* ptr); 
//	/*void* ptr = nullptr;
//	operator delete(ptr);
//	delete ptr;*/
//
//	//==========================
//	//使用方法:类似于malloc 和free
//	//operator new: malloc +异常
//
//	//int* ptr = (int*)operator new (0x7fffffffffff);//申请空间失败,抛出异常返回空值
//
//	int* ptr2 = (int*)malloc(0x7fffffff);//如果是malloc则会返回指针空值,不会抛出异常
//
//	//封装的free,对应operator new的执行
//	//operator delete(ptr);
//	free(ptr2);
//}
//=========================
//class A{
//
//public:
//	A(int a = 10)
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//void test(){
//
//	//相当于一个类的封装,将malloc和free中的内容封装到了这个地方进行使用
//
//	//new: operator new-->malloc
//	int* ptr = new int;
//	//delete: operator delete-->free +抛出异常
//	delete ptr;
//	//new[]: operator new[]-->operator-->malloc
//	int* ptr2 = new int[];
//	//delete[]: operator delete[]-->operator delete-->free
//	delete []ptr2;
//
//
//	//自定义类型
//	//new: operator new-->malloc-->构造
//	A* pa = new A;
//	//delete: 析构 -->operator delete-->free
//	delete pa;
//
//	//连续--在空间申请好的时候,直接执行N次构造
//	A* pa2 = new A[10];
//	//delete []: 会执行一个N次的析构
//	delete[]pa2;
//
//
//}


//====内存池!!!
//struct ListNode{
//public:
//
//	//在类的内部进行定义的时候,如果加了对应的返回值,则可以确定为外部函数
//	void* operator new(size_t n){
//		
//		cout << "operator new" << endl;
//		//采用内存池的方式
//		cout << "memory poll" << endl;
//		allocator<ListNode>alloc;
//		return alloc.allocate(1);		//一个元素的大小
//	
//	}
//
//	void operator delete(void* ptr){
//		
//		cout << "operator delete" << endl;
//		allocator<ListNode>alloc;
//		alloc.deallocate((ListNode*)ptr, 1);
//		cout << "memory pool deallocate" << endl;
//
//	}
//
//	ListNode(int data = 1)	//空间的初始化
//		:_data(data)
//	{
//		
//		cout << "ListNode(int)" << endl;
//	}
//
//	~ListNode(){
//		
//		cout << "~ListNode()" << endl;
//	}
//private:
//	int _data=0;
//	ListNode* _next = nullptr;
//	
//};
//
//class A{
//
//
//};
//void test(){
//
//	//1.首先调用析构函数对内部的资源进行一个清理
//	//2.在调用初始化
//	ListNode* node = new ListNode;
//
//	delete node;
//
//	A* pa = new A;
//	delete pa;
//
//}

//========6.3 new 定义表达式
//对已分配的原始内存空间进行一个初始化,一半搭配内存池进行使用
//class A{
//
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//	~A(){
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void test(){
//
//	A* pa = (A*)malloc(sizeof(A));
//	//初始化已有的空间
//	
//	//new定位表达式: new(指针)类型(参数列表)
//	new (pa)A(10);
//	pa->~A();	//在释放前将内部的资源全部清理掉,然后再进行空间的释放,不然容易会资源泄露
//	
//	free(pa);
//
//}


//====
void test(){

	
	//char* p = new char[0xffffff];

	//char* p = (char*)malloc(0xffffffff);

}


int main(){
	
	test();

	system("pause");
	return 0;
}
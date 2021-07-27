#include<iostream>
#include<string>
#include<vector>
using namespace std;


//内存泄漏



//堆内存
//配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉

//系统资源
//比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费

//!!!最好前期能使用智能指针来进行内存管理,不会造成内存的泄漏

//========使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:

	SmartPtr(T* ptr = nullptr)	//创建智能指针
		: _ptr(ptr)
	{}

	~SmartPtr(){

		if (_ptr)		//进行析构
			delete _ptr;
	}

private:
	T* _ptr;
};

void MergeSort(int* a, int n) {

	int* tmp = (int*)malloc(sizeof(int)*n);
	
	SmartPtr<int> sp(tmp);
	// _MergeSort(a, 0, n - 1, tmp);

	vector<int> v(1000000000, 10);
}
//int main(){
//
//	try {
//		int a[5] = { 4, 5, 2, 3, 1 };
//		MergeSort(a, 5);
//		cout << "test" << endl;
//	}
//	catch (const exception& e){
//
//		cout << e.what() << endl;
//	}
//	system("pause");
//	return 0;
//}
//=================================智能指针就是要满足 RAII 和满足重载 * -> 这两个运算符,具有像指针一样的行为
#include<memory>


//===============auto_ptr============在发生对象拷贝的时候,前面的对象会被悬空,nullptr

class Date{

public:

	Date(){ cout << "Date()" << endl; }

	~Date(){ cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

//int main1(){
//	
//	auto_ptr<Date> ap(new Date);
//	ap->_year = 2018;
//
//	auto_ptr<Date> copy(ap);	//重点!!!当对象发生拷贝或者是复制后,前面的对象就会被悬空!!!!
//
//	system("pause");
//	return 0;
//}


template<class T>
class autoPtr{

public:
	
	autoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	~autoPtr(){
		
		if (_ptr){
			
			delete _ptr;
		}
	}

	T& operator*(){ return *_ptr; }
	T& operator->(){ return _ptr; }
private:
	T* _ptr;
};

//int main2(){
//	
//	autoPtr<Date> ap(new Date);
//
//	autoPtr<Date> copy(ap);
//
//	ap->_year = 2018;	//我们发现在这里ap指针已经不能用了,实际上就是对原来的ap进行拷贝以后已经被赋空
//						//这里的时候ap所在的指针已经不能使用了,在访问对应的资源的时候就会出错.
//
//	return 0;
//}

//===============unique_ptr============粗暴的方式进行防止拷贝

//int main3(){
//	
//	unique_ptr<Date> ap(new Date);
//
//	//unique_ptr<Date> copy(ap);	//这里的时候不能发生拷贝
//								// unique_ptr的设计思路非常的粗暴-防拷贝，也就是不让拷贝和赋值。
//}

//template<class T>
//class uniquePtr{
//
//public:
//
//	uniquePtr(T* ptr=nullptr)
//		:_ptr(ptr)
//	{}
//
//	~uniquePtr(){
//		
//		if (_ptr){
//			
//			delete _ptr;
//		}
//	}
//
//	T& operator*(){ return *_ptr; }
//	T* operator->(){ return _ptr; }
//
//private:
//
//	//C++98防止拷贝的方式是在私有类对于拷贝的方式进行声明,这样就访问不到,可以防止拷贝
//	uniquePtr(uniquePtr<T>const &);
//
//	uniquePtr & operator=(uniquePtr<T> const &);
//
//	//C++11防止拷贝也是在私有类进行创建,只不过要进行  delete!!!
//	uniquePtr(uniquePtr<T>const &) = delete;
//
//	uniquePtr & operator=(uniquePtr<T> const &) = delete;
//
//private:
//	T* _ptr;
//};

//===============shared_ptr============通过引用计数支持智能指针对象的拷贝

/*
1. shared_ptr在其内部，给每个资源都维护了着一份计数，用来记录该份资源被几个对象共享。
2. 在对象被销毁时(也就是析构函数调用)，就说明自己不使用该资源了，对象的引用计数减一。
3. 如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源；
4. 如果不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。
*/

//int main(){
//
//	
//	shared_ptr<Date> sp(new Date);
//	shared_ptr<Date> copy(sp);
//
//	cout << "ref count:" << sp.use_count() << endl;
//	cout << "ref count:" << copy.use_count() << endl;
//
//	system("pause");
//	return 0;
//}

#include<thread>
#include<mutex>

template<class T>
class sharedPtr{

public:

	sharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	~sharedPtr(){ Release(); }

	sharedPtr(const sharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	sharedPtr<T>& operator=(const sharedPtr<T>& sp){
		
		if (_ptr != sp._ptr){
			
			Release();

			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}
		return *this;
	}

	T& operator*(){ return *_ptr; }
	T* operator->(){ return _ptr; }

	int UseCount(){ return *_pRefCount; }
	T* Get(){ return _ptr; }

	void AddRefCount(){
		
		_pMutex->lock();	//加锁

		++(*_pRefCount);	//对于内部的share_ptr的内存共享性进行计数,计数多少个在联系

		_pMutex->unlock();	//解锁
	}

private:

	void Release(){
		
		bool deleteflag = false;

		_pMutex->lock();
		if (--(*_pRefCount) == 0){
			
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag == true)
			delete _pMutex;
	}

private:

	int * _pRefCount;	//引用计数
	T* _ptr;			//资源管理的指针
	mutex* _pMutex;		//互斥锁
};
//
//int main(){
//	
//	sharedPtr<int> sp1(new int(10));		//因为shared_ptr内部是通过一个计数器来控制互相访问的方式的,只要对应的变量
//	sharedPtr<int> sp2(sp1);				//建立了连接,它的计数器就会+1,通过这样的方式来建立shared_ptr的分享
//
//	*sp2 = 20;
//
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//
//	sharedPtr<int> sp3(new int(10));
//
//	sp2 = sp3;
//
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//
//	sp1 = sp3;
//
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//
//	system("pause");
//	return 0;
//}

/*
1.指针中引用计数++、--是需要加锁的，也就是说引用计数的操作是线程安全的。
2.智能指针管理的对象存放在堆上，两个线程中同时去访问，会导致线程安全问题。
*/

void SharePtrFunc(sharedPtr<Date>& sp, size_t n) {
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		sharedPtr<Date> copy(sp);
		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
			copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
//int main()
//{
//	sharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	
//	system("pause");
//	return 0;
//}

//===============weak_ptr============和shared_ptr一起用于循环引用,只能配合使用,
//用于解决shared_ptr的循环引用问题

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode(){ cout << "~ListNode()" << endl; }
};

//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	system("pause");
//	return 0;
//}



//====智能指针和boost库之间的关系

/*
1. C++ 98 中产生了第一个智能指针auto_ptr.
2. C++ boost给出了更实用的scoped_ptr和shared_ptr和weak_ptr.
3. C++ TR1，引入了shared_ptr等。不过注意的是TR1并不是标准版。
4. C++ 11，引入了unique_ptr和shared_ptr和weak_ptr。需要注意的是unique_ptr对应boost的scoped_ptr。并且这些智能指针的实现原理是参考boost中的实现的
*/


template<class Mutex>	//!!!!设计守卫锁，防止异常安全导致的死锁问题!!!!
class LockGuard{

public:

	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}

	~LockGuard()
	{
		_mutex.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;

private:
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;

void Func(){

	for (size_t i = 0; i < 1000000; ++i){

		LockGuard<mutex> lock(mtx);
		++n;
	}
}
int main(){

	int begin = clock();

	thread t1(Func);
	thread t2(Func);

	t1.join();
	t2.join();

	int end = clock();
	cout << n << endl;

	cout << "cost time:" << end - begin << endl;

	system("pause");
	return 0;
}




//thread
#include<thread>
#include<iostream>
#include<mutex>
using namespace std;

//
//int main(){
//	
//	std::thread t1;
//
//	cout << t1.get_id() << endl;
//
//	system("pause");
//	return 0;
//}
//
//void ThreadFunc(int a) {
//	cout << "Thread1" << a << endl;
//}
//class TF
//{
//public:
//	void operator()()
//	{
//		cout << "Thread3" << endl;
//	}
//};
//int main()
//{
//	// 线程函数为函数指针
//	thread t1(ThreadFunc, 10);
//
//
//	// 线程函数为lambda表达式
//	thread t2([]{cout << "Thread2" << endl; });
//
//	// 线程函数为函数对象
//	TF tf;
//	thread t3(tf);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	cout << "Main thread!" << endl;
//
//	system("pause");
//	return 0;
//}

//
//void ThreadFunc1(int& x) {
//	x += 10;
//}
//void ThreadFunc2(int* x) {
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	// 在线程函数中对a修改，不会影响外部实参，因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
//	thread t1(ThreadFunc1, a);
//	
//	t1.join();
//	cout << a << endl;
//	
//	// 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	thread t2(ThreadFunc1, std::ref(a));		//====ref修改函数值
//
//	t2.join();
//	cout << a << endl;
//	
//	// 地址的拷贝
//	thread t3(ThreadFunc2, &a);
//	t3.join();
//	cout << a << endl;
//
//	system("pause");
//	return 0;
//}

//
//class mythread
//{
//public:
//	explicit mythread(std::thread &t) :m_t(t){}
//	
//	~mythread(){
//		if (m_t.joinable())
//			m_t.join();
//	}
//
//	mythread(mythread const&) = delete;
//
//	mythread& operator=(const mythread &) = delete;
//
//private:
//
//	std::thread &m_t;
//};
//
//void ThreadFunc() { cout << "ThreadFunc()" << endl; }
//bool DoSomething() { return false; }
//
//int main(){
//
//	thread t(ThreadFunc);
//	mythread q(t);
//
//	if (DoSomething())
//		return -1;
//
//	system("pause");
//	return 0;
//}
std::mutex m;

unsigned long sum = 0L;
void fun(size_t num) {
	for (size_t i = 0; i < num; ++i)
	{
		m.lock();
		sum++;
		m.unlock();			//加锁保护
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();		//销毁
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;

	system("pause");
	return 0;
}


#include <atomic>		//使用原子性的话,会让每个线程之间的访问产生互斥,也就不需要继续发生加锁解锁操作
int main()
{
	atomic<int> a1(0);
	//atomic<int> a2(a1); // 编译失败
	atomic<int> a2(0);
	//a2 = a1; // 编译失败
	return 0;
}


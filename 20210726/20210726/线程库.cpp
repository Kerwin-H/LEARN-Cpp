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
//	// �̺߳���Ϊ����ָ��
//	thread t1(ThreadFunc, 10);
//
//
//	// �̺߳���Ϊlambda���ʽ
//	thread t2([]{cout << "Thread2" << endl; });
//
//	// �̺߳���Ϊ��������
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
//	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
//	thread t1(ThreadFunc1, a);
//	
//	t1.join();
//	cout << a << endl;
//	
//	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
//	thread t2(ThreadFunc1, std::ref(a));		//====ref�޸ĺ���ֵ
//
//	t2.join();
//	cout << a << endl;
//	
//	// ��ַ�Ŀ���
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
		m.unlock();			//��������
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();		//����
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;

	system("pause");
	return 0;
}


#include <atomic>		//ʹ��ԭ���ԵĻ�,����ÿ���߳�֮��ķ��ʲ�������,Ҳ�Ͳ���Ҫ��������������������
int main()
{
	atomic<int> a1(0);
	//atomic<int> a2(a1); // ����ʧ��
	atomic<int> a2(0);
	//a2 = a1; // ����ʧ��
	return 0;
}


#include<iostream>
#include<string>
#include<vector>
using namespace std;


//�ڴ�й©



//���ڴ�
//��ͨ��malloc / calloc / realloc / new�ȴӶ��з����һ���ڴ棬��������ͨ��������Ӧ�� free����delete ɾ��

//ϵͳ��Դ
//�ȷ��׽��֡��ļ����������ܵ���û��ʹ�ö�Ӧ�ĺ����ͷŵ�������ϵͳ��Դ���˷�

//!!!���ǰ����ʹ������ָ���������ڴ����,��������ڴ��й©

//========ʹ��RAII˼����Ƶ�SmartPtr��
template<class T>
class SmartPtr {
public:

	SmartPtr(T* ptr = nullptr)	//��������ָ��
		: _ptr(ptr)
	{}

	~SmartPtr(){

		if (_ptr)		//��������
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
//=================================����ָ�����Ҫ���� RAII ���������� * -> �����������,������ָ��һ������Ϊ
#include<memory>


//===============auto_ptr============�ڷ������󿽱���ʱ��,ǰ��Ķ���ᱻ����,nullptr

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
//	auto_ptr<Date> copy(ap);	//�ص�!!!�����������������Ǹ��ƺ�,ǰ��Ķ���ͻᱻ����!!!!
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
//	ap->_year = 2018;	//���Ƿ���������apָ���Ѿ���������,ʵ���Ͼ��Ƕ�ԭ����ap���п����Ժ��Ѿ�������
//						//�����ʱ��ap���ڵ�ָ���Ѿ�����ʹ����,�ڷ��ʶ�Ӧ����Դ��ʱ��ͻ����.
//
//	return 0;
//}

//===============unique_ptr============�ֱ��ķ�ʽ���з�ֹ����

//int main3(){
//	
//	unique_ptr<Date> ap(new Date);
//
//	//unique_ptr<Date> copy(ap);	//�����ʱ���ܷ�������
//								// unique_ptr�����˼·�ǳ��Ĵֱ�-��������Ҳ���ǲ��ÿ����͸�ֵ��
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
//	//C++98��ֹ�����ķ�ʽ����˽������ڿ����ķ�ʽ��������,�����ͷ��ʲ���,���Է�ֹ����
//	uniquePtr(uniquePtr<T>const &);
//
//	uniquePtr & operator=(uniquePtr<T> const &);
//
//	//C++11��ֹ����Ҳ����˽������д���,ֻ����Ҫ����  delete!!!
//	uniquePtr(uniquePtr<T>const &) = delete;
//
//	uniquePtr & operator=(uniquePtr<T> const &) = delete;
//
//private:
//	T* _ptr;
//};

//===============shared_ptr============ͨ�����ü���֧������ָ�����Ŀ���

/*
1. shared_ptr�����ڲ�����ÿ����Դ��ά������һ�ݼ�����������¼�÷���Դ������������
2. �ڶ�������ʱ(Ҳ����������������)����˵���Լ���ʹ�ø���Դ�ˣ���������ü�����һ��
3. ������ü�����0����˵���Լ������һ��ʹ�ø���Դ�Ķ��󣬱����ͷŸ���Դ��
4. �������0����˵�������Լ���������������ʹ�ø÷���Դ�������ͷŸ���Դ��������������ͳ�Ұָ���ˡ�
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
		
		_pMutex->lock();	//����

		++(*_pRefCount);	//�����ڲ���share_ptr���ڴ湲���Խ��м���,�������ٸ�����ϵ

		_pMutex->unlock();	//����
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

	int * _pRefCount;	//���ü���
	T* _ptr;			//��Դ�����ָ��
	mutex* _pMutex;		//������
};
//
//int main(){
//	
//	sharedPtr<int> sp1(new int(10));		//��Ϊshared_ptr�ڲ���ͨ��һ�������������ƻ�����ʵķ�ʽ��,ֻҪ��Ӧ�ı���
//	sharedPtr<int> sp2(sp1);				//����������,���ļ������ͻ�+1,ͨ�������ķ�ʽ������shared_ptr�ķ���
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
1.ָ�������ü���++��--����Ҫ�����ģ�Ҳ����˵���ü����Ĳ������̰߳�ȫ�ġ�
2.����ָ�����Ķ������ڶ��ϣ������߳���ͬʱȥ���ʣ��ᵼ���̰߳�ȫ���⡣
*/

void SharePtrFunc(sharedPtr<Date>& sp, size_t n) {
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		sharedPtr<Date> copy(sp);
		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ��������տ����Ľ������һ���Ǽ���2n
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

//===============weak_ptr============��shared_ptrһ������ѭ������,ֻ�����ʹ��,
//���ڽ��shared_ptr��ѭ����������

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



//====����ָ���boost��֮��Ĺ�ϵ

/*
1. C++ 98 �в����˵�һ������ָ��auto_ptr.
2. C++ boost�����˸�ʵ�õ�scoped_ptr��shared_ptr��weak_ptr.
3. C++ TR1��������shared_ptr�ȡ�����ע�����TR1�����Ǳ�׼�档
4. C++ 11��������unique_ptr��shared_ptr��weak_ptr����Ҫע�����unique_ptr��Ӧboost��scoped_ptr��������Щ����ָ���ʵ��ԭ���ǲο�boost�е�ʵ�ֵ�
*/


template<class Mutex>	//!!!!�������������ֹ�쳣��ȫ���µ���������!!!!
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
	// ע���������ʹ�����ã��������ľͲ���һ������������
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




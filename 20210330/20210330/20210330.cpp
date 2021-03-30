#include<iostream>
#include<vector>
using namespace std;


class Vector{

public:
	//��ʼ��
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}


	Vector(size_t n, const T& val = T())
		:_start(new T(n))
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; ++i)
			_start[i] = val;
	}

	template <class inputIterator>
	Vector(inputIterator first, inputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		//[first,last)
		while (first != last){

			pushBack(*first);
			++first;
		}
	}


	void pushBack(const T& val){

		//�������
		if (_finish == _endOfStorage){

			//����
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}

		//����
		*_finish = val;

		//����size
		++_finish;
	}

	void reserve(size_t n){

		if (n > capacity()){

			//���ȱ���ԭ��������
			size_t sz = size();

			//���ٿռ�
			T* arr = new T[n];

			//��������
			if (_start){

				memcpy(arr, _start, sizeof(T)*sz);
				delete[] _start;
			}
			//����
			_start = arr;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}


	//����������: T*
	typedef T* iterator;
	typedef const T* const_iterator;

	size_t size()const
	{
		return _finish - _start;
	}

	size_t capacity()const
	{
		return _endOfStorage - _start;
	}

	iterator begin(){

		return _start;
	}

	iterator end(){

		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

private:

	iterator _start;
	iterator _finish;
	iterator _endOfStorage;
};

struct A{

	explicit A(int a = 0)
	:_a(a)
	{
		cout << "A(int)" << endl;
	}
	int _a = 10;
};

template<class T>
void printVector(const Vector<T>& vec){

	Vector<T>::const_iterator cit = vec.begin();
	while (cit != vec.end()){

		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

template<class T>
void printForVector(const Vector<T>& vec){

	for (suto& e : vec){

		cout << e << " ";
		//e=T();
	}
	cout << endl;
}

void test(){


}



int main(){

	test();

	return 0;
}
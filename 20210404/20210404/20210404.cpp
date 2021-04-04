#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Vector{

public:
	typedef T* iterator;
	typedef const T* const_iterator;


	//初始化
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

		//检查容量
		if (_finish == _endOfStorage){

			//增容
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}

		//插入
		*_finish = val;

		//更新size
		++_finish;
	}

	void reserve(size_t n){

		if (n > capacity()){

			//首先保留原来的数据
			size_t sz = size();

			//开辟空间
			T* arr = new T[n];

			//拷贝数据
			if (_start){

				memcpy(arr, _start, sizeof(T)*sz);
				delete[] _start;
			}
			//更新
			_start = arr;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	//==========================================20210403
	void resize(size_t n, const T& val = T()){
		
		//n>capacity:增容
		if (n > capacity()){
			reserve(n);
		}

		if (n > size()){
			
			while (_finish != _start + n){
				*_finish = val;
				++_finish;
			}
		}
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val){
		
		if (pos >= _start&&pos <= _finish){
			
			//容量检查
			if (_finish == _endOfStorage){
				
				size_t num = pos - _start;

				size_t n = _endOfStorage == nullptr ? 1 : 2 * capacity();

				reserve(n);
				pos = _start + num;
			}
			iterator end = _finish;
			while (end != pos){
				
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
		}
	}

	iterator erase(iterator pos){
		
		if (pos < _finish&& pos >= _start){
			
			iterator start = pos + 1;
			while (start != _finish){
				
				*(start - 1) = *start;
				++start;
			}
			--_finish;
		}
		return pos;
	}

	void popBack(){
		
		erase(end() - 1);
	}

	//===========================================

	//迭代器类型: T*
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
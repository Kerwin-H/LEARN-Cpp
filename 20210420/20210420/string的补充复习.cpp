#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
#include<string>
#include<iostream>
using namespace std;


class String{

public:

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin(){

		return _data;
	}

	const_iterator begin() const{

		return _data;
	}

	iterator end(){

		return _data + _size;
	}

	const_iterator end() const{

		return _data + _size;
	}

	String(const char* str = "")
		:_size(strlen(str))
		, _capacity(_size)
		, _data(new char[_size + 1])
	{
		strcpy(_data, str);
	}

	String(const String& str)
		:_size(0)
		, _capacity(0)
		, _data(nullptr)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	void Swap(String& str){

		swap(_size, str._size);
		swap(_capacity, str._capacity);
		swap(_data, str._data);
	}

	String& operator=(String str){

		Swap(str);
		return *this;
	}

	~String(){

		if (_data){

			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t size()const{

		return _size;
	}

	size_t capacity() const{

		return _capacity;
	}

	char& operator[](size_t pos){

		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos)const{

		assert(pos < _size);
		return _data[pos];
	}

	const char* c_str()const{

		return _data;
	}

	void pushBack(const char& ch){

		if (_size == _capacity){

			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		_data[_size] = ch;
		++_size;

		_data[_size] = '\0';
	}

	void reserve(size_t n){

		if (n > _capacity){

			char* tmp = new char[n + 1];

			strcpy(tmp, _data);

			delete[] _data;

			_data = tmp;
			_capacity = n;
		}
	}

	void resize(size_t n, const char& ch = '\0'){

		if (n > _capacity){

			reserve(n);
		}

		if (n > _size){

			memset(_data + _size, ch, sizeof(char)*(n - _size));

			_size = n;
			_data[_size] = '\0';
		}
	}

	void append(const char* str){

		int len = strlen(str);
		if (_size + len > _capacity){

			reserve(_size + len);
		}

		memcpy(_data + _size, str, sizeof(char)*len);

		_size += len;
		_data[_size] = '\0';
	}

	//+=
	String& operator+=(const String& str){

		append(str._data);
		return *this;
	}
	String& operator+=(const char* str){

		append(str);
		return *this;
	}
	String& operator+=(const char ch){

		pushBack(ch);
		return *this;
	}

	void insert(size_t pos, const char& ch){

		assert(pos <= _size);

		if (_size == _capacity){

			size_t newc = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newc);
		}

		size_t end = _size + 1;
		while (end > pos){

			_data[end] = _data[end - 1];
			--end;
		}

		_data[pos] = ch;

		_size++;
	}

	void insert(size_t pos, const char* ptr){

		assert(pos <= _size);

		int len = strlen(ptr);
		if (_size + len > _capacity){

			reserve(_size + len);
		}

		size_t end = _size + len;
		while (end > pos + len - 1){

			_data[end] = _data[end - len];
			--end;
		}

		memcpy(_data + pos, ptr, sizeof(char)*len);

		_size += len;
	}

	void erase(size_t pos, size_t len = npos){

		assert(pos<_size);

		if (len == npos || pos + len >= _size){

			_size = pos;
			_data[_size] = '\0';
		}
		else{

			size_t start = pos + len;
			while (start <= _size){

				_data[start - len] = _data[start];
				start++;
			}
			_size -= len;  //注意这里的调用接口
		}
	}

	size_t find(const char& ch, size_t pos = 0){

		for (size_t i = pos; i < _size; ++i){

			if (_data[i] == ch)
				return i;
		}
		return npos;
	}

	size_t find(const char* ptr, size_t pos = 0){

		assert(pos<_size);

		char* ptrpos = strstr(_data + pos, ptr);
		if (ptrpos){

			return ptrpos - _data;
		}
		return npos;
	}

	String substr(size_t pos, size_t len = npos){

		assert(pos < _size);

		if (len == npos || pos + len >= _size){

			return String(_data + pos);
		}
		else{

			char* newc = new char[len + 1];

			memcpy(newc, _data + pos, sizeof(char)*len);

			newc[len] = '\0';
			return String(newc);
			delete[] newc;
		}
	}



private:

	size_t _size;
	size_t _capacity;
	char* _data;
	static const size_t npos;
};


void test(){

	String str = "123456";
	str.resize(10);
}


int main(){

	test();

	system("pause");
	return 0;
}

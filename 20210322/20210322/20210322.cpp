#include<assert.h>
#include<string>
#include<iostream>
using namespace std;




//=======自己编写一个String类
class String{

public:
	//String迭代器
	//实现:字符指针
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin(){		//迭代器找到首元素
		
		//首元素的位置
		return _data;
	}

	const_iterator begin() const{	//迭代器找到首元素的位置
		
		//第一个元素的位置
		return _data;
	}

	iterator end(){
		
		//最后一个元素的下一个位置
		return _data + _size;
	}

	const_iterator end() const{
		
		//最后一个元素的下一个位置
		return _data + _size;
	}

	//构造函数
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

	//交换函数
	void Swap(String& str){
		
		swap(_size, str._size);
		swap(_capacity, str._capacity);
		swap(_data, str._data);
	}

	//=改变
	String& operator=(String str){
		
		Swap(str);
		return *this;
	}

	//析构函数
	~String(){
		
		if (_data){

			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t size() const{
		
		return _size;
	}

	size_t capacity() const{
		
		return _capacity;
	}

	//[]
	char& operator[](size_t pos){
		
		assert(pos < _size);
		return _data[pos];
	}

	//[]
	const char& operator[](size_t pos) const{
		
		assert(pos < _size);
		return _data[pos];
	}

	const char* c_str() const{
		
		return _data;
	}


	//尾插一个字符
	void pushBack(const char& ch){
		
		if (_size == _capacity){
			
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		_data[_size] = ch;
		++_size;

		_data[_size] = '\0';
	}

	//扩容
	void reserve(size_t n){
		
		if (n > _capacity){
			
			char* tmp = new char[n + 1];

			strcpy(tmp, _data);

			delete[] _data;

			_data = tmp;
			_capacity = n;
		}
	}

	//改变有效字符的个数
	void resize(size_t n, const char& ch = '\0'){
		
		if (n > _capacity){
			
			reserve(n);
		}

		if (n > _size)
			memset(_data + _size, ch, sizeof(char)*(n - _size));

		_size = n;
		_data[_size] = '\0';
	}

	//类似于尾插
	void append(const char* str){
		
		int len = strlen(str);
		if (_size + len > _capacity){
			
			reserve(_size + len);
		}
		
		memcpy(_data + _size, str, sizeof(char)* len);

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
private:
	//size:有效字符个数
	size_t _size;
	//容量:最大存放字符的个数
	size_t _capacity;
	char* _data;
};

//分为String类//字符串//单个字符

String operator+(const String& str1, const String& str2){
	
	String str = str1;
	str += str2;
	return str;
}

String operator+(const char* str1, const String& str2){
	
	String str(str1);
	str += str2;
	return str;
}

String operator+(const char ch, const String& str2){

	String str = str2;
	str += ch;
	return str;
}

//普通打印
void printString(const String& str){
	
	for (int i = 0; i < str.size(); ++i){
		
		cout << str[i] << " ";
	}
	cout << endl;
}

//字符串类的打印
void printFor(const String& str){
	
	for (const char& ch : str){
		
		cout << ch << " ";
	}
	cout << endl;
}

//利用迭代器方式的打印
void printIterator(const String& str){
	
	String::const_iterator it = str.begin();
	while (it != str.end()){
		
		cout << *it << " ";

		++it;
	}
	cout << endl;
}
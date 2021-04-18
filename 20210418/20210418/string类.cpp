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
	//==============================================================================0328
	//====简单插入
	void  insert(size_t pos, const char& ch){

		//0.检查位置是否有效[0,size]
		assert(pos <= _size);

		//1.容量检查
		if (_size == _capacity){

			size_t newc = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newc);
		}
		//2.从后向前移动元素(先将\0放在最后,以免最后的添加)
		size_t end = _size + 1;
		while (end > pos){

			_data[end] = _data[end - 1];
			--end;
		}
		//3.插入
		_data[pos] = ch;
		//4.更新
		_size++;

	}
	//pos定点插入
	void insert(size_t pos, const char* ptr){

		assert(pos <= _size);

		int len = strlen(ptr);
		if (_size + len > _capacity){

			reserve(_size + len);
		}

		size_t end = _size + len;
		while (end>pos + len - 1){

			_data[end] = _data[end - len];
			--end;
		}
		//n的循环
		/*for (int i = 0; i < len; ++i){

		_data[i + pos] = ptr[i];
		}
		*/
		memcpy(_data + pos, ptr, sizeof(char)*len);

		_size += len;
	}
	//====删除其中一部分   默认值类似于缺省,删除所有的元素
	void erase(size_t pos, size_t len = npos){

		assert(pos < _size);
		if (len == npos || pos + len >= _size){

			_size = pos;
			_data[_size] = '\0';
		}
		else{

			size_t start = pos + len;

			//[pos+len,size]
			while (start <= _size){

				//依次向前移动
				_data[start - len] = _data[start];
				start++;
			}
			_size -= len;
		}
	}

	size_t find(const char& ch, size_t pos = 0){

		for (size_t i = pos; i < _size; ++i){

			if (_data[i] == ch)
				return i;
		}
		//越界
		return npos;
	}

	//寻找对应的字符串位置
	size_t find(const char* ptr, size_t pos = 0){

		assert(pos < _size);
		char* ptrPos = strstr(_data + pos, ptr);
		if (ptrPos){

			return ptrPos - _data;
		}
		return npos;
	}
	//选取字符串中要寻找的子串
	String substr(size_t pos, size_t len = npos){

		assert(pos < _size);

		if (len == npos || pos + len >= _size){

			//String str(_data + pos)
			//return str;	

			return String(_data + pos);
		}
		else{

			char* newC = new char[len + 1];

			memcpy(newC, _data + pos, sizeof(char)*len);
			newC[len] = '\0';
			return String(newC);
			delete[] newC;
		}
	}


private:
	//size:有效字符个数
	size_t _size;
	//容量:最大存放字符的个数
	size_t _capacity;
	char* _data;

	static const size_t npos;
};

//静态成员在外部进行定义
const size_t String::npos = -1;

ostream& operator<<(ostream& out, const String& str){

	for (const auto& ch : str)
		out << ch;
	return out;
}

istream& operator>>(istream& in, String& str){

	char ch;
	while (ch = cin.get()){	//利用grt函数接口,遇到空格时结束

		if (ch == ' ' || ch == '\n')
			break;
		//尾插
		str += ch;
	}

	return in;
}




void test(){

	String str;


}




//===============================================================
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


int main(){

	test();

	return 0;
}
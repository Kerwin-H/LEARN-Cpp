#include<assert.h>
#include<string>
#include<iostream>
using namespace std;




//=======�Լ���дһ��String��
class String{

public:
	//String������
	//ʵ��:�ַ�ָ��
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin(){		//�������ҵ���Ԫ��
		
		//��Ԫ�ص�λ��
		return _data;
	}

	const_iterator begin() const{	//�������ҵ���Ԫ�ص�λ��
		
		//��һ��Ԫ�ص�λ��
		return _data;
	}

	iterator end(){
		
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	const_iterator end() const{
		
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	//���캯��
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

	//��������
	void Swap(String& str){
		
		swap(_size, str._size);
		swap(_capacity, str._capacity);
		swap(_data, str._data);
	}

	//=�ı�
	String& operator=(String str){
		
		Swap(str);
		return *this;
	}

	//��������
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


	//β��һ���ַ�
	void pushBack(const char& ch){
		
		if (_size == _capacity){
			
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		_data[_size] = ch;
		++_size;

		_data[_size] = '\0';
	}

	//����
	void reserve(size_t n){
		
		if (n > _capacity){
			
			char* tmp = new char[n + 1];

			strcpy(tmp, _data);

			delete[] _data;

			_data = tmp;
			_capacity = n;
		}
	}

	//�ı���Ч�ַ��ĸ���
	void resize(size_t n, const char& ch = '\0'){
		
		if (n > _capacity){
			
			reserve(n);
		}

		if (n > _size)
			memset(_data + _size, ch, sizeof(char)*(n - _size));

		_size = n;
		_data[_size] = '\0';
	}

	//������β��
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
	//size:��Ч�ַ�����
	size_t _size;
	//����:������ַ��ĸ���
	size_t _capacity;
	char* _data;
};

//��ΪString��//�ַ���//�����ַ�

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

//��ͨ��ӡ
void printString(const String& str){
	
	for (int i = 0; i < str.size(); ++i){
		
		cout << str[i] << " ";
	}
	cout << endl;
}

//�ַ�����Ĵ�ӡ
void printFor(const String& str){
	
	for (const char& ch : str){
		
		cout << ch << " ";
	}
	cout << endl;
}

//���õ�������ʽ�Ĵ�ӡ
void printIterator(const String& str){
	
	String::const_iterator it = str.begin();
	while (it != str.end()){
		
		cout << *it << " ";

		++it;
	}
	cout << endl;
}
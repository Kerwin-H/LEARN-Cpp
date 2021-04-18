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
	//==============================================================================0328
	//====�򵥲���
	void  insert(size_t pos, const char& ch){

		//0.���λ���Ƿ���Ч[0,size]
		assert(pos <= _size);

		//1.�������
		if (_size == _capacity){

			size_t newc = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newc);
		}
		//2.�Ӻ���ǰ�ƶ�Ԫ��(�Ƚ�\0�������,�����������)
		size_t end = _size + 1;
		while (end > pos){

			_data[end] = _data[end - 1];
			--end;
		}
		//3.����
		_data[pos] = ch;
		//4.����
		_size++;

	}
	//pos�������
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
		//n��ѭ��
		/*for (int i = 0; i < len; ++i){

		_data[i + pos] = ptr[i];
		}
		*/
		memcpy(_data + pos, ptr, sizeof(char)*len);

		_size += len;
	}
	//====ɾ������һ����   Ĭ��ֵ������ȱʡ,ɾ�����е�Ԫ��
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

				//������ǰ�ƶ�
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
		//Խ��
		return npos;
	}

	//Ѱ�Ҷ�Ӧ���ַ���λ��
	size_t find(const char* ptr, size_t pos = 0){

		assert(pos < _size);
		char* ptrPos = strstr(_data + pos, ptr);
		if (ptrPos){

			return ptrPos - _data;
		}
		return npos;
	}
	//ѡȡ�ַ�����ҪѰ�ҵ��Ӵ�
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
	//size:��Ч�ַ�����
	size_t _size;
	//����:������ַ��ĸ���
	size_t _capacity;
	char* _data;

	static const size_t npos;
};

//��̬��Ա���ⲿ���ж���
const size_t String::npos = -1;

ostream& operator<<(ostream& out, const String& str){

	for (const auto& ch : str)
		out << ch;
	return out;
}

istream& operator>>(istream& in, String& str){

	char ch;
	while (ch = cin.get()){	//����grt�����ӿ�,�����ո�ʱ����

		if (ch == ' ' || ch == '\n')
			break;
		//β��
		str += ch;
	}

	return in;
}




void test(){

	String str;


}




//===============================================================
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


int main(){

	test();

	return 0;
}
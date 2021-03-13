#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


class A{

public:
	int _a;
	A(int a = 10){
		_a = a;
		cout << "A()" << endl;
	}
};

class Date{

public:

	Date(int year = 1, int month = 1, int day = 1){

		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int)" << endl;
	}

	Date(int  year, int month, int day, int num){

		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int,int)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;


	A _a;
};


class Date{

public:

	Date(int year = 1, int month = 1, int day = 1){

		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int)" << endl;
	}
	void Display()	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date(){}
private:
	int _year;
	int _month;
	int _day;

};

typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));

		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_capacity = 0;
			_size = 0;
			cout << "~SeqList" << endl;
		}
	}

private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

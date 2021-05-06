#include<iostream>
#include<array>
using namespace std;


//====1.ģ����ػ�
template <class T>
bool isEqual(T a, T b){

	return a == b;
}

template <>
bool isEqual<char*>(char* a, char* b){

	return strcmp(a, b) == 0;
}

//
//
//void test(){
//	
//	bool ret = isEqual(1, 2);
//	ret = isEqual(2.3, 2.3);
//	ret = isEqual("123", "123");
//
//	char* ptr = "123";
//	char ptr2[] = "123";
//	ret = isEqual(ptr, ptr2);
//
//}


//void test1(){
//	
//	//array<T,size_t>: size_t --->������ģ�����
//	//ֻ������������,���ܸ������������Զ������͵�����
//	array<int, 10> arr;
//
//}


//=====2.��ģ����ػ�  Ӧ�ó���: ������ȡ
//�ȳ�ʼ��һ���򵥵�ģ��
template<class T1, class T2>
struct D{

public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1,T2)" << endl;
	}

	T1 _d1;
	T2 _d2;
};
//�ػ�: ȫ�ػ�: ���е����Ͷ��Ǿ�������
template <>
struct D<char, double>{

	D(const char& d1, const double& d2)
	:_d1(d1)
	, _d2(d2)
	{
		cout << "D(char,double)" << endl;
	}

	char _d1;
	double _d2;
};


//====3.ƫ�ػ�
//1.ֻ�ػ����ֵ�����
template <class T1>
struct D<T1, char>{

	D(const T1& d1, const double& d2)
	:_d1(d1)
	, _d2(d2)
	{
		cout << "D(T1,char)" << endl;
	}

	T1 _d1;
	double _d2;
};
//2.��ģ���������һ��������
template <class T1, class T2>
struct D<T1*, T2*>{

public:
	D(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "D(T1*,T2*)" << endl;
	}

	T1 _d1;
	T2 _d2;
};


void test(){

	D<int, int> d(1, 1);		//����ͨ��ģ���ʵ����

	D<char, double> d2('a', 1.1);		//ȫ�ػ�ģ���ʵ����

	D<int, char> d3(1, 'a');	//ƫ�ػ���ģ��ʵ����

	D<int*, int* > d4(1, 2);	//ƫ�ػ���ģ��ʵ����
}


int main(){

	test();

	system("pause");
	return 0;
}

//ģ�������:
//1.���������ͬһ���ļ���
//2.���Է�ֹ����Ա�ڱ�̵�ʱ���ظ��Ĳ���,���Ч��
//3.��ʡ��Դ,����ĵ�������
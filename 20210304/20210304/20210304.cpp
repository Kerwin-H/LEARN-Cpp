#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


//========5.��ֵ���������
//====(1)���������
class Date{

public:
	Date(int y = 1, int m = 1, int d = 1){
		
		_y = y;
		_m = m;
		_d = d;
	}
	
	bool isEqual(const Date& d){
		
		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}

	Date(const Date& d){
		
		_y == d._y;
		_m == d._m;
		_d == d._d;
		cout << "Date(const Date&)" << endl;
	}

	//��Ա�����������ص�thisָ��
	//��Ϊ��Ա����,�����ʵ�ʵ���һ��

	//������ֵ�this ָ��ʱ��ָ��������ҵĵĵ�һ��ָ��
	bool operator==(const Date& d){
		
		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}


	//�����Ҫ����������ֵ,�򷵻�ֵ���Ͳ���Ϊ��
	//����ֵ����Ϊ��ǰ���� 
	Date& operator=(const Date& d){
		
		//�Ż�,�ж϶����Ƿ���ͬһ������: ͨ��ָ������ж�
		if (this != &d){

			_y == d._y;
			_m == d._m;
			_d == d._d;
			cout << "operator=" << endl;
		}
		return *this;	//���ص�ǰ������õĶ���Ķ�Ӧָ��,�ٴ�����һλ����
		//return d;
	}

	~Date(){
		cout << "~Date()" << endl;
	}

private:
	int _y;
	int _m;
	int _d;
};

//==���������
//������: operator==
//1.ֻ�������Ѿ����ڵ������,��@�����ķ��žͲ���
//5.  * :: sizeof ?: . ����������,�����ڱ������г���

bool operator==(const Date& d1, const Date& d2){}

//==2.3.�������͵Ĳ��ܽ����޸�--->����������в�����Ϊ��������
//int operator+(int a, int b){	//����һЩ�ڲ����������Ԫ�ز��ܽ�������
//	return a*b;					//����+-*/���ֵ�
//}

void test1(){

	Date d1(2021,12,25);
	Date d2(2021,12,25);
	//�ж������Ƿ����
	if (d1 == d2){	//�����������������������ص�ʱ������Ͳ�������

					//��Ϊ�����==������жϲ�����ڲ������껹���»����յ�
					//�ж�,��������Ҫ�����==�������������,�����ڲ�������
					//�¶���,��==�������ڽ��бȽϵķ�ʽ,���ܽ������ڵıȽ�! 
	}
	//====������������ص�������ʽ
	//if (d1.operator==(d2))
		//�����������غ������ǳ�Ա�ڲ��ĺ���
		//if (operator==(d1,d2))

	//һ��������ļ�д��ʽ,�ȽϷ���,�������������
		if(d1==d2)
	{
		cout << "==" << endl;
	}
	else{
		cout << "!=" << endl;
	}
	
	//if (d1.isEqual(d2)){	//ֱ��������ڲ�����һ����Ա����,ֱ���ǽ������������ıȽ�	
	//}
}

//====(2)��ֵ���������
void test(){
	
	Date d1(2021, 12, 25);
	Date d2(2091, 12, 25);
	Date d3(2031, 12, 25);


	//��ֵ����
	////��д
	//d1 = d2;
	////ȫд
	//d2.operator=(d3);		//���û����ʾ����,���������Զ��޸�����

	//d2 = d2;	//������Լ����Լ����ж���,���ǿ���ͨ��������Ա���Ż��������һ�����


	int a, b, c;
	//������ֵ:��������
	a = b = c = 100;

	//������ʽ
	d1.operator=(d2.operator=(d3));
	//��д��ʽ
	d1 = d2 = d3;		//====������յ��Ĳ������Ͳ�ͬ

	//���Ǹ�ֵ,Ϊ��������
	Date d4 = d1;	//���Ѿ����ڵı������µı������г�ʼ��,��ɿ�������
}


class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
void test()
{
	String s1("hello");		//����������Դ��ʱ��,��Ҫ��ʾ���帳ֵ,��ʾ���忽������
	String s2("world");		//��ֹ���еĿռ��޷������ͷ�,��ɾ޴����ʧ

	s1 = s2;
}


int main(){
	
	test();

	system("pause");
	return 0;
}






#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��C++��,�ṹ�岻����Զ��������,�����Զ��������
//��������Ľṹ��Ͳ�������һ���ṹ��,����һ��"��"
//��Ϊ�����а����˽ṹ��Ķ���,�ͽṹ����صĺ���
//========�������+����

//class Student{};//����//�����ֶ��巽ʽ��һ����,������ǰ��ĵ��ʲ�һ��
//C++�г��õĶ��巽ʽ:    class + ���� + {���еĳ�Ա};
struct Student{

public:		//========����Ȩ��
	//������: �����η���ʼ����һ�����η�����ʱ����

	//��Ա����
	void SetStudentInfo(const char* name, const char* gender, int age){
		
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo(){
		cout << _name << " " << _gender << " " << _age << endl;
	}

	//��Ա����
	char _name[20];
	char _gender[3];
	int _age;
};

void test1(){
	
	Student stu;	
	//���Ա��ʹ��,����Ҫͨ���������޶����ķ�ʽʹ��
	//ͨ��"."�ķ�ʽ,�����ָ��,ͨ��"->"����ʽ

	stu.SetStudentInfo("hu", "��", 20);
	stu.PrintStudentInfo();
	cout << stu._gender << endl;
}

//========struct class����
//struct �������  ,Ĭ�Ϸ���Ȩ��Ϊpublic
class A{
public:
	int _a;
};
//class Ĭ�Ϸ���Ȩ��Ϊprivate
class B{
public:
	int fun1(int a, int b){
		return a + b;
	}
public:
	int _b;
};

class C{
public:
	int fun2(int a, int b){
		
		return a + b;
	}

};

class D{};
void test(){
	
	//����һ�������͵ı���:��Ϊ���ʵ����
	//ʵ�����ı�����Ϊ��Ķ���
	A oa;	//oa����Aʵ������һ������
	oa._a = 10;

	B ob;
	//ob._b = 5;


	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

}


int main(){
	
	test();

	system("pause");
	return 0;
}

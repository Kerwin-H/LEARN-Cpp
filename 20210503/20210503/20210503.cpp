#include<iostream>
using namespace std;
//��̬������
//0.ǰ��: �̳�
//1.���麯��
//2.������д������麯��
//3.���ô˺����������ǻ����ָ��,����

//
//class Person{
//
//public:
//	//�麯��: vritual +�����ĺ�������
//	virtual void BuyTicket(){ cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student:public Person{
//
//	//�麯������д: ���ඨ����һ���͸���ӿ���ȫ��ͬ�ĺ���
//	//��д���麯��������,�����б�,����ֵ�͸����Ӧ�ĺ�����ȫһ��
//public:
//	//�麯��: vritual +�����ĺ�������
//	virtual void BuyTicket(){ cout << "��Ʊ-���" << endl; }
//};
//
////��̬������
//void fun(Person& p){
//	
//	p.BuyTicket();
//}
////���������������ж��Ƿ��Ƕ�̬
//void fun2(Person p){
//	p.BuyTicket();
//}
//
//void test(){
//
//	Person p;
//	Student s;
//
//	fun(p);
//	fun(s);
//
//	fun2(p);
//	fun2(s);
//}
////Э��:����ֵ���Ϳ��Բ�ͬ,���Ǳ������м̳й�ϵ��ָ��/����
//
////�������������
//
///*class A final{};
//
//class B :public A{};*/	//����,����final���������յ�����,�޷��ٽ�����չ
//
//
//class A{
//
//public:
//	virtual void fun() final{
//		
//		cout << "A::fun() final" << endl;	//�����޷����̳�
//	}
//};

//ǿ����д
//override //�������������û����д��Ӧ���麯��,���û����д��ᱨ��


//���麯��: ����=0
//�����಻�ܷ���ʵ����
//������: ���ж����˴��麯��

//=====�ӿڵ�ʵ��

//class A{
//
//public:
//	virtual void fun(){
//		
//		cout << "A::fun()" << endl;
//	}
//
//private:
//	int _a = 1;
//};
//void test(){
//
//	cout << sizeof(A) << endl;
//} 

//�̳й�ϵ���麯����

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//void test(){
//	
//	Base b;
//	Derive d;
//}

//��̳�

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
//һ������̳�����������

typedef void(*vfptr)();
void printVTable(vfptr vfTable[]){

	cout << "����ַ:" << vfTable << endl;
	vfptr* fptr = vfTable;
	while (*fptr != nullptr){

		(*fptr)();
		++fptr;
	}
}


void test(){

	Base1 b;
	Base2 b2;
	Derive d;

	cout << "Base1 vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&b);
	printVTable(vftable);

	cout << "Base2 vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&b2);
	printVTable(vftable);

	cout << "Derive vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&d + sizeof(Base1));
	printVTable(vftable);

	cout << "Derive vfptr:";
	vfptr* vftable = (vfptr*)(*(int*)&d + sizeof(Base1));
	printVTable(vftable);
}



int main(){

	test();

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

//==========1.C++ �̳з�ʽ


//class Person{
//
//public:
//	void Print(){
//		
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "peter";
//	int _age = 18;
//};


//�̳�==������: �̳з�ʽ  �̳���(�����д�̳з�ʽ,���ֱ��Ĭ��˽�еļ̳з�ʽ)
//�����public����֧�ּ̳����ڲ��ĳ�Ա�ķ���

//class Student :protected Person  ������̳�
//class Student :private Person	   ˽����̳�
//class Student :public Person
//{};
//
//class Empty{};

//
//void test(){
//
//
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Person s;
//
//	s._age = 5;
//	s.Print();		//�����public��ᱨ��
//}
//!!!��Ҫ���Ǹ��ݷ��ʷ�ʽ�Ĳ�ͬ,����Ӧ�Ĺ�������иı�


//2.==========�����������ĸ�ֵת��

//void test(){
//	
//	Person p;
//	Student stu;
//
//	//��Ƭ:�������,ָ��,���ø�ֵ������Ķ���,ָ��,����
//	p = stu;
//	Person& rs = stu;
//	Student& rs2 = stu;
//	Person& rs3 = rs2;
//	Person* ps = &stu; 
//	Student* ps2 = &stu;
//
//	//���ܸ������ֵ���������
//	//stu=(Student)p;
//	//����ָ��,���ò���ֱ�Ӹ�ֵ������ָ��,��Ҫ��������
//	//���ǿ��Խ���ǿ������ת�������и�ֵ
//
//	rs.Print();
//
//
//	int a = 10;
//	float b = 1.1;
//	a = b;	//��ʽ����ת��
//	Student stu;
//	stu.Person::Print();
//
//}


//==========��Ӧ�����ֺ���
//class A{
//
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& a)
//		:_a(a._a)
//	{	
//		cout << "A(const A&)" << endl;
//	}
//
//	A& operator=(const A& a){
//		
//		if (this != &a){
//			
//			_a = a._a;
//		}
//		cout << "A& operator=" << endl;
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//protected:
//	int _a;
//};
//
//class B:public A{
//
//public:
//	B(int a, int b)
//		:A(a)		//��Aд�ڳ�ʼ���б�
//		, _b(b)
//	{
//		cout << "B(int,int) " << endl;
//	}
//
//	//��ʾ����Ŀ�������,Ĭ�ϵ���A��Ĭ�Ϲ���
//	B(const B& b)
//		:_b(b._b)
//	{
//		cout << " B(const B&)" << endl;
//	}
//
//	//��ʾ����ĸ�ֵ�����,������ø���ĸ�ֵ�����
//	B& operator=(const B& b){
//		
//		if (this != &b){
//			
//
//			//A::operator=(b);	//���ø���ĸ�ֵ�����
//
//			_a = b._a;
//			_b = b._b;
//		}
//		cout << "B& operator=" << endl;
//		return *this;
//	}
//
//	//��ʾ�������������,�ں�����ִ������Ӻ�,���Զ����ø�������� 
//
//	//��������������: destructor
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//
//protected:
//	int _b;
//};

//void test(){
//	
//	//����Ĭ�ϵĹ��캯��,�Զ����ø��๹�캯��
//	//��ɸ����Ա�ĳ�ʼ��,�������û�ж��µĳ�Ա���й���,�ͻ�������ֵ
//	B b(10,100);
//	
//	//B copy(b);	//����Ҳ��Ĭ�ϵ��ø���Ŀ���������ɿ���
//
//	
//
//	//B copy(b);
//	//����Ĭ�ϵĸ�ֵ�����,�Զ����ø���ĸ�ֵ�����
//	//b = copy;
//	 
//}

//��Ԫ
//����ľ�̬��Ա,�������̳���ϵ���ǹ����
struct A{

	static int _i;
};

int A::_i = 0;

struct B :public A
{};

void test(){

	A a;
	B b;
	a._i = 1;
	b._i = 2;
	A::_i = 3;
	B::_i = 4;

}

//class A:public B,public C,.......//��̳еķ�ʽ

//���μ̳�: ��������,������
//virtual :�ı�ײ������_name ֻ��һ��








int main(){

	test();

	system("pause");
	return 0;
}
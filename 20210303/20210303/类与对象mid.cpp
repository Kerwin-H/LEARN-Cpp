//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//
//class A{
//
//public:
//	int _a; 
//	A(int a = 10){
//		_a = a;
//		cout << "A()" << endl;
//	}
//};
//
////=========���6��Ĭ�ϵĳ�Ա����
//
////=========1.���캯��
////���Ѿ������ĺ������г�ʼ��
//class Date{
//
//public:
//	//���캯����������
//	//�޲�:Ĭ�Ϲ���
//	//�������Զ����ɵ�Ҳ��Ĭ�Ϲ���
//
//	//Date(){
//	//	
//	//	cout << "Date()" << endl;
//	//}
//
//	//====!!!���������������Ĭ�Ϲ���ֻ�ܴ���һ��,���ܶ�γ���
//	//====�޲ι������ȫȱʡ����
//
//	//ȫȱʡ	Ҳ��һ��Ĭ�ϵĹ���
//	Date(int year=1, int month=1, int day=1){
//		
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//
//	Date(int  year, int month, int day, int num){
//		
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int,int)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//�Զ������ͳ�Ա
//	A _a;
//};
//
//void test3(){
//	//�������ڴ�������ʱ,�Զ����ù��캯��
//	//��ɶ������ݵĳ�ʼ��,�����Ǵ�������
//	//�����޲εĹ���
//
//
//	Date d;		//��Ϊ���������������������A����,����
//				//���ǻ����ȷ��ʵ�A����Ӧ����,Ȼ���ٷ��ʵ�Date��Ӧ��Ĭ����
//				//����Զ������û�ж�Ӧ��Ĭ�Ϲ���,ϵͳ�ͻᱨ��!
//
//	//���ô������Ĺ���(�Զ�����)
//	Date d1(1998, 12, 25);
//	Date d2(1999, 06, 28);		//�����б��ж�Ӧ�ĸ���������Ҫһ��,��Ȼ�ͻᱨ���Ҳ���
//
//	//Date d3(2019, 20, 25, 35);//���������Զ����㶨��ĺ������ͺ�
//							 // ��������Ŀ�Զ�������Ҫ���õĺ���
//	//������ʾ���ú���
//	//d.Date(2020, 2, 2);		//����
//
//	//���ǵ����޲εĹ���,��������һ������
//	//������:d4
//	//�����б�: ��
//	//����ֵ:Date
//	Date d4();		//�����޲�����ֱ���� Date d4;����
//
//	
//}
//
////=========2.��������
////�����������ٶ���,��������������Դ������
//class Date{
//
//public:
//
//	Date(int year = 1, int month = 1, int day = 1){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//	void Display()	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//����ʾ���������,���������Զ�����Ĭ�ϵ���������
//	//�������Զ�������Զ����Ա����������,����Զ����Ա������
//	~Date(){}
//private:
//	int _year;
//	int _month;
//	int _day;
//	
//};
//
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//
//		_size = 0;
//		_capacity = capacity;
//	}
//	//�������ٵ�ʱ��,�������Զ���������,�����Դ������
//	~SeqList()
//	{
//		if (_pData) 
//		{
//			free(_pData); // �ͷŶ��ϵĿռ�
//			_pData = NULL; // ��ָ����Ϊ��
//			_capacity = 0;
//			_size = 0;
//			cout << "~SeqList" << endl;
//		}
//	}
//
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//int* p = nullptr;
//void test5(){
//	//Date d(2020, 2, 3);
//
//	//��̬����һ����Ӧ�Ŀռ�,���Դ��10��Ԫ��
//	//����Ӧ���׵�ַ������_pData��
//	SeqList sq(10);		//����ƥ��Ŀռ�û�б�����˳�����,�ǽ��ռ俪���ڶ���,Ȼ����ָ����е���
//
//	cout << sizeof(sq) << endl;
//	
//}
//
//void test6(){
//	
//	Date d(2021, 20, 5);
//}
//
////========3.�������캯��
//class Date{
//
//public:
//	
//	Date(int year = 1, int month = 1, int day = 1){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int)" << endl;
//	}
//	//�������ʾ���忽������,���������Զ����ɿ�������
//	Date(const Date& d){		//�������û�м�ȡ��ַ�ķ��ŵ�ʱ��, ��ֻ��
//								//���޵Ľ��п���������ȥ,��һ���޷������е�ֵ���п���
//		
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		cout << "�����Ŀ���" << endl;		//���������һ������,���Ƿ��ֱ�ӵ��ÿ������������
//	}
//
//	Date(int  year, int month, int day, int num){
//
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int,int,int,int)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void test(){
//	
//	Date date(2020, 02, 20);
//	//������������,����copy����,���ݺ�date��ȫһ��
//	Date copy(date);
//}
////====�������ñ����������Զ���������ʽ����  !ǳ����!
////��ֻ��Ӧ����һЩ�򵥵Ŀ�����ʽ��,���´���������Դ!
////����һЩ����Դ����,���������ʾ����,�����������һ��������free�Ĳ�����,��������
////��ַ����ָ��ͬһ�������,�����Ļ�free�����ͻ�ִ������,��ɴ������,
////���Զ�����������Դ��,���Ǿ�Ҫ������������в���
//
//
//int main(){
//	
//	test();
//
//	system("pause");
//	return 0;
//}

//#pragma pack(1)		//Ĭ�϶���ĳ�1byte
//
//#include<iostream>
//
//using namespace std;
//
//
////========�ṹ���ڴ�������
//struct A{
//	int a;
//	int b;
//	double d;
//	int e;
//
//};
//
//void test1(){
//	
//	cout << sizeof(A) << endl;
//
//	A oa;
//	cout << (char*)&oa.d - (char*)&oa << endl;		//���ĳ����Ա����ڽṹ����ʼλ�õ�ƫ����
//}
//
////========���С���ֽ���
//void test2(){
//
//	int a = 1;
//	char* pa = (char*)&a;
//
//	if (*pa)
//		cout << "small"<< endl;
//	else
//		cout << "big" << endl;
//}
////========this ָ��
//
//class D{
//
//	int a;
//};
//class Date
//{
//public:
//	//ÿһ���Ǿ�̬��Ա������,������һ��this ָ��
//	//��Ϊ�����ĵ�һ���β�
//	//this ָ��ָ����ô˺����Ķ���
//	//this ����: ������*  const this
//	//ֻ�����ڳ�Ա������,�������޷����з���
//	//һ�����ڼĴ���
//	void Display()	//void Display (this)		�����this ָ���ڳ�Ա��������һ���β�,ʹ��֮����������
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		
//		D d;
//		//this = &d;	//��Ϊ�����thisָ����һ��const ���͵�����,����ָ���������޷��ı��
//	}
//
//	void SetDate(int year, int month, int day)  //void SetDate( this ,int year, int month, int day)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//
//
//void test()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display();
//	d2.Display();
//
//	//�����޷����з���
//	//cout << this << endl;
//}
////====��ָ���޷����н����õĲ���
////====thisָ����û�н��н����õ������¿��Խ��н�����
//
//
//int main(){
//
//	test1();
//
//	system("pause");
//	return 0;
//}
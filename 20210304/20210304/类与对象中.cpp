#include<iostream>
using namespace std;


//========7.const ��Ա


//class A{
//
//public:
//	int setI(int i){
//		
//		_i = i;
//		//==��const��Ա������,���Ե���const��Ա����
//		getI();		//����ʵ��  const *=*
//	}
//	//==const����thisָ��:thisָ��ָ��Ķ������ݲ��ܱ�
//	int getI()const{		//const this :const A* const
//		
//		//_i = 100;
//		//this->_i = 100;
//		//setI(10);		���Ͳ�ƥ��
//		return _i;
//	}
//
//private:
//	int _i;
//};
//
////==�����Ƿǳ�Ա����,�������const ���͵ĺ���
//void fun(int a)//const
//{
//
//	a = 100;
//}
//void test1(){
//
//	A a;
//	//ԭ��:Ȩ�޹�����(��д)--->Ȩ�޲��ܷŴ�,���ǿ�����С
//	//��const������Ե���const��Ա����:����
//	a.setI(10);
//	a.getI();
//
//	const A b; 
//	
//	//const������Ե��÷�const��Ա����:����
//	
//	//b.setI(10); 
//	b.getI();
//
//}

//========8.ȡ��ַ��constȡ��ַ����������
class A{

public:
	int setI(int i){

		_i = i;
	}
	int getI()const{		

		return _i;
	}
	//==this: A* const
	A* operator&(){
		
		return this;
	}
	//==this: const A* const
	A* operator&()const{	//��ʾ�ڲ���ָ����һ��constָ��
		
		//return this;	����
	}

private:
	int _i;
};


void test(){

	A obja;
	A* pa = &obja;
	pa->setI(10);

	const A objb;
	const A* pb = &objb;
}



int main(){

	test();

	system("pause");
	return 0;
}
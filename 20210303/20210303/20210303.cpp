#pragma pack(1)		//Ĭ�϶���ĳ�1byte

#include<iostream>

using namespace std;


//========�ṹ���ڴ�������
struct A{
	int a;
	int b;
	double d;
	int e;

};

//void test(){
//	
//	cout << sizeof(A) << endl;
//
//	A oa;
//	cout << (char*)&oa.d - (char*)&oa << endl;		//���ĳ����Ա����ڽṹ����ʼλ�õ�ƫ����
//}

//========���С���ֽ���
void test(){

	int a = 1;
	char* pa = (char*)&a;

	if (*pa)
		cout << "small"<< endl;
	else
		cout << "big" << endl;
}



int main(){

	test();

	system("pause");
	return 0;
}
#pragma pack(1)		//默认对齐改成1byte

#include<iostream>

using namespace std;


//========结构体内存对齐规则
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
//	cout << (char*)&oa.d - (char*)&oa << endl;		//求出某个成员相对于结构体起始位置的偏移量
//}

//========大端小端字节序
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
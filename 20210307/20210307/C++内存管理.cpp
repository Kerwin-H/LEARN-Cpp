#include<iostream>
using namespace std;

//========1.C/C++�ڴ�ֲ�
int globalVar = 1;										
static int staticGlobalVar = 1;							
void test()					
{
	static int staticVar = 1;							
	int localVar = 1;									

	int num1[10] = { 1, 2, 3, 4 };						
	char char2[] = "abcd";								
	char* pChar3 = "abcd";								
	int* ptr1 = (int*)malloc(sizeof (int)* 4);		
	int* ptr2 = (int*)calloc(4, sizeof(int));			
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);	
	free(ptr1);		
	free(ptr3);
}

//========2. C�����ж�̬�ڴ����ʽ

//====1)malloc/calloc/realloc��free����
void test(){


	//char* ptr = (char*)malloc(0xffffffff);
	//char* ptr = (char*)malloc(0x7fffffff);
	char* ptr = (char*)malloc(sizeof(char));
	//�����ռ�Ĵ�С,����
	char* ptr1 = (char*)realloc(ptr, 2 * sizeof(char));
	//�����µĿռ�
	char* ptr2 = (char*)realloc(NULL, sizeof(char));

	char* ptr3 = (char*)realloc(ptr2, sizeof(char)* 100);
	//��Ϊ��pte3�Ĳ�����������2,����2�Ͳ��ý����ͷ�,������ͷ�
	//ptrָ��Ŀռ䲻����ʾ�ͷ�
	//ֻ����ʽ�ͷ�realloc����֮��Ŀռ�,����realloc�е�ָ��ռ䲻����ʾ�ͷ�


	//free(ptr);

	free(ptr1);
	//free(ptr2);
	free(ptr3);


	//����ռ�+�ռ�ȫ����ʼ��Ϊ0
	char* ptr7 = (char*)calloc(4, sizeof(char));
}

int main(){
	
	test();

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

//========1.C/C++内存分布
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

//========2. C语言中动态内存管理方式

//====1)malloc/calloc/realloc和free操作
void test(){


	//char* ptr = (char*)malloc(0xffffffff);
	//char* ptr = (char*)malloc(0x7fffffff);
	char* ptr = (char*)malloc(sizeof(char));
	//调整空间的大小,扩容
	char* ptr1 = (char*)realloc(ptr, 2 * sizeof(char));
	//申请新的空间
	char* ptr2 = (char*)realloc(NULL, sizeof(char));

	char* ptr3 = (char*)realloc(ptr2, sizeof(char)* 100);
	//因为在pte3的操作中利用了2,所以2就不用进行释放,会帮助释放
	//ptr指向的空间不能显示释放
	//只能显式释放realloc返回之后的空间,传入realloc中的指针空间不能显示释放


	//free(ptr);

	free(ptr1);
	//free(ptr2);
	free(ptr3);


	//申请空间+空间全部初始化为0
	char* ptr7 = (char*)calloc(4, sizeof(char));
}

int main(){
	
	test();

	system("pause");
	return 0;
}
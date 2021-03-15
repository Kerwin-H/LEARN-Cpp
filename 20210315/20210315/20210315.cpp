#include<iostream>

using namespace std;

//========3.C++ �ڴ����ʽ
//====3.1 new/delete������������
//void test(){
//	//����ʹ��new����Ŀռ�,ֱ����delete�����ͷ�
//	//����malloc����Ŀռ�ֱ��ʹ��free
//	//��Ӧ�ͷ�,һ��
//
//	int* mptr = (int*)malloc(sizeof(int));
//	
//	free(mptr);
//
//	int* ptr = new int;//ֱ������
//	delete ptr;
//	int* ptr2 = new int(10); //����+��ʼ��
//	delete ptr2;
//	//����
//	int* arr = new int[10];//���������Ŀռ�
//	 
//	delete[] arr;//����ʹ��delete���������Ŀռ��ͷ�,ֱ�������
//
//}
//====3.2�Զ������� 
//class A{
//public:
//
//	A(){
//		cout << "A()" << endl;
//	}
//	~A(){
//		
//		cout << "~A()" << endl;
//	}
//private:
//
//	int _a = 10;
//};
//
//void test(){
//
//	A* mpa = (A*)malloc(sizeof(A));	//1.ֻ��������ռ�
//
//	free(mpa);
//	cout << "------------" << endl;
//
//
//	//�Զ�������: new: ����ռ�+���ù��캯�����пռ����ݵĳ�ʼ��
//	//��Ҫ����Ĭ�Ϲ���,(�޲�)
//	A* pal = new A;	//1.������ռ�=2.���ù��캯�����г�ʼ��
//
//
//	A* pal2 = new A;
//	//���ȵ����������������Դ������,+�ٽ��пռ���ͷ�
//	//1.�ȶ���˳�������ָ����Դ�����ͷ�
//	//2.�ٶ���˳���������ͷ�
//	delete pal;	
//	delete pal2;
//
//	//����ʹ�ô��ι���Զ��������пռ�����ͳ�ʼ��
//	//������Ĭ�Ϲ���
//	A* arrA = new A[6];
//	delete[] arrA;		//����ĵ��ú����Ǹ�������Ĵ�С���е��ù��캯��
//}

//=====4.operator new/operator delete����
//C++�е�ȫ�ֺ���

//void test(){
//	
//	//operator new ����new����������غ���
//	//void* operator new(size_t n);
//	//ȫд
//	//void* ptr = operator new(sizeof(int));
//	////��д
//	//void* ptr2 = new sizeof(int);
//
//	//operator delete����delete����������غ���
//	//void operator delete(void* ptr); 
//	/*void* ptr = nullptr;
//	operator delete(ptr);
//	delete ptr;*/
//
//	//==========================
//	//ʹ�÷���:������malloc ��free
//	//operator new: malloc +�쳣
//
//	//int* ptr = (int*)operator new (0x7fffffffffff);//����ռ�ʧ��,�׳��쳣���ؿ�ֵ
//
//	int* ptr2 = (int*)malloc(0x7fffffff);//�����malloc��᷵��ָ���ֵ,�����׳��쳣
//
//	//��װ��free,��Ӧoperator new��ִ��
//	//operator delete(ptr);
//	free(ptr2);
//}
//=========================
//class A{
//
//public:
//	A(int a = 10)
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//void test(){
//
//	//�൱��һ����ķ�װ,��malloc��free�е����ݷ�װ��������ط�����ʹ��
//
//	//new: operator new-->malloc
//	int* ptr = new int;
//	//delete: operator delete-->free +�׳��쳣
//	delete ptr;
//	//new[]: operator new[]-->operator-->malloc
//	int* ptr2 = new int[];
//	//delete[]: operator delete[]-->operator delete-->free
//	delete []ptr2;
//
//
//	//�Զ�������
//	//new: operator new-->malloc-->����
//	A* pa = new A;
//	//delete: ���� -->operator delete-->free
//	delete pa;
//
//	//����--�ڿռ�����õ�ʱ��,ֱ��ִ��N�ι���
//	A* pa2 = new A[10];
//	//delete []: ��ִ��һ��N�ε�����
//	delete[]pa2;
//
//
//}


//====�ڴ��!!!
//struct ListNode{
//public:
//
//	//������ڲ����ж����ʱ��,������˶�Ӧ�ķ���ֵ,�����ȷ��Ϊ�ⲿ����
//	void* operator new(size_t n){
//		
//		cout << "operator new" << endl;
//		//�����ڴ�صķ�ʽ
//		cout << "memory poll" << endl;
//		allocator<ListNode>alloc;
//		return alloc.allocate(1);		//һ��Ԫ�صĴ�С
//	
//	}
//
//	void operator delete(void* ptr){
//		
//		cout << "operator delete" << endl;
//		allocator<ListNode>alloc;
//		alloc.deallocate((ListNode*)ptr, 1);
//		cout << "memory pool deallocate" << endl;
//
//	}
//
//	ListNode(int data = 1)	//�ռ�ĳ�ʼ��
//		:_data(data)
//	{
//		
//		cout << "ListNode(int)" << endl;
//	}
//
//	~ListNode(){
//		
//		cout << "~ListNode()" << endl;
//	}
//private:
//	int _data=0;
//	ListNode* _next = nullptr;
//	
//};
//
//class A{
//
//
//};
//void test(){
//
//	//1.���ȵ��������������ڲ�����Դ����һ������
//	//2.�ڵ��ó�ʼ��
//	ListNode* node = new ListNode;
//
//	delete node;
//
//	A* pa = new A;
//	delete pa;
//
//}

//========6.3 new ������ʽ
//���ѷ����ԭʼ�ڴ�ռ����һ����ʼ��,һ������ڴ�ؽ���ʹ��
//class A{
//
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//	~A(){
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void test(){
//
//	A* pa = (A*)malloc(sizeof(A));
//	//��ʼ�����еĿռ�
//	
//	//new��λ���ʽ: new(ָ��)����(�����б�)
//	new (pa)A(10);
//	pa->~A();	//���ͷ�ǰ���ڲ�����Դȫ�������,Ȼ���ٽ��пռ���ͷ�,��Ȼ���׻���Դй¶
//	
//	free(pa);
//
//}


//====
void test(){

	
	//char* p = new char[0xffffff];

	//char* p = (char*)malloc(0xffffffff);

}


int main(){
	
	test();

	system("pause");
	return 0;
}
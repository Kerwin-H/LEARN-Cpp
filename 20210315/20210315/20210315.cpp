//#include<iostream>
//
//using namespace std;
//
////========3.C++ �ڴ����ʽ
////====3.1 new/delete������������
////void test(){
////	//����ʹ��new����Ŀռ�,ֱ����delete�����ͷ�
////	//����malloc����Ŀռ�ֱ��ʹ��free
////	//��Ӧ�ͷ�,һ��
////
////	int* mptr = (int*)malloc(sizeof(int));
////	
////	free(mptr);
////
////	int* ptr = new int;//ֱ������
////	delete ptr;
////	int* ptr2 = new int(10); //����+��ʼ��
////	delete ptr2;
////	//����
////	int* arr = new int[10];//���������Ŀռ�
////	 
////	delete[] arr;//����ʹ��delete���������Ŀռ��ͷ�,ֱ�������
////
////}
////====3.2�Զ������� 
////class a{
////public:
////
////	a(){
////		cout << "a()" << endl;
////	}
////	~a(){
////		
////		cout << "~a()" << endl;
////	}
////private:
////
////	int _a = 10;
////};
////
////void test(){
////
////	a* mpa = (a*)malloc(sizeof(a));	//1.ֻ��������ռ�
////
////	free(mpa);
////	cout << "------------" << endl;
////
////
////	//�Զ�������: new: ����ռ�+���ù��캯�����пռ����ݵĳ�ʼ��
////	//��Ҫ����Ĭ�Ϲ���,(�޲�)
////	a* pal = new a;	//1.������ռ�=2.���ù��캯�����г�ʼ��
////
////
////	a* pal2 = new a;
////	//���ȵ����������������Դ������,+�ٽ��пռ���ͷ�
////	//1.�ȶ���˳�������ָ����Դ�����ͷ�
////	//2.�ٶ���˳���������ͷ�
////	delete pal;	
////	delete pal2;
////
////	//����ʹ�ô��ι���Զ��������пռ�����ͳ�ʼ��
////	//������Ĭ�Ϲ���
////	a* arra = new a[6];
////	delete[] arra;		//����ĵ��ú����Ǹ�������Ĵ�С���е��ù��캯��
////}
//
////=====4.operator new/operator delete����
////c++�е�ȫ�ֺ���
//
////void test(){
////	
////	//operator new ����new����������غ���
////	void* operator new(size_t n);
////	//ȫд
////	void* ptr = operator new(sizeof(int));
////	////��д
////	void* ptr2 = new sizeof(int);
////
////	//operator delete����delete����������غ���
////	void operator delete(void* ptr); 
////	void* ptr = nullptr;
////	operator delete(ptr);
////	delete ptr;
////
////	//==========================
////	//ʹ�÷���:������malloc ��free
////	//operator new: malloc +�쳣
////
////	int* ptr = (int*)operator new (0x7fffffffffff);
////
////	int* ptr2 = (int*)malloc(0x7fffffff);
////
////
////	operator delete(ptr);
////	free(ptr2);
////}
////////=========================
////class a{
////
////public:
////	a(int a = 10)
////		:_a(a)
////	{}
////
////private:
////	int _a;
////};
////
////void test(){
////
////	//�൱��һ����ķ�װ,��malloc��free�е����ݷ�װ��������ط�����ʹ��
////
////	//new: operator new-->malloc
////	int* ptr = new int;
////	//delete: operator delete-->free +�׳��쳣
////	delete ptr;
////	//new[]: operator new[]-->operator-->malloc
////	int* ptr2 = new int[];
////	//delete[]: operator delete[]-->operator delete-->free
////	delete []ptr2;
////
////
////	//�Զ�������
////	//new: operator new-->malloc-->����
////	a* pa = new a;
////	//delete: ���� -->operator delete-->free
////	delete pa;
////
////	//����--�ڿռ�����õ�ʱ��,ֱ��ִ��n�ι���
////	a* pa2 = new a[10];
////	//delete []: ��ִ��һ��n�ε�����
////	delete[]pa2;
////
////
////}
////
////
////====�ڴ��!!!
////struct listnode{
////public:
////
////	//������ڲ����ж����ʱ��,������˶�Ӧ�ķ���ֵ,�����ȷ��Ϊ�ⲿ����
////	void* operator new(size_t n){
////		
////		cout << "operator new" << endl;
////		//�����ڴ�صķ�ʽ
////		cout << "memory pool" << endl;
////		allocator<listnode>alloc;
////		return alloc.allocate(1);		//һ��Ԫ�صĴ�С
////	
////	}
////
////	void operator delete(void* ptr){
////		
////		cout << "operator delete" << endl;
////		allocator<listnode>alloc;
////		alloc.deallocate((listnode*)ptr, 1);
////		cout << "memory pool deallocate" << endl;
////
////	}
////
////	listnode(int data = 1)	//�ռ�ĳ�ʼ��
////		:_data(data)
////	{
////		
////		cout << "listnode(int)" << endl;
////	}
////
////	~listnode(){
////		
////		cout << "~listnode()" << endl;
////	}
////private:
////	int _data=0;
////	listnode* _next = nullptr;
////	
////};
////
////
////void test(){
////
////
////	listnode* node = new listnode;
////
////	cout << "----------" << endl;
////
////	delete node;
////
////}
//
////========6.3 new ������ʽ
////���ѷ����ԭʼ�ڴ�ռ����һ����ʼ��,һ������ڴ�ؽ���ʹ��
//class a{
//
//public:
//	a(int a)
//		:_a(a)
//	{
//		cout << "a(int)" << endl;
//	}
//	~a(){
//		cout << "~a()" << endl;
//	}
//private:
//	int _a;
//};
//void test(){
//
//	a* pa = (a*)malloc(sizeof(a));
//	//��ʼ�����еĿռ�
//	
//	//new��λ���ʽ: new(ָ��)����(�����б�)
//	new (pa)a(10);
//
//	pa->~a();	//���ͷ�ǰ���ڲ�����Դȫ�������,Ȼ���ٽ��пռ���ͷ�,��Ȼ���׻���Դй¶
//	
//	free(pa);
//
//}
//
//
////====
////void test(){
////
////	
////	char* p = new char[0xffffff];
////
////	char* p = (char*)malloc(0xffffffff);
////
////}
//
//
//
//int main(){
//
//	test();
//
//	system("pause");
//	return 0;
//}
//
//
//

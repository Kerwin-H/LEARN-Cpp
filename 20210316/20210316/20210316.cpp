#include<iostream>
using namespace std;


struct listnode{
public:

	
	void* operator new(size_t n){

		cout << "operator new" << endl;
		//采用内存池的方式
		cout << "memory pool" << endl;
		allocator<listnode>alloc;
		return alloc.allocate(1);		

	}

	void operator delete(void* ptr){

		cout << "operator delete" << endl;
		allocator<listnode>alloc;
		alloc.deallocate((listnode*)ptr, 1);
		cout << "memory pool deallocate" << endl;

	}

	listnode(int data = 1)	
		:_data(data)
	{

		cout << "listnode(int)" << endl;
	}

	~listnode(){

		cout << "~listnode()" << endl;
	}
private:
	int _data = 0;
	listnode* _next = nullptr;

};

void test(){

	listnode* node = new listnode;		

	cout << "----------" << endl;		

	delete node;		
}

//=====================================================================
class a{

public:
	a(int a)
		:_a(a)
	{
		cout << "a(int)" << endl;
	}
	~a(){
		cout << "~a()" << endl;
	}
private:
	int _a;
};

void test(){

	a* pa = (a*)malloc(sizeof(a));
	

	
	new (pa)a(10);

	pa->~a();	

	free(pa);

}



int main(){
	
	test();

	system("pause");
	return 0;
}
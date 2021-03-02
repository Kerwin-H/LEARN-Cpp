#include<iostream>

using namespace std;

//========��������(�����ں�)
//inline + ����
//���ڱȽϼ򵥵ĺ���,��ֱ�ӽ���չ��,������к����ĵ���
//���Ƕ����������˵�Ƚϸ��ӵĺ���,�Ͳ�һ���������õ�
inline int add(int a, int b){
	return a + b;
}

inline int fun1(int n){
	
	for (int i = 1; i < n; ++i)
		n += i*n / (i + 1)*n;
	return n;
}

void test2(){
	
	int a = add(10, 20);	//ʵ�ʱ���ʱ: int a=10+20
	
	int n = 10000;
	n = fun1(n);

}

//========auto�ؼ���
void test1(){
	
	//auto: �Զ������Ƶ�(�Զ�ʶ�����������ݵ�����)
	//�൱��һ�����͵ĵ��÷�
	auto a = 10;
	auto b = 2.0;
	auto c = 'a';
	auto d = 'a' + b;
	//����ָ��:������,��Ϊ����Դ��ұߵ�&���ſ�����
	auto pa = &a;		//ָ��
	auto* pb = &a;

	//��������:�����&
	auto& rc = b;
	auto f = b;


	int j, k, l;
	//auto a = 10, b = 60, c = 'a';	//����,ͬһ�б�����ͬһ������


	cout << typeid(a).name() << endl;		//��ʾ������
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;


	cout << typeid(pa).name() << endl;
	cout << typeid(rc).name() << endl;
	cout << typeid(f).name() << endl;

}

//========���ڷ�Χ��forѭ��
//��Χfor
void test3(){
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		
		cout << arr[i] << " ";
	}
	cout << endl;


	//��Χfor:   ��ǰ������ : ѭ���ķ�Χ
	//ֻ��ѭ�������������˱仯,�����Ķ���һ����
	for (const int& e : arr){		//������������const ��ֵ���ᱻ�޸�,����ĸ�ֵҲû�а취
		cout << e << " ";
		//e = 10;
	}
	cout << endl;

	for (int e : arr){
		cout << e << " ";
	}
	cout << endl;


	for (const auto& e : arr){
		cout << e << " ";
	}
}

//��������Ϊ������ʱ��,���������˻���ָ��,��Χ�޷�ȷ��,��---����ʹ�÷�Χfor
//void fun(int arr[], int n){
//	
//	for (const auto& e : arr){
//		cout << e << " ";
//	}
//	cout << endl;
//}

//========ָ���ֵ
void fun(int a){
	cout << "fun(int)" << endl;
}
void fun(int* a){
	cout << "fun(int*)" << endl;
}

void test(){

	int* p = NULL;	//��Ԥ�����ʱ��,���滻: int* p=0;
	int* p2 = 0;

	fun(NULL);		//��Ϊ�յ�ʱ��,�����������޽�NULLת��������,������ָ������
	

	fun((int*)NULL);//==
	fun(nullptr);	//����ʹ������������ʽ
	
	cout << typeid(nullptr).name() << endl;
}

int main(){

	test();

	system("pause");
	return 0;
}
#include<stdio.h>
//c++�� .h
#include<iostream>


//========I.�����ռ�Ķ���
//========(1)��ͨ����

//namespace + �����ռ����� (����,����)
namespace N1{		
	
	int a=0;
	void fun1(){
		printf("N1:fun1()\n");
	}

//========(2)Ƕ�׶���
	//��Ƕ��
	namespace N2{
		
		int a=1;
		void fun1(){
			
			printf("N1:N2:fun1()\n");
		}
	}
}
//========(3)�ֶζ���

//�ֶζ���,�ɽ�N1��������,ֻ�����ڲ������������ӵ�
//������Ϊ�ֿ�����͸��Ǹ���
namespace N1{
	
	//int a;	//�ض���
	int b=66;
	void fun2(){
		
		printf("N1:fun2()\n");
	}
}

//��Ȼ������ͬ,����������ͬ,�ʿ��Թ���
int a = 10;

void fun1(){
	
	printf("fun1()\n");
}

void test1(){
	//ȫ��:a
	printf("a:  %d\n",a);
	//�����ռ��г�Ա�ķ�����ʽ:
	//1.�����ռ�+ :: +��Ա
	printf("N1::a:  %d\n",N1::a);
	//2.using �����ռ�::��Ա

	using N1::b;		//��Ҫ�����֮ǰ,��Ȼ����Ҫ��ȫ����
	
	printf("N1::b: %d\n",b);
	//3.չ����Ա�ռ�:  using namespace  �����ռ�
	//���ȫ����������,��ᷢ������
	using namespace N1;
	//printf("n1::a:  %d\n",a);		//��ȷ��,���ڶ��
	fun2();

	//========�Ƽ�1 2
}
//========II.�������
//========cpp�е����������Ϊ���
using namespace std;
void test2(){
	
	//C++�е�ͷ�ļ���������г�Ա������std�����ռ�
	
	//std::cin >> a;		//����
	//std::cout << a;		//���
	//========��������std�����ǰ��ĸ�ʽ,���Ǿ���Ҫ��std�������ռ����չ��
	//�ڴ���֮ǰ  using namespace std;

	//========֧���������������,Ҳ���ñ�ʾ����ȷ������
	//���˳��: ��������
	//����˳��: ��������

	//cin >> a>>a>>a;
	//cout << a<<"123"<<"\n";
	
	int b, c, d, e;
	cin >> a >> b >> c >> d>>e;
	cout << a << b << c << d << e << "\n";

	cout << endl;	//��ʾ����

}
//========III.ȱʡ����
void fun3(int a){
	cout << a << endl;
}

//ȫȱʡ: ���еĲ���������Ĭ��ֵ
//��ȱʡ: ���ִ���Ĭ��ֵ==========(���������������,��������)

void fun4(int a = 10){		//====�ڶ��庯����ʱ��,��һ������ֵ,���û�д�ֵ,��ʹ�ñ���ֵ,���ᱨ��
	cout << a << endl;		//�����ֵ���ñ���ֵ
}

void fun5(int a = 10, int b = 20, int c = 30, int d = 40){
	cout << a << b << c << d << endl;
}
void test3(){
	
	//fun3(1);
	fun3(100);
	fun4();
	fun4(50);

	fun5(3,6,9);
}

//��������
void fun7(int a = 10);
//��������
void fun7(int a){
	cout << a << endl;
}

//========IIII.��������
//����������������,������Ҫ����һ���Ĳ���
//C �ᱨ���ض���
char add(char a, char b){
	return a + b;
}
int add(int a, int b){
	return a + b;
}
double add(double a, double b){
	return a + b;
}

void fun8(char a, int b){
	cout << "fun7(char,int)" << endl;
}
//����˳��ͬ
void fun8(int b, char a){
	cout << "fun7(int,char)" << endl;
}
//����������ͬ
void fun8(char a,int b,char c){
	cout << "fun7(char,int,char)" << endl;
}
//����ͨ������ֵ���͵Ĳ�ͬ�����ֺ�������


int main(){
	
	//test1();
	//test2();
	test3();
	fun7();
	int a = 1;
	char b = 'a';

	fun8(a,b);
	fun8(b,a);
	fun8(b,a,b);




	system("pause");
	return 0;
}
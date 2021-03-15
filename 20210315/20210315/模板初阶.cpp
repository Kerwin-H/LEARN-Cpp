#include<iostream>

using namespace std;

//========1.���ͱ��(ģ����)
//���������Ч��

//$====1.����ģ��
//���ȶ����������ģ��,ʵ����ִ�е�ʱ���ڲ����������,�γ���Ҫ�ĺ���
//�����T����һ��ģ�����
template<typename T>

void Swap(T& a, T& b){
	
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>	//!!�����ﲻ������struct 
T add(T a, T b){
	
	return a + b;
}

template<class T1,class T2,class T3>
void print(const T1& a, const T2& b, const T3&c){
	
	cout << a <<"-"<< b <<"-"<< c << endl;
}
//Ϊ����ģ��ʵ��������ͨ����
void print(const int& a, const int& b, const double& c){

	cout << a << "-" << b << "-" << c << endl;
}

void test(){
	
	int a = 1, b = 2;
	char d = 'm', e = 'n';
	double f = 1.3;
	double g = 5.94;
	
	//�����ִ�еĲ��ǵ��õ�ͬһ������,����template�ڲ����Զ������µĳ��������е���
	//��������:
	//��ʽʵ����(һ��)
	Swap(a, b);
	Swap(d, e);
	Swap(f, g);

	//��ʽʵ����
	add(a, b);

	add<int>(a, e);	//��ִ��ae��ʱ��,���ڴ���������ͬ�Ĳ�������,���Ǿ�Ҫ�������е����ͽ�������,����ʵ��
					//���ֽ��������Ĺ��̾ͽ�����ʾʵ����

	//ǿ������
	add(a, (int)e);

	print(a, b, d);
	print(b, f, a);

	//ƥ�����:
	//1.����ƥ����ͨ����
	//2.�������ģ�����ʵ����һ������ƥ��ĺ���,��ʵ����
	//3.���ָ����Ҫ����ʵ����,��ֱ��ʵ����
	print(a, b, f);

	print<int,int,double>(a, b, f);
}

//$====2.��ģ��
template <class T>
class seqList{
public:
	seqList(int n)
		:_data(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	T seqListAt(size_t pos);

private:
	//int* _data;
	T* _data;
	size_t _size;
	size_t _capacity;
};
//==�����������к����Ķ���,ҲҪ�ӷ��͵�����
template <class T>
T seqList::seqListAt(size_t pos){
	
	return _data[pos];
}


void test(){

	//����д��,���ܽ���ʵ����
	//seqList sq;
	//��ģ��ʵ����֮��,����������-->����<ģ���������>
	//ֻ������ʽʵ����
	seqList<int>sq(10);

	seqList<double>sq2(10);
}

int main(){
	
	//test();

	system("pause");
	return 0;
}
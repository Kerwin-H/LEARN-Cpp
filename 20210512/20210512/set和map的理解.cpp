#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;


//��list vector ��Щ��������ʽ����  �ײ�Ϊ����˳������ݽṹ
//=====1.����ʽ���������: �ײ�洢��<key,value> �ļ�ֵ��,���ݼ�����Ч�ʸ���


//=====2.��ֵ��
//���ڲ���ʵ���ǽ�������Դ����,�������е�һ���Ϳ��Ի�ȡ������һ��������
template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair() : first(T1()), second(T2())
	{}

	pair(const T1& a, const T2& b) : first(a), second(b)
	{}
};

//==========3.���ͽṹ�Ĺ���������
//set//map//multimap//multiset����

//=====3.1  set

//��������
void test1(){
		
	//��������
	int arr[] = { 1, 1, 2, 3, 4, 4, 5, 5, 6 };
	set<int>s(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//��Χfor��ӡ,�鿴Ԫ���Ƿ��ظ�
	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	///���������ô�ӡ
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	
	
	set<char>s2(s.begin(), s.end());	//��set1�е����ݽ��д���

	//����operator=��ʵ�����ݵĽ���,���ҽ�֮ǰ�����ÿ�
	set<int> s3;
	s3 = s;
	s = set<int>();
}
//Capacity
void test2(){
	
	set<int>s;
	s.empty();		//�пղ���

	cout << "size:" << s.size() << endl;		//size()ʹ��
	s.insert(100);
	cout << "size:" << s.size() << endl;
	s.insert(10);
	cout << "size:" << s.size() << endl;


	cout << "size:" << s.max_size() << endl;

	if (s.max_size() > 1000){
		
		for (int i = 0; i < 1000; i++){
			
			s.insert(i);
		}
	}
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
}
//Modifiers
void test3(){
	
	set<int>s;

	s.insert(5);		//����
	s.insert(10);
	s.insert(15);

	s.erase(5);		//ɾ��
	s.erase(1);


	set<int>s2;
	s2.insert(666);

	s.swap(s2);		//����

	s.clear();		//���

	s.emplace(66);
	s.emplace(666);		//�����ڲ���
	s.emplace(6666);
	s.emplace(6);
}

//Observers
void test4(){
	

}


//Operations
void test5(){

	std::set<int>::iterator it;
	set<int>s;

	s.insert(6);
	s.insert(2);
	s.insert(8);

	it=s.find(8);		//find

	for (it = s.begin(); it != s.end(); ++it){
		
		cout << *it << " ";
	}
	cout << endl;

	for (auto & e : s)
		cout << e << endl;


	cout << s.count(2) << endl;		//count  0/1��ӡ,��Ϊֻ���ڵ�һ������
	cout << s.count(4) << endl;



	set<int>sa;
	set<int>::iterator itlow, itup;
	
	for (int i = 1; i < 10; ++i)
		sa.insert(i);

	itlow = sa.lower_bound(2);		//�������˵�����������,����ɾ����Ӧ��Ԫ��(����2��5)
	itup = sa.upper_bound(5);

	sa.erase(itlow, itup);
	for (auto &e : sa)
		cout << e << " ";

	s.equal_range(6);		//����??????

}

//multiset
void test(){
	
	int arr[] = { 1, 2, 3, 4, 4, 5, 5, 5, 7, 2 };		//���ݿ��ظ�
	multiset<int> m1(arr, arr + sizeof(arr) / sizeof(arr[0]));

	for (auto& e : m1)
		cout << e << " ";
	cout << endl;
}






int main(){

	test();

	system("pause");
	return 0;
}
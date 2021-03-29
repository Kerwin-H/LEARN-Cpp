#include<iostream>
#include<vector>
#include<string>
using namespace std;


//========1.�򵥵Ĺ���һ��vector 
void test1(){
	

	struct A{

		A(int a = 1, int b = 2)
		:_a(a)
		, _b(b)
		{}
		int _a = 1;
		int _b = 2;
	};
	//==������һ���յ�vector
	vector<int>v1;
	vector<char>v2;
	vector<A>v3;

	//==��������:ȱʡֵΪ��0ֵ(���ǲ�ͬ���͵�0����˼)
	//�������5�ǿ�������ֽڵĿռ�,���ҳ�ʼֵ��Ϊ ��0
	vector<int>v4(5);
	vector<char>v5(5);
	vector<int*>v6(5);
	vector<float>v7(5);

	//�Զ�������: ȱʡֵΪĬ�Ϲ��캯��
	vector<A>v8(5);	//�����ڿ���5��һ����A,���е�ֵΪA�����ȱʡֵ


	vector<A>v9(5, A(10)); //�����Ǵ����Զ����vector����������и�ֵ,���ֻ��һ��ֵ��ֻ��ǰ��Ľ��и�ֵ



	//���鷽ʽ
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int>v10(arr, arr + sizeof(arr) / sizeof(arr[0]));	//���ڲ��ĳ�ֵת���������ڲ�������

	char arr2[] = { 1, 2, 3, 4, 5 };
	vector<char>v11(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));	//ת����char���͵�12345

	//��������ʽ
	string str("1234567890");
	vector<char>v12(str.begin(), str.end());
}


//========2.���ڲ������ݽ������
void test2(){
	
	string str("1234567890");
	vector<char>v(str.begin(), str.end());

	for (auto& ch : v){		//���÷�Χfor���ڲ������ݽ������
		
		cout << ch;
		//ch = 'a';		//���ڲ���ֵ���иı�
	}
	for (const auto& ch : v){	//����ı���ֵ
		
		cout << ch;
	}
	cout << endl;

	//������
	vector<char>::iterator it = v.begin();
	//�������const�Ĳ��ܶ�����н�����,��Ϊ�ڲ���ֵ�Ѿ������ͷŵ�
	//vector<char>::const_iterator it = v.cbegin();
	int idx = 0;

	while (it != v.cend()){
		
		cout << *it << " ";
		*it = 'a'+idx;
		++idx;
		++it;
	}
	cout << endl;

	vector<char>::reverse_iterator rit = v.rbegin();
	//vector<char>::const_reverse_iterator rit = v.cbegin();

	while (rit != v.rend()){
		
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

//========3.capacity
struct A{

	A(int a = 1, int b = 2)
	:_a(a)
	, _b(b)
	{}
	int _a = 1;
	int _b = 2;
};
void test3(){

	vector<char>v1;
	vector<int>v2;
	vector<int*>v3;
	vector<double>v4;
	vector<A>v5;

	//��ʾ�����洢��
	cout << v1.max_size() << endl;
	cout << v2.max_size() << endl;
	cout << v3.max_size() << endl;
	cout << v4.max_size() << endl;
	cout << v5.max_size() << endl;

	cout << v1.size() << endl;	//�鿴��Ӧ���ֽ�
	cout << v1.capacity() << endl;	//�������

	v1.resize(10);
	v2.resize(2);
	v3.resize(4);
	v4.resize(6);
	v5.resize(3);


	v5.reserve(6);
	v1.reserve(5);		//�ڴ�����ֻ�ܸĴ�,���ܱ�С!!!
	v2.reserve(10);

	v5.shrink_to_fit();	 //����ڶ�Ӧ�Ŀռ��ڲ��ж���Ŀ��в���,���������ӿ����ֱ��ɾ��

}


//========4.��ӦԪ�صķ���
void test4(){
	
	string str = "1234567890";
	vector<char>v(str.begin(), str.end());

	for (size_t i = 0; i < str.size(); ++i){
		
		cout << v.operator[](i) << " ";		//��һ��ȫ��ʽ��ӡ

		v.operator[](i) = i + 'a';		//�ı�ֵ

		cout << v[i] << " ";		//���δ�ӡ

		v[i] = i + 'q';		//��ֵ

	}

	cout << endl;
	for (size_t i = 0; i < str.size(); ++i){

		cout << v[i] << " ";	//�鿴�ڶ��δ�ӡ������
		
	}

	//v[100] = 'a';
	//v.at(100) = 'a';

	//char* ptr = v.data();
}

//========5.���ܺ���
void test5(){
	
	//assign�о�size��С�����׸ı�

	string s("1234");
	vector<char>v(s.begin(), s.end());
	v.assign(10, 'a');		//1.�ı�vector�ڲ���ֵ��size�Ĵ�С/���ܱȽ϶�

	string s2("abcdef");
	v.assign(s2.begin(), s2.end());//2.�����ڲ�����ֱֵ�Ӹı���ַ������������

	//�������������ӶȱȽϵ͵Ľӿ�
	v.push_back('1');
	v.push_back('2');
	v.push_back('3');
	v.push_back('4');
	v.push_back('5');

	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();

	v.insert(v.begin(), '0');		//��Ԫ��λ�ò���0
	v.insert(--v.end(), 5,'a');		//�����ڶ���Ԫ�ص�λ�ò���5��a
	v.insert(++v.begin(), s2.begin(), s2.end());	//�ڵڶ���Ԫ�ص�λ�ò���s2�������ַ���

	v.erase(v.begin());		//ɾ����Ԫ��
	v.erase(++v.begin(), --v.end());	//ɾ���ڶ���Ԫ�ص������ڶ���Ԫ��֮�������Ԫ��
}

//==========emplace
void test6(){
	
	struct A{
		
		explicit A(int a, int b)
		:_a(a)
		, _b(b)
		{}
	private:
		int _a;
		int _b;
	};

	vector<A>v;	//��vector
	A a1(1, 2);	//��A���д�ֵ

	v.push_back(a1);	//�����һ���Զ������ͽ���Ӧ��ֵ����

	//v.push_back(2);		//����explicit���ܷ�����ʽת��


	//����ֻ��Ҫ���빹�캯����Ӧ�Ĳ���,�ӿ��ڻ��Զ���������
	v.emplace_back(2, 3);	//��������һ��,��Ӧ��ֵ������

	v.emplace_back(a1);		//��a1�е�ֵ���в���,��β��

	v.insert(v.begin(), A(2, 3));		//�ڿ�ʼλ�ò���һ��23��A

	//v.insert(v.begin(), A(5, 6));  ͬ��
	v.emplace(v.begin(), 5, 6);		//�ڿ�ʼ��λ�ò���ֵΪ56��һ������
		
}

//========ȷ���ڴ���䱶��
void test7(){
	
	vector<int>v;
	size_t c = v.capacity();

	cout << c << endl;
	for (size_t i = 0; i < 200; ++i){
		
		v.push_back(i);
		if (c != v.capacity()){
			
			c = v.capacity();
			cout << c << endl;
		}
	}
}

//========��������
void test8(){
	
	vector<int>v(3, 10);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	//1.������ĳ������ݲ�����ʱ��,�ǷǷ���,����Ŀռ��Ѿ����ͷ���,�޷����ʻᱨ��
	/*v.push_back(4);
	v.resize(5);
	v.reserve(10);*/

	//v.insert(it, 0);
	cout << *it << endl;

	it = v.begin();
	cout << *it << endl;
	
	//2.�������ʱ���������ָ���Ѿ������˱仯,�ᱨ��
	v.erase(it);
	cout << *it << endl;
}

//=========��������Ľ������
void test9(){
	
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//��ִ�������ݲ���֮��,ɾ������,���Ա��������ʧЧ������
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
}

//=========Ƕ��vector
void test10(){

	//������һ����ά����,�Ƿ�װ��10��vector���͵�����,ÿ�������ڲ�������10��0�Ķ�Ӧֵ
	vector<vector<int>>mat(10, vector<int>(10, 0));
}

int main(){
	
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	

	system("pause");
	return 0;
}
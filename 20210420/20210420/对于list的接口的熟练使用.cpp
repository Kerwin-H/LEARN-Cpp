#include<iostream>
#include<vector>
#include<list>
using namespace std;


void test1(){

	//1.��������
	list<int>lst;
	list<char>lst1;

	//2.���ַ�ʽ����
	list<int>lst3(3, 5);

	//3.���õ�������string�еĳ�ʼ����lst��
	string str = "123456";
	list<char>lst4(str.begin(), str.end());

	//4.��ͨ������ַ���ֱ�ӵ�list��
	char arr[] = "abcdefg";
	list<char>lst5(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//5.vector��ֱ�ӵ�list��
	vector<char>v(str.begin(), str.end());
	list<char>lst6(v.begin(), v.end());
}

void test2(){

	//����Ԫ��

	//���������(�ɶ����޸�)
	cout << "���������" << endl;
	string s = "123456";
	list<char>lst(s.begin(), s.end());
	list<char>::iterator it = lst.begin();

	while (it != lst.end()){

		cout << *it << " ";
		*it = 'a';
		++it;
	}
	cout << endl;

	cout << "���������" << endl;
	//ֻ��������
	list<char>::const_iterator cit = lst.cbegin();
	while (cit != lst.cend()){

		cout << *cit << " ";

		//*cit = 'c';  //���ɽ����޸�,�ʻᱨ��

		++cit;
	}
	cout << endl;


	cout << "���������" << endl;
	//���õ������ķ�ʽҲ���Խ����ַ�����ת�ļ򵥲���
	//����
	list<char>lst2(s.begin(), s.end());
	list<char>::reverse_iterator rit = lst2.rbegin();

	while (rit != lst2.rend()){

		cout << *rit << " ";

		*rit = 'a';

		++rit;
	}
	cout << endl;

	cout << "������������������" << endl;
	//���������������
	list<char>lst3(s.begin(), s.end());
	list<char>::const_reverse_iterator crit = lst3.crend();
	--crit;
	while (crit != lst3.crbegin()){

		cout << *crit << " ";
		--crit;
	}
	cout << *crit << endl;

	//��Χfor    auto �Զ������Ƶ�
	cout << "��Χfor������" << endl;
	for (auto& e : lst3){

		cout << e << " ";
		e = 'c';
	}
	cout << endl;

	for (const auto& e : lst3){

		cout << e << " ";
	}
	cout << endl;


}

void test3(){
	//����
	list<int>lst;

	lst.push_front(1);
	lst.push_back(2);
	lst.insert(lst.begin(), 0);
	lst.insert(lst.end(), 3);

	lst.emplace(lst.begin(), -1);
	lst.emplace_back(4);
	lst.emplace_front(-2);
	list<int>copy = lst;
	lst.insert(lst.end(), copy.begin(), copy.end());
	for (const auto& e : lst){

		cout << e << " ";
	}
	cout << endl;


	//����list�ĵײ���ʵ��һ������
	//����һ��Ԫ�ز��ᵼ�µ�����ʧЧ,����ɾ��һ��Ԫ�����׵��µ�����ʧЧ
	//cout << *it << endl;

	//ɾ�����ö�Ӧ������ʧȥ��������һλԪ�ص�������ַ,�ʻ�ʧЧ����޷�����
	//it = lst.erase(it);
	//cout << *it << endl; 

}

template <class T>
void printList(const list<T>& lst){

	for (const auto& e : lst)
		cout << e << " ";
	cout << endl;
}

bool compareList(const int& a, const int& b){

	return a > b;
}

void test4(){

	//spliceƴ��

	string s = "123";
	string s2 = "abc";
	list<char>lst(s.begin(), s.end());
	list<char>lst2(s2.begin(), s2.end());

	//lst.splice(lst.begin(), lst2);//��������splice������ƴ��,��ֱ�ӽ�lst2�е�����ֱ���ù�ȥ����lst2��������

	//��lst2�д�begin��һ������ʼ��ֱ��end֮������ݼ��е�lst��
	lst.splice(lst.begin(), lst2, ++lst2.begin(), lst2.end());

	lst.remove('f');	//�����Ӧ��lst����f,����ɾ��


	printList(lst);
	printList(lst2);


	lst.push_back('1');
	lst.push_back('2');
	lst.push_back('3');
	lst.push_back('a');
	lst.push_back('b');
	lst.push_back('b');
	printList(lst);
	lst.unique();		//ע�������ڵ�������ӿڵ�ʱ��,ԭ������������Ҫ�����
	//��Ϊ����ӿڵ�ԭ���ǽ���Ԫ�غ����ڵ�Ԫ�ؽ��жԱ�,�ظ�
	//��ɾ��,������������,�п���ֻ��ɾ����Ӧ�Ĳ���Ԫ��
	printList(lst);

	lst.sort(compareList);
	printList(lst);
	lst.unique();
	printList(lst);

}

void test(){

	int arr[] = { 10, 9, 3, 2 };	//����Ļ�Ҳ�޷�����ƴ��
	int arr2[] = { 29, 21, 13, 10 };	//������ȫ��˳���

	list<int>lst(arr, arr + 4);
	list<int>lst2(arr2, arr2 + 4);

	lst.sort();		//�Ƚ�������,�������ֱ���,�����mergeҪ������������²���ʹ��
	lst2.sort();

	lst.merge(lst2);	//��lst2�е�����ƴ�ӵ�lst���ڲ�,�����ʱ����lst2�е����ݱ�Ϊ��
	printList(lst);



}

int main(){

	test();

	system("pause");
	return 0;
}
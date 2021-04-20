#include<iostream>
#include<vector>
#include<list>
using namespace std;


void test1(){

	//1.基础创建
	list<int>lst;
	list<char>lst1;

	//2.数字方式创建
	list<int>lst3(3, 5);

	//3.利用迭代器将string中的初始化到lst中
	string str = "123456";
	list<char>lst4(str.begin(), str.end());

	//4.普通数组的字符串直接到list中
	char arr[] = "abcdefg";
	list<char>lst5(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//5.vector中直接到list中
	vector<char>v(str.begin(), str.end());
	list<char>lst6(v.begin(), v.end());
}

void test2(){

	//访问元素

	//迭代器输出(可读可修改)
	cout << "正向迭代器" << endl;
	string s = "123456";
	list<char>lst(s.begin(), s.end());
	list<char>::iterator it = lst.begin();

	while (it != lst.end()){

		cout << *it << " ";
		*it = 'a';
		++it;
	}
	cout << endl;

	cout << "正向迭代器" << endl;
	//只读迭代器
	list<char>::const_iterator cit = lst.cbegin();
	while (cit != lst.cend()){

		cout << *cit << " ";

		//*cit = 'c';  //不可进行修改,故会报错

		++cit;
	}
	cout << endl;


	cout << "反向迭代器" << endl;
	//利用迭代器的方式也可以进行字符串反转的简单操作
	//反向
	list<char>lst2(s.begin(), s.end());
	list<char>::reverse_iterator rit = lst2.rbegin();

	while (rit != lst2.rend()){

		cout << *rit << " ";

		*rit = 'a';

		++rit;
	}
	cout << endl;

	cout << "反向迭代器的正向输出" << endl;
	//反向迭代器向后后退
	list<char>lst3(s.begin(), s.end());
	list<char>::const_reverse_iterator crit = lst3.crend();
	--crit;
	while (crit != lst3.crbegin()){

		cout << *crit << " ";
		--crit;
	}
	cout << *crit << endl;

	//范围for    auto 自动类型推导
	cout << "范围for的运用" << endl;
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
	//插入
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


	//对于list的底层其实是一个链表
	//插入一个元素不会导致迭代器失效,但是删除一个元素容易导致迭代器失效
	//cout << *it << endl;

	//删除会让对应的链表失去对于下下一位元素的描述地址,故会失效造成无法访问
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

	//splice拼接

	string s = "123";
	string s2 = "abc";
	list<char>lst(s.begin(), s.end());
	list<char>lst2(s2.begin(), s2.end());

	//lst.splice(lst.begin(), lst2);//这里运用splice发生了拼接,会直接将lst2中的数据直接拿过去导致lst2中无数据

	//把lst2中从begin下一个数开始的直到end之间的数据剪切到lst中
	lst.splice(lst.begin(), lst2, ++lst2.begin(), lst2.end());

	lst.remove('f');	//如果对应的lst中有f,则将其删除


	printList(lst);
	printList(lst2);


	lst.push_back('1');
	lst.push_back('2');
	lst.push_back('3');
	lst.push_back('a');
	lst.push_back('b');
	lst.push_back('b');
	printList(lst);
	lst.unique();		//注意这里在调用这个接口的时候,原来的数据是需要有序的
	//因为这个接口的原理是将其元素和相邻的元素进行对比,重复
	//则删除,如果不是有序的,有可能只会删除对应的部分元素
	printList(lst);

	lst.sort(compareList);
	printList(lst);
	lst.unique();
	printList(lst);

}

void test(){

	int arr[] = { 10, 9, 3, 2 };	//逆序的话也无法进行拼接
	int arr2[] = { 29, 21, 13, 10 };	//必须是全部顺序的

	list<int>lst(arr, arr + 4);
	list<int>lst2(arr2, arr2 + 4);

	lst.sort();		//先进行排序,否则会出现报错,这里的merge要在有序的条件下才能使用
	lst2.sort();

	lst.merge(lst2);	//将lst2中的数据拼接到lst的内部,这里的时候在lst2中的数据变为空
	printList(lst);



}

int main(){

	test();

	system("pause");
	return 0;
}
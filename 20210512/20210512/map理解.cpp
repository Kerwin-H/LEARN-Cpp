#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;


//1.map是关联性容器,按特定的方式存放键值key和值value
//2.key和value是相互关联的内容,绑定在了一起叫做pair
//typedef pair value_type;
//3.内部按照键值key来进行比较排序(访问元素的速度慢)
//4.map通过平衡搜索树来实现

//=====1.内部构造
struct classcomp{

	bool operator()(const char& lhs, const char& rhs)const{

		return lhs > rhs;	//向这里的产生>的返回方式会产生逆序的排序方式
	}
};

bool fncomp(char lhs, char rhs) { return lhs<rhs; }

void test1(){

	map<char, int> m1;		//简单构造
	m1['a'] = 32;
	m1['b'] = 33;
	m1['c'] = 99;
	m1['s'] = 54;
	m1['d'] = 66;


	map<char, int> m2(m1.begin(), m1.end());		//创建新的map变量利用迭代器传入数据

	map<char, int> m3(m2);		//直接传入对应的对象也可进行复制数据

	map<char, int, classcomp> m4(m1.begin(), m1.end());	//初始化,通过这里在外部定义的函数来实现改变key大小排序的方式


	bool(*fn_pt)(char, char) = fncomp;
	map<char, int, bool(*)(char, char)> m5(fn_pt);	//指针相关


	map<char, int>m6;
	m6 = m1;				//operator=赋值运算符重载来实现数据的传递
	m1 = map<char, int>();

}

//=====2.迭代器的使用
void test2(){


	map<char, int> m1;

	m1['s'] = 5;	//按照键值进行排序
	m1['d'] = 66;
	m1['a'] = 25;
	m1['c'] = 100;

	map<char, int>::iterator it = m1.begin();			//正向迭代
	for (it; it != m1.end(); ++it){
		cout << it->first << "-->" << it->second << endl;
	}

	cout << endl;
	map<char, int>::reverse_iterator rit = m1.rbegin();	//反向迭代
	for (rit; rit != m1.rend(); ++rit){
		cout << rit->first << "-->" << rit->second << endl;
	}
}

//=====3.capacity
void test3(){

	map<char, int> m1;
	m1['s'] = 5;
	m1['d'] = 66;
	m1['a'] = 25;
	m1['c'] = 100;

	//while (!m1.empty()){}		//判空操作


	cout << m1.size() << endl;	 //size

	cout << m1.max_size() << endl;	//最大字节存储数

}

//====4.Element access
void test4(){

	map<char, string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];		//C传入b对应的value

	cout << "mymap['a'] is " << mymap['a'] << '\n';		//利用operator[]将key中对应的value进行取出
	cout << "mymap['b'] is " << mymap['b'] << '\n';
	cout << "mymap['c'] is " << mymap['c'] << '\n';
	cout << "mymap['d'] is " << mymap['d'] << '\n';


	std::map<std::string, int> mymap1 = {		//at ==查找具有指定键值的元素
		{ "alpha", 0 },
		{ "beta", 0 },
		{ "gamma", 0 } };

	mymap1.at("alpha") = 10;
	mymap1.at("beta") = 20;
	mymap1.at("gamma") = 30;

	for (const auto& x : mymap1) {
		std::cout << x.first << ": " << x.second << '\n';
	}

	cout << mymap1.at("beta") << endl;

}

//======5.Modifiers
void test5(){


	map<char, int> m1;

	m1.insert(pair<char, int>('a', 10));
	m1.insert(pair<char, int>('b', 100));	//插入


	//map<char, int>::iterator it;
	//it = m1.find('b');			//初始化迭代器来删除erase其中对应的值
	//m1.erase(it);

	map<char, int> m2;
	m2.swap(m1);		//交换内部的数据

	//m2.clear();		//清空

	m2.emplace('x', 100);
	m2.emplace('y', 300);
	m2.emplace('z', 400);

	for (auto &e : m2)
		cout << e.first << "-->" << e.second << endl;
}

//=====6.Observers
void test6(){

	map<char, int> mymap;

	map<char, int>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	char highest = mymap.rbegin()->first;     // key value of last element

	map<char, int>::iterator it = mymap.begin();
	do {
		cout << it->first << " => " << it->second << '\n';
	} while (mycomp((*it++).first, highest));

}
//=====7.Operations
void test7(){

	map<char, int> m1;
	m1['a'] = 10;
	m1['b'] = 100;
	m1['c'] = 33;
	m1['d'] = 45;
	m1['d'] = 0;
	m1['s'] = 66;
	m1['f'] = 54;
	m1['z'] = 15;
	map<char, int>::iterator it;
	it = m1.find('c');				//find应用
	for (auto& e : m1)
		cout << e.first << "-->" << e.second << endl;


	std::map<char, int> mymap;
	char c;

	mymap['a'] = 101;
	mymap['c'] = 202;
	mymap['f'] = 303;

	for (c = 'a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)		//类似于计数
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}


	map<char, int>::iterator itl, itr;	//创建对应的迭代器位置
	itl = m1.lower_bound('c');			//设置对应的边界位置
	itr = m1.upper_bound('f');
	m1.erase(itl, itr);		//删除对应的边界内部的数据,注意上面的数据是按顺序存放的

}

//multimap
void test(){
	
	multimap<char, int> m1;
	m1.insert(pair<char, int>('a', 10));
	m1.insert(pair<char, int>('a', 100));
	m1.insert(pair<char, int>('b', 1000));
	m1.insert(pair<char, int>('d', 10000));
	m1.insert(pair<char, int>('d', 100000));
	m1.insert(pair<char, int>('g', 1000000));
	m1.insert(pair<char, int>('g', 1066));
	m1.insert(pair<char, int>('j', 1044));
	m1.insert(pair<char, int>('k', 1033));

	multimap<char, int>::iterator it;
	it = m1.find('a');
	m1.erase(it);
	it = m1.find('a');
	m1.erase(it);

}



int main(){

	test();

	system("pause");
	return 0;
}
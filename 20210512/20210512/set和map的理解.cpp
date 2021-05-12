#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;


//向list vector 这些叫做序列式容器  底层为线性顺序的数据结构
//=====1.关联式容器的理解: 底层存储着<key,value> 的键值对,数据检索的效率更高


//=====2.键值对
//其内部其实就是将两个资源互联,访问其中的一个就可以获取到另外一个的数据
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

//==========3.树型结构的关联性容器
//set//map//multimap//multiset四种

//=====3.1  set

//构建函数
void test1(){
		
	//数组输入
	int arr[] = { 1, 1, 2, 3, 4, 4, 5, 5, 6 };
	set<int>s(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//范围for打印,查看元素是否重复
	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	///迭代器逆置打印
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	
	
	set<char>s2(s.begin(), s.end());	//将set1中的数据进行传递

	//利用operator=来实现数据的交换,并且将之前数据置空
	set<int> s3;
	s3 = s;
	s = set<int>();
}
//Capacity
void test2(){
	
	set<int>s;
	s.empty();		//判空操作

	cout << "size:" << s.size() << endl;		//size()使用
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

	s.insert(5);		//插入
	s.insert(10);
	s.insert(15);

	s.erase(5);		//删除
	s.erase(1);


	set<int>s2;
	s2.insert(666);

	s.swap(s2);		//交换

	s.clear();		//清空

	s.emplace(66);
	s.emplace(666);		//类似于插入
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


	cout << s.count(2) << endl;		//count  0/1打印,因为只存在单一的数据
	cout << s.count(4) << endl;



	set<int>sa;
	set<int>::iterator itlow, itup;
	
	for (int i = 1; i < 10; ++i)
		sa.insert(i);

	itlow = sa.lower_bound(2);		//设置两端迭代器的区间,用来删除对应的元素(包含2和5)
	itup = sa.upper_bound(5);

	sa.erase(itlow, itup);
	for (auto &e : sa)
		cout << e << " ";

	s.equal_range(6);		//不懂??????

}

//multiset
void test(){
	
	int arr[] = { 1, 2, 3, 4, 4, 5, 5, 5, 7, 2 };		//数据可重复
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
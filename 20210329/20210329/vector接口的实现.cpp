#include<iostream>
#include<vector>
#include<string>
using namespace std;


//========1.简单的构建一个vector 
void test1(){
	

	struct A{

		A(int a = 1, int b = 2)
		:_a(a)
		, _b(b)
		{}
		int _a = 1;
		int _b = 2;
	};
	//==建立出一个空的vector
	vector<int>v1;
	vector<char>v2;
	vector<A>v3;

	//==内置类型:缺省值为类0值(就是不同类型的0的意思)
	//这里面的5是开辟五个字节的空间,并且初始值均为 类0
	vector<int>v4(5);
	vector<char>v5(5);
	vector<int*>v6(5);
	vector<float>v7(5);

	//自定义类型: 缺省值为默认构造函数
	vector<A>v8(5);	//类似于开辟5个一样的A,其中的值为A里面的缺省值


	vector<A>v9(5, A(10)); //这里是创建自定义的vector并给里面进行赋值,如果只有一个值则只给前面的进行赋值



	//数组方式
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int>v10(arr, arr + sizeof(arr) / sizeof(arr[0]));	//将内部的初值转换成数组内部的数据

	char arr2[] = { 1, 2, 3, 4, 5 };
	vector<char>v11(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));	//转换成char类型的12345

	//迭代器方式
	string str("1234567890");
	vector<char>v12(str.begin(), str.end());
}


//========2.将内部的数据进行输出
void test2(){
	
	string str("1234567890");
	vector<char>v(str.begin(), str.end());

	for (auto& ch : v){		//利用范围for将内部的数据进行输出
		
		cout << ch;
		//ch = 'a';		//将内部的值进行改变
	}
	for (const auto& ch : v){	//输出改变后的值
		
		cout << ch;
	}
	cout << endl;

	//迭代器
	vector<char>::iterator it = v.begin();
	//下面这个const的不能对其进行解引用,因为内部的值已经被是释放掉
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

	//显示出最大存储量
	cout << v1.max_size() << endl;
	cout << v2.max_size() << endl;
	cout << v3.max_size() << endl;
	cout << v4.max_size() << endl;
	cout << v5.max_size() << endl;

	cout << v1.size() << endl;	//查看对应的字节
	cout << v1.capacity() << endl;	//最大容量

	v1.resize(10);
	v2.resize(2);
	v3.resize(4);
	v4.resize(6);
	v5.resize(3);


	v5.reserve(6);
	v1.reserve(5);		//内存容量只能改大,不能变小!!!
	v2.reserve(10);

	v5.shrink_to_fit();	 //如果在对应的空间内部有多余的空闲部分,则调用这个接口则会直接删掉

}


//========4.对应元素的访问
void test4(){
	
	string str = "1234567890";
	vector<char>v(str.begin(), str.end());

	for (size_t i = 0; i < str.size(); ++i){
		
		cout << v.operator[](i) << " ";		//第一次全形式打印

		v.operator[](i) = i + 'a';		//改变值

		cout << v[i] << " ";		//二次打印

		v[i] = i + 'q';		//改值

	}

	cout << endl;
	for (size_t i = 0; i < str.size(); ++i){

		cout << v[i] << " ";	//查看第二次打印的作用
		
	}

	//v[100] = 'a';
	//v.at(100) = 'a';

	//char* ptr = v.data();
}

//========5.功能函数
void test5(){
	
	//assign感觉size大小很容易改变

	string s("1234");
	vector<char>v(s.begin(), s.end());
	v.assign(10, 'a');		//1.改变vector内部的值和size的大小/功能比较多

	string s2("abcdef");
	v.assign(s2.begin(), s2.end());//2.将其内部的数值直接改变成字符串里面的内容

	//下面是两个复杂度比较低的接口
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

	v.insert(v.begin(), '0');		//首元素位置插入0
	v.insert(--v.end(), 5,'a');		//倒数第二个元素的位置插入5个a
	v.insert(++v.begin(), s2.begin(), s2.end());	//在第二个元素的位置插入s2的整个字符串

	v.erase(v.begin());		//删除首元素
	v.erase(++v.begin(), --v.end());	//删除第二个元素到倒数第二个元素之间的所有元素
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

	vector<A>v;	//空vector
	A a1(1, 2);	//对A进行传值

	v.push_back(a1);	//插入第一个自定义类型将对应的值插入

	//v.push_back(2);		//运用explicit不能发生隐式转化


	//我们只需要传入构造函数对应的参数,接口内会自动创建对象
	v.emplace_back(2, 3);	//在最后插入一个,对应的值的数组

	v.emplace_back(a1);		//将a1中的值进行插入,在尾部

	v.insert(v.begin(), A(2, 3));		//在开始位置插入一个23的A

	//v.insert(v.begin(), A(5, 6));  同下
	v.emplace(v.begin(), 5, 6);		//在开始的位置插入值为56的一个数组
		
}

//========确认内存分配倍数
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

//========两种问题
void test8(){
	
	vector<int>v(3, 10);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	//1.在这里的出现增容操作的时候,是非法的,这里的空间已经被释放了,无法访问会报错
	/*v.push_back(4);
	v.resize(5);
	v.reserve(10);*/

	//v.insert(it, 0);
	cout << *it << endl;

	it = v.begin();
	cout << *it << endl;
	
	//2.在这里的时候迭代器的指向已经发生了变化,会报错
	v.erase(it);
	cout << *it << endl;
}

//=========两种问题的解决方法
void test9(){
	
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//在执行完增容操作之后,删除操作,可以避免迭代器失效的问题
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
}

//=========嵌套vector
void test10(){

	//类似于一个二维数组,是封装了10个vector类型的数组,每个数组内部都有着10个0的对应值
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
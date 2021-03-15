#include<iostream>
#include<string>
using namespace std;

//STL========String类

//====6种初始化方式
//void test(){
//	
//	//1.创建空的string对象
//	//string();
//	string str;
//
//	//2.拷贝
//	//string(const string& str);
//	string copy(str);
//
//	//3.通过内部的字符串创建一个对象
//	//string(const char* s);
//	string str2("abc");
//
//	//4.通过一个字符串的部分内容来创建新的字符串对象
//	//string(const string& str,size_t pos,size_t len=npos);
//	string substr(str2, 1, 2); // "bc" (对应的字符串,从哪一个开始,往后几个字符)
//
//	//5.获取你输入字符串的前几个
//	//string(const char* s,size_t n);
//	string str3("12345678", 5);  //"12345"
//
//	//6.创建一个字符对象有几个后面的字符
//	//string(size_t n, char c);
//	string str4(10, 'a');	//"aaaaaaaaaa"
//	
//	//7.常用
//	string str5 = "abcde";	//单参构造的隐式类型转换
//
//
//	str5 = str4;
//	str5 = "123";
//	str5 = 'b';
//}

//====string类对象的简单构造
//void test(){
//
//	const string str="12345";
//	string str2 = "12345";
//	
//
//	//const对象,调用接口: const char& operator[](size_t pos) const
//	//可以使用类似于数组的方式对字符串进行访问
//	
//	//==1.可读取其中的字符串
//	char ch = str[3];
//	const char& ref = str[3];
//
//	//==2.不可修改其中的字符串(这里是const形式,不可修改)
//	/*str[3] = 'f';
//	str[3] = 'a';*/
//
//	//非const对象: char& operator[](size_t pos) const
//	char& ref = str2[3];
//	str2[3] = 'a';
//
//	//==在这里直接利用at可以对其直接进行赋值
//	str2.at(3) = 'b';
//
//
//	//==[]越界:报断言错误
//	//char ch2 = str2[10];
//	
//	//==at越界:抛异常
//	//char ch2 = str2.at(10);
//
//}

//====1.迭代器
//使用方法和指针类似
//设计规范:
//1.begin迭代器:指向第一个元素
//2.end迭代器:指向最后一个元素的末尾
//3.访问数据:通过解引用来完成 : *,->
//4.迭代器移动: ++移动到下一个元素,--移动到上一个元素
//5.位置的判断: 支持!= ,== 
//在其中的有些容器中存在反向迭代器
//6.rbegin迭代器: 指向最后一个元素的位置		(包含起始,不包含结束)
//7.rend迭代器: 指向第一个元素的前一个位置

//====正向迭代器
//void test(){
//
//	string str = "12345";
//	//起始位置的迭代器
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it){
//		
//		//迭代器的解引用
//		cout << *it <<" ";
//
//		//可以通过迭代器对内容进行修改
//		*it = 'a';
//
//	}
//	const string str2 = "abcde";
//	//只读的操作
//	string::const_iterator it2 = str2.begin();
//	while (it2!=str2.end()){
//		
//		cout << *it2 << " ";
//		//只读迭代器,不可以发生修改,因为是const
//		//*it2 = 's';
//		++it2;
//	}
//}

//====反向迭代器
//void test(){
//
//	string str = "12345";
//	//最后一个元素的位置
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend()){
//		
//		cout << *it << " ";	//54321
//		//反向移动
//		*it = 'a';
//		++it;
//	}
//
//
//	//只读的反向迭代器
//	const string str2 = "abcde";
//
//	string::const_reverse_iterator it2 = str2.rbegin();
//	while (it2 != str2.rend()){
//		
//		cout << *it2 << " ";
//		//只读迭代器:const不可以发生修改
//		//*it2 = "d";
//		++it2;
//	}
//}

//====2.范围for
//void test(){
//	
//	//==范围for:访问范围确定的序列
//	int arr[] = { 1, 2, 3, 4, 5 };
//	for (const auto& e : arr){
//		
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : arr){
//		
//		e = 10;
//	}
//
//	string str = "12345";
//	//范围for:实际上就是通过迭代器进行实现的
//	//		  支持迭代器访问的自定义类型都可以支持范围for
//	for (auto& ch : str){
//
//		cout << ch << " ";
//		ch = 'a';
//	}
//}

//====3.for循环
//void test(){
//	
//	string str = "12345";
//	for (size_t i = 0; i < str.size(); ++i){
//		
//		cout << str[i] << " ";
//		str[i] = 'a';
//	}
//	cout << endl;
//}

//========对于string访问的方式
//1.for循环+operator[]
//2.迭代器
//3.范围for
//这三种方式都可以修改其内容
 

//========容量相关的接口size
//void test(){
//
//	string  str;
//	cout << str.size() << endl;
//	
//	//====resize:修改有效字符的个数
//	//resize(n):如果有效字符个数增加,新的位置填充'\0'
//	//resize(n, ch): 如果有效字符的个数增加,则新增的位置填充ch
//	//如果size减小,则不会进行填充
//
//	//==修改有效字符的个数
//	//有效字符是按照size最终的大小来规定的,\0也有可能是有效字符
//	str.resize(10);
//
//	cout << str.size() << endl;
//
//	string str2 = "123";		//在有效元素不够的时候,像这里会填充7个\0
//	cout << str2.size() << endl;
//	str2.resize(10);
//	cout << str2.size() << endl;
//
//	str2.resize(2);		//将有效字符减少
//	cout << str2.size() << endl;
//
//	//如果有扩充空间的话,将需要填充的空间将a进行填入,就不为\0
//	str2.resize(5, 'a');	//12aaa
//
//	str2.resize(2, 'b');	//如果变小,没有需要填充的位置则没有用
//
//}

//====capacity
//void test(){
//
//	string str = "123";
//	int sz = str.size();
//	//capacity当前string 中最多可以存放的元素个数
//	int cap = str.capacity();
//	str.resize(10);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(1);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(20);
//	//resize:当调整之后的size大于容量的时候,容量也会发生变化
//	sz = str.size();
//	cap = str.capacity();
//
//	//reserve:修改容量:只能进行容量的增加,不能减小
//	//不影响size
//	str.reserve(60);
//	sz = str.size();
//	cap = str.capacity();
//
//	str.reserve(10);
//	sz = str.size();
//	cap = str.capacity();
//
//
//	//clear: 清空有效字符	只影响size 
//	str.clear();
//	sz = str.size();
//	cap = str.capacity();
//
//}

//====shrink接口
//void test(){
//
//	string str = "123";
//	int sz = str.size();
//	int cap = str.capacity();
//
//	//主要作用就是把将其中像'\0'这样没有作用的字符进行清理,保证每个字符都是有效的
//	str.shrink_to_fit();	
//	int sz = str.size();
//	int cap = str.capacity();
//
//}

//====push_back
//void test(){
//	
//	//按照1.5倍的空间进行增容
//	string str;
//	int cap = str.capacity();
//
//	//避免频繁的增容,提高代码的效率
//	//直接增容到200,就不存在过程
//	str.reserve(200);
//	
//	cout << cap << endl;
//	for (int i = 0; i < 200; ++i){
//		
//		str.push_back('a');
//		if (cap != str.capacity()){
//			
//			cap = str.capacity();
//			cout << cap << endl;
//		}
//	}
//}

//+=	类似于尾插
//void test(){
//
//	string str;
//	string str2 = "123";
//	
//	//连续操作
//	str += str2;	//123
//	str += "abc";	//123abc
//	str += '4';		//123abc4
//	//完整形式
//	str.operator+=('5');	//123abc45
//
//}

//append类似于相加
//void test(){
//
//	string str;
//	string str2 = "123";
//
//	str.append(str2);	//123
//
//	str.append(str2, 1, 1);		//1232
//
//	str.append("abc");	//1232abc
//
//	str.append("123456", 6);	//1232abc123456
//
//	str.append(5, 'm');	//1232abc123456mmmmm
//
//	char arr[] = "abcdefg";
//	str.append(arr, arr + sizeof(arr) / sizeof(arr[0]));	//1232abc123456mmmmmabcdefg 
//	str.append(str2.begin(), str2.end());	//1232abc123456mmmmmabcdefg123
//
//}

//==insert
void test(){

	string str="123";
	string str2 = "abc";

	str.insert(0, str2);	//abc123

	str.insert(4, str2, 1, 2);	//abc1bc23

	str.insert(str.size(), "abc");	//abc1bc23abc

	str.insert(5, "12345", 4);	//abc1b1234c23abc

	str.insert(str.begin(), 2, '0');	//00abc1b1234c23abc

	str.insert(str.end(), str2.begin(), str2.end());	//00abc1b1234c23abc123



}




int main(){
	
	test();
	system("pause");
	return 0;
}


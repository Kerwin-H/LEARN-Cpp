#include<iostream>
#include<string>

using namespace std;

//========字符串的修改
//====erase
//void test(){
//
//	string str = "123456";
//	str.erase(3, 2);  //1236
//	str.erase(0, 1);  //236
//
//	str.erase(str.begin());  //36
//	str.erase(str.begin(),str.end());  //3
//
//	str.erase(0);	//""
//
//	string str1 = "12/34567/89";
//	str1.replace(2, 5, "abc");   //12abc89
//
//	str1.replace(++str1.begin(), --str1.end(), "dddddddd");
//	
//	//成员函数
//	str1.swap(str);		//字符串进行交换
//	//全局
//	swap(str, str1);	//类似于自己进行模板初始化的一个函数
//
//
//}
//====
//void test(){
//
//	string str = "123456";
//
//	str.resize(20);
//
//	cout << str << "end" << endl;	//输出所有的有效字符,会将里面存在的\0也会进行输出
//	
//	//按照C的方式来进行输出
//	cout << str.c_str() <<"end"<< endl;	//当遇到\0就会直接结束,不会输出\0
//	cout << str.data() << "end" << endl;
//
//
//}

//====cout出现未定义行为

//void test(){
//
//	string str = "23456123123";
//	string str2 = "123";
//	
//	//find寻找对应的字符串,只找第一个
//	//找不到返回
//	size_t pos = str.find("666663");	//找不到返回最大的容量//4G
//	pos = str.find(str2);
//
//	pos = str.find("456abd", 0, 2);	//查找从0开始2个字符的对应  //45
//
//	//反向查找
//	pos = str.rfind(str2);
//
//	//查找一个域名对应得位置
//	string str4 = "https://blog.csdn.net/weixin_46554582/article/details/114886749";
//	pos = str4.find("://");
//	size_t end = str4.find("/", pos + 3);
//	string sub = str4.substr(pos + 3, end - pos-3);
//
//
//	string file = "test.tar.gz.txt";
//	pos = file.rfind('.');
//	string suff = file.substr(pos + 1);
//
//	//相关查找的函数
//	pos = str.find_first_not_of;	//不属于以后的一个
//	pos = str.find_first_of;		//找到任意的第一个
//	pos = str.find_last_not_of;		//不属于的最后一个
//	pos = str.find_last_of;			//最后一个
//
//
//}

//====比较
void test(){

	string str = "123455";
	string str2 = "ab";



	//string的比较:按照每一个得第一个ASCII码值进行比较
	bool ret = str == str2;
	ret = str > str2;
	ret = str < str2;
	

	//输入:
	//cin会在遇到空格结束/换行结束
	cin >> str;

	//getline:遇到换行结束
	getline(cin, str);

	getline(cin, str, ',');		//遇到逗号结束


}



int main(){

	test();

	system("pause");
	return 0;
}


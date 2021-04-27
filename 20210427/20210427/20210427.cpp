#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;



void test1(){

	//cin: 是istream的对象  ,其实本质上是一个重载函数
	int a;
	cin >> a;
	cin.operator>>(a);	//这里其实内部是通过重载函数来实现

	float f;
	cin >> f;
	cin.operator>>(f);	//对于不同的类型直接通过不同类型的重载来实现对于不同的输入


	//cout: ostream的对象
	//也是通过重载来实现
	cout << a;
	cout.operator<<(a).operator<<(endl);	//输出其他的程序也是一致的

	//scanf  ///printf //这两者都是库函数,系统无法根据类型的不同来实现输入
	scanf("%s", a);
	//所以这里的库函数的代码我们就需要对于其内部要输入的类型进行定义,无法让系统内部对于输入的不同而进行重载

}


struct Student{

	int age;
	char name[20];
};
void test2(){
	
	//ofstream : 输入文件流
	//ifstream : 输出文件流

	//写文件: 文件不存在,创建新的文件
	ofstream fout("test.txt");
	//fout.open("test.txt");

	if (!fout.is_open())
		cout << "not open" << endl;

	//写入对应的数据
	//=====1.文本文件  :字符流读写

	fout << "test.txt" << endl;		//!!!内部有析构函数会调用close对文件进行关闭
		
	fout.put('a');
	//fout.close();

	//读文件: 文件不存在,打开失败
	ifstream fin("test.txt");
	char arr[100];
	fin >> arr;

	//读取单个的字符
	char ch;
	ch = fin.get();
	fin.get(ch);		//读取单个的字符
	fin.get(arr, 100);	//读取对应的100个字符

	fin.getline(arr, 100);	//读取对应的一行代码,如果字符够则为空,够则只传前100


	ofstream fout("test.txt");
	//Student stu;		//创建结构体对于内部的数据进行读写
	//stu.age = 30;
	//strcpy(stu.name,"abc");
	//fout << stu.name << endl;		//输出
	//fout << stu.age << endl;

	fout.close();


	//=====2.二进制读写: 字节流读写

	ofstream fout2("test.binary.txt");

	//fout2.write((char*)&stu,sizeof(stu));	//这里对于char*类型直接进行强转
	fout2.close();


	//二进制的读文件
	ifstream fin("test.binary.txt", ifstream::binary);//这里是对于二进制的声明

	//Student stu;

	//fin.read((char*)&stu, sizeof(stu));	
	//在这里对于文件首先进行char类型的强转
	//然后再对对应的size进行大小字节的读入


}





void test(){

	//1.stringstream : 数值--->字符串


	//stringstream ss;

	int a = 10;
	//int b = 010;
	//int c = 0x10;

	//char arr[100];
	//itoa(a, arr, 10);
	//itoa(b, arr, 8);
	//itoa(c, arr, 16);
	//
	////sprintf
	//sprintf(arr, "%f", a);
	float f = 2.3;
	//sprintf(arr,"%d",f);
	//printf("%d",a);

	stringstream ss;
	string str;
	ss << a;
	ss >> str;

	//clear(): 下一次转换之前,调用clear接口清空状态位
	//不会清空其内容
	ss.clear();
	ss << f;
	ss >> str;


	//str(重置内容)  :重置stringstream对象中的内容
	ss.str("");

	//str() : 获取stringstream对象中内容
	str = ss.str();

	ss.clear();
	ss << f;

	str = ss.str();

	//2.字符串拼接
	ss.str("");
	ss << "123" << "456" << "789";
	cout << ss.str() << endl;

}





int main(){

	test();
	system("pause");
	return 0;
}
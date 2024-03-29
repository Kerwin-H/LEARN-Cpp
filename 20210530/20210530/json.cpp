#include "json.hpp"

using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


//json序列化实例1
//内部存储的是无序的
string func1(){

	json js;
	js["msg_type"] = 2;
	js["from"] = "zhangsan";
	js["to"] = "lisi";
	js["msg"] = "hello mu friend";

	string buf = js.dump();   //将其转成字符串的形式,通过网络来进行发送

	//cout<<buf.c_str()<<endl;
	return buf;
}

//序列化2
string func2(){

	json js; // 添加数组 
	js["id"] = { 1, 2, 3, 4, 5 }; // 添加key-value
	js["name"] = "zhang san"; // 添加对象 
	js["msg"]["zhang san"] = "hello world";
	js["msg"]["liu shuo"] = "hello china";
	// 上面等同于下面这句一次性添加数组对象 
	js["msg"] = { { "zhang san", "hello world" }, { "liu shuo", "hello china" } };
	//cout << js << endl;

	return js.dump();
}

//序列化3
string func3(){

	json js; // 直接序列化一个vector容器
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);

	js["list"] = vec;

	// 直接序列化一个map容器
	map<int, string> m;
	m.insert({ 1, "黄山" });
	m.insert({ 2, "华山" });
	m.insert({ 3, "泰山" });

	js["path"] = m;

	string buf1 = js.dump();      //将对应的数据转成字符串,方便对于数据进行发送
	// cout<<buf1.c_str()<<endl;

	return buf1;
	//cout<<js<<endl;
}


int main(){

	string rece = func3();

	//数据的反序列化 ! 字符串反序列成数据对象(并且保留对应的数据类型)
	json jsbuf = json::parse(rece);

	// cout<<jsbuf["msg_type"]<<endl;
	// cout<<jsbuf["from"]<<endl;
	// cout<<jsbuf["to"]<<endl;
	// cout<<jsbuf["msg"]<<endl;

	// cout<<jsbuf["id"]<<endl;
	// auto arr=jsbuf["id"];
	// cout<<arr[2]<<endl;

	vector<int> vec = jsbuf["list"];//js内部的数组类型直接放入vector容器内部
	for (int &v : vec){

		cout << v << " ";
	}
	cout << endl;

	map<int, string> m = jsbuf["path"];
	for (auto &p : m){

		cout << p.first << " " << p.second << endl;
	}


	return 0;
}

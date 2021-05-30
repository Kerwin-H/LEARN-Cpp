#include "json.hpp"

using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


//json���л�ʵ��1
//�ڲ��洢���������
string func1(){

	json js;
	js["msg_type"] = 2;
	js["from"] = "zhangsan";
	js["to"] = "lisi";
	js["msg"] = "hello mu friend";

	string buf = js.dump();   //����ת���ַ�������ʽ,ͨ�����������з���

	//cout<<buf.c_str()<<endl;
	return buf;
}

//���л�2
string func2(){

	json js; // ������� 
	js["id"] = { 1, 2, 3, 4, 5 }; // ���key-value
	js["name"] = "zhang san"; // ��Ӷ��� 
	js["msg"]["zhang san"] = "hello world";
	js["msg"]["liu shuo"] = "hello china";
	// �����ͬ���������һ�������������� 
	js["msg"] = { { "zhang san", "hello world" }, { "liu shuo", "hello china" } };
	//cout << js << endl;

	return js.dump();
}

//���л�3
string func3(){

	json js; // ֱ�����л�һ��vector����
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);

	js["list"] = vec;

	// ֱ�����л�һ��map����
	map<int, string> m;
	m.insert({ 1, "��ɽ" });
	m.insert({ 2, "��ɽ" });
	m.insert({ 3, "̩ɽ" });

	js["path"] = m;

	string buf1 = js.dump();      //����Ӧ������ת���ַ���,����������ݽ��з���
	// cout<<buf1.c_str()<<endl;

	return buf1;
	//cout<<js<<endl;
}


int main(){

	string rece = func3();

	//���ݵķ����л� ! �ַ��������г����ݶ���(���ұ�����Ӧ����������)
	json jsbuf = json::parse(rece);

	// cout<<jsbuf["msg_type"]<<endl;
	// cout<<jsbuf["from"]<<endl;
	// cout<<jsbuf["to"]<<endl;
	// cout<<jsbuf["msg"]<<endl;

	// cout<<jsbuf["id"]<<endl;
	// auto arr=jsbuf["id"];
	// cout<<arr[2]<<endl;

	vector<int> vec = jsbuf["list"];//js�ڲ�����������ֱ�ӷ���vector�����ڲ�
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

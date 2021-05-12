#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;


//1.map�ǹ���������,���ض��ķ�ʽ��ż�ֵkey��ֵvalue
//2.key��value���໥����������,������һ�����pair
//typedef pair value_type;
//3.�ڲ����ռ�ֵkey�����бȽ�����(����Ԫ�ص��ٶ���)
//4.mapͨ��ƽ����������ʵ��

//=====1.�ڲ�����
struct classcomp{

	bool operator()(const char& lhs, const char& rhs)const{

		return lhs > rhs;	//������Ĳ���>�ķ��ط�ʽ��������������ʽ
	}
};

bool fncomp(char lhs, char rhs) { return lhs<rhs; }

void test1(){

	map<char, int> m1;		//�򵥹���
	m1['a'] = 32;
	m1['b'] = 33;
	m1['c'] = 99;
	m1['s'] = 54;
	m1['d'] = 66;


	map<char, int> m2(m1.begin(), m1.end());		//�����µ�map�������õ�������������

	map<char, int> m3(m2);		//ֱ�Ӵ����Ӧ�Ķ���Ҳ�ɽ��и�������

	map<char, int, classcomp> m4(m1.begin(), m1.end());	//��ʼ��,ͨ���������ⲿ����ĺ�����ʵ�ָı�key��С����ķ�ʽ


	bool(*fn_pt)(char, char) = fncomp;
	map<char, int, bool(*)(char, char)> m5(fn_pt);	//ָ�����


	map<char, int>m6;
	m6 = m1;				//operator=��ֵ�����������ʵ�����ݵĴ���
	m1 = map<char, int>();

}

//=====2.��������ʹ��
void test2(){


	map<char, int> m1;

	m1['s'] = 5;	//���ռ�ֵ��������
	m1['d'] = 66;
	m1['a'] = 25;
	m1['c'] = 100;

	map<char, int>::iterator it = m1.begin();			//�������
	for (it; it != m1.end(); ++it){
		cout << it->first << "-->" << it->second << endl;
	}

	cout << endl;
	map<char, int>::reverse_iterator rit = m1.rbegin();	//�������
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

	//while (!m1.empty()){}		//�пղ���


	cout << m1.size() << endl;	 //size

	cout << m1.max_size() << endl;	//����ֽڴ洢��

}

//====4.Element access
void test4(){

	map<char, string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];		//C����b��Ӧ��value

	cout << "mymap['a'] is " << mymap['a'] << '\n';		//����operator[]��key�ж�Ӧ��value����ȡ��
	cout << "mymap['b'] is " << mymap['b'] << '\n';
	cout << "mymap['c'] is " << mymap['c'] << '\n';
	cout << "mymap['d'] is " << mymap['d'] << '\n';


	std::map<std::string, int> mymap1 = {		//at ==���Ҿ���ָ����ֵ��Ԫ��
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
	m1.insert(pair<char, int>('b', 100));	//����


	//map<char, int>::iterator it;
	//it = m1.find('b');			//��ʼ����������ɾ��erase���ж�Ӧ��ֵ
	//m1.erase(it);

	map<char, int> m2;
	m2.swap(m1);		//�����ڲ�������

	//m2.clear();		//���

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
	it = m1.find('c');				//findӦ��
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
		if (mymap.count(c)>0)		//�����ڼ���
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}


	map<char, int>::iterator itl, itr;	//������Ӧ�ĵ�����λ��
	itl = m1.lower_bound('c');			//���ö�Ӧ�ı߽�λ��
	itr = m1.upper_bound('f');
	m1.erase(itl, itr);		//ɾ����Ӧ�ı߽��ڲ�������,ע������������ǰ�˳���ŵ�

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
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<iostream>
using namespace std;


void test(){

	unordered_multimap<int, int> m;
	//map<int, int> m;
	//�������ܱ�map����: O(1)
	m.insert(make_pair(1, 1));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(3, 3));
	/*for (int i = 3; i < 100; ++i){

	m[i] = i;
	}*/

	//����ĵ������ı������������
	//�����map/set,unordered_map/setֻ�����������
	//unordered_map<int, int>::iterator it = m.begin();
	auto it = m.begin();	//�Զ��Ƶ�
	while (it != m.end()){

		cout << it->first << " ";
		++it;
	}
	cout << endl;

	cout << "equal_range" << endl;
	auto range = m.equal_range(3);
	it = range.first;
	while (it != range.second){

		cout << it->first << " ";
		++it;
	}
	cout << endl;

}
//��ϣ��ͻ

//1.��ɢ��
//====����̽��: �Ӽ���Ĺ���λ�ÿ�ʼ,�ҳ���һ�����е�λ��,�������


//2.��ɢ��



int main(){

	test();

	system("pause");
	return 0;
}
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<iostream>
using namespace std;


void test(){

	unordered_multimap<int, int> m;
	//map<int, int> m;
	//操作性能比map更高: O(1)
	m.insert(make_pair(1, 1));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(3, 3));
	/*for (int i = 3; i < 100; ++i){

	m[i] = i;
	}*/

	//这里的迭代器的遍历不是有序的
	//相对于map/set,unordered_map/set只有正向迭代器
	//unordered_map<int, int>::iterator it = m.begin();
	auto it = m.begin();	//自动推导
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
//哈希冲突

//1.闭散列
//====线性探测: 从计算的哈西位置开始,找出第一个空闲的位置,存放数据


//2.开散列



int main(){

	test();

	system("pause");
	return 0;
}
#include<iostream>
#include<set>
using namespace std;


void test(){

	set<int> s;
		//��������
		//1.�ڲ�ֻ�ܴ�ŵ�һ������,�Լ�ȥ���ظ���Ԫ��


		//2.����ʹ�����Ƶĵ������ķ�ʽ�����г��� 
		
	
		//3.set��������֧���޸�

		//4.

	int arr[] = { 1, 2, 3 };
	s.insert(arr, arr + sizeof(arr) / sizeof(arr[0]));
	s.erase(s.begin());	//end����������
	
}

int main(){

	test();
	
	system("pause");
	return 0;
}

#include<functional>
#include<iostream>
#include<vector>
using namespace std;
#include<queue>
#include<list>


//====2.������ʵ�ֵ�k������Ԫ��
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;
		for (auto& e : nums)
			pq.push(e);
		while (k-->1)
			pq.pop();
		return pq.top();
	}
};



//1.====��listʵ�ֶ���
template <class T>
class Queue{

public:
	void push(const T& val){

		_q.pop_back(val);
		//_q.pop_front(val);
	}

	void pop(){

		_q.pop_front();
		//_q.pop_back();
	}

	T& front(){

		return _q.front();
		//return _q.back();
	}

	size_t size() const{

		return _q.size();
	}

	bool empty() const{

		return _q.empty();
	}
private:
	list<T> _q;
};





//1.=====������ʵ��ջ
class MyStack {

private:
	queue<int> q;

public:

	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int top;
		int sz = q.size();
		while (sz>1){

			int front = q.front();
			q.pop();
			q.push(front);
			--sz;
		}
		top = q.front();
		q.pop();
		return top;
	}

	/** Get the top element. */
	int top() {
		int topV;
		int sz = q.size();
		while (sz>0){

			topV = q.front();
			q.pop();
			q.push(topV);
			--sz;
		}
		return topV;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

class MinStack {

private:
	stack<int> _st;
	stack<int> _minSt;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		_st.push(val);
		if (_minSt.empty() || val <= _minSt.top())
			_minSt.push(val);
	}

	void pop() {
		if (_st.top() == _minSt.top())
			_minSt.pop();
		_st.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _minSt.top();
	}
};


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> st;
		int pushIdx = 0;
		int popIdx = 0;

		while (pushIdx<pushV.size()){

			//ÿ����ջһ��Ԫ��
			st.push(pushV[pushIdx++]);
			//ѭ���ж��Ƿ���Ҫ��ջ��Ԫ��
			while (!st.empty() && st.top() == popV[popIdx]){
				st.pop();
				popIdx++;
			}
		}
		return st.empty();
	}
};
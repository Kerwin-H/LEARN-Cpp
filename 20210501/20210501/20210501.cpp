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

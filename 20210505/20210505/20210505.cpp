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
//=====1.��Сջ  : ֻ������С��ֵ,���Ὣ���ڵ�ֵ����/�ڲ�������ջ
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

//=====2.ջ�ĵ���ѹ������
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

//=====3.�沨�����ʽ
// atoi : �ַ���ת���� stoi : string����ת����
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const auto& str : tokens){

			//�������ж�
			if (str == "+" || str == "-"
				|| str == "*" || str == "/")
			{
				//�����������ִ��
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (str == "+")
					st.push(left + right);
				else if (str == "-")
					st.push(left - right);
				else if (str == "*")
					st.push(left*right);
				else if (str == "/")
					st.push(left / right);
			}
			else
				st.push(stoi(str));
		}
		return st.top();
	}
};




//����˫�˶��е�ʵ��
//����Ӧ�����ݽ��зֶ�ʽ�洢,��ͷ����β�������Խ������ݵ���������
//ͨ����������洢�ռ���ʵ��

//���ݴ���С
//1.���ݵĻ���������,��һ���µĻ�����,���������׵�ַ����ָ������
//2.ָ����������,�¿�һ��ָ������,ֻҪ����ԭ�еĻ�������ָ��,������Ԫ��

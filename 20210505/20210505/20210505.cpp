#include<functional>
#include<iostream>
#include<vector>
using namespace std;
#include<queue>
#include<list>


//====2.数组中实现第k个最大的元素
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



//1.====用list实现队列
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





//1.=====队列来实现栈
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
//=====1.最小栈  : 只保存最小的值,不会将大于的值进入/内部是两个栈
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

//=====2.栈的弹出压入序列
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> st;
		int pushIdx = 0;
		int popIdx = 0;

		while (pushIdx<pushV.size()){

			//每次入栈一个元素
			st.push(pushV[pushIdx++]);
			//循环判断是否是要出栈的元素
			while (!st.empty() && st.top() == popV[popIdx]){
				st.pop();
				popIdx++;
			}
		}
		return st.empty();
	}
};

//=====3.逆波兰表达式
// atoi : 字符串转整数 stoi : string对象转整数
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const auto& str : tokens){

			//操作符判断
			if (str == "+" || str == "-"
				|| str == "*" || str == "/")
			{
				//遇到运算符则执行
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




//对于双端队列的实现
//将对应的数据进行分段式存储,在头部和尾部都可以进行数据的输入和输出
//通过创建多个存储空间来实现

//增容代价小
//1.数据的缓冲区满了,则开一个新的缓冲区,缓冲区的首地址存入指针数组
//2.指针数组满了,新开一个指针数组,只要拷贝原有的缓冲区的指针,不拷贝元素

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
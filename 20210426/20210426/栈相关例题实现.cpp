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
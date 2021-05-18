class CQueue {
	stack<int> stack1, stack2;
public:
	CQueue() {
		while (!stack1.empty()) {
			stack1.pop();
		}
		while (!stack2.empty()) {
			stack2.pop();
		}
	}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		// 如果第二个栈为空
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()) {
			return -1;
		}
		else {
			int deleteItem = stack2.top();
			stack2.pop();
			return deleteItem;
		}
	}
};


#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main(){

	string s;
	while (getline(cin, s)){

		map<string, int> m;
		string temp;
		for (int i = 0; i<s.size(); i++){

			if (s[i] == ' ' || s[i] == ',' || s[i] == '.'){

				if (temp != "")
					m[temp]++;
				temp = "";
			}
			else{

				temp += tolower(s[i]);
			}
		}
		for (auto it = m.begin(); it != m.end(); it++){

			cout << it->first << ":" << it->second << endl;
		}
	}
	return 0;
}

class Solution {

	struct Com{
		bool operator()(pair<string, int> &a, const pair<string, int> &b){
			if (a.second != b.second){
				return a.second>b.second;
			}
			else{
				return a.first<b.first;
			}
		}
	};

public:
	vector<string> topKFrequent(vector<string>& words, int k) {

		map<string, int> m;
		for (auto e : words)
			m[e]++;


		priority_queue<pair<string, int>, vector<pair<string, int>>, Com> q;


		for (auto e : m)
		{
			q.push(e);
			if (q.size() > k)
				q.pop();
		}


		vector<string> ret;
		while (!q.empty())
		{
			ret.push_back(q.top().first);
			q.pop();
		}


		reverse(ret.begin(), ret.end());
		return ret;
	}
};
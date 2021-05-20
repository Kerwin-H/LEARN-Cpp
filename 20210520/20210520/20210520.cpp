class Solution {
public:
	string replaceSpace(string s) {
		string a = "";
		for (int i = 0; i<s.length(); ++i){

			if (s[i] != ' ') a += s[i];
			else a += "%20";
		}
		return a;
	}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		while (head){

			v.push_back(head->val);
			head = head->next;
		}
		return vector<int>(v.rbegin(), v.rend());
	}
};
class CQueue {
	stack<int> stack1, stack2;
public:
	CQueue() {
		while (!stack1.empty()){
			stack1.pop();
		}
		while (!stack2.empty()){
			stack2.pop();
		}
	}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {

		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()){
			return -1;
		}
		else{
			int del = stack2.top();
			stack2.pop();
			return del;
		}
	}
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/

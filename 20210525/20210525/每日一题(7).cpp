class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> stk, stkl;
	MinStack() {

	}

	void push(int x) {
		stk.push(x);
		if (stkl.empty() || x <= stkl.top()) stkl.push(x);
	}

	void pop() {
		if (stk.top() == stkl.top()) stkl.pop();
		stk.pop();
	}

	int top() {
		return stk.top();
	}

	int min() {
		return stkl.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;       

		queue<TreeNode*> q;
		q.push(root);

		while (q.size())
		{
			int size = q.size();              
			vector<int> tmp;                 
			while (size--)                   
			{
				auto t = q.front();
				q.pop();

				tmp.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}

			res.push_back(tmp);
		}

		return res;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int moleVote = 0, res = 0;
		for (int i : nums){
			if (moleVote == 0){
				res = i;
			}
			moleVote += res == i ? 1 : -1;
		}
		return res;
	}
};

class Solution {
private:
	Node* cur = NULL;
	Node* ans;
public:
	Node* treeToDoublyList(Node* root) {
		if (!root)
			return root;
		Node* end = root;
		while (end->right)
		{
			end = end->right;
		}
		DFS(root);
		if (ans)
			ans->left = end;
		end->right = ans;
		return ans;
	}
	void DFS(Node* root)
	{
		if (!root)
			return;
		DFS(root->left);
		root->left = cur;
		if (cur)
			cur->right = root;
		if (!cur)
		{
			cur = root;
			ans = cur;
		}
		cur = root;
		DFS(root->right);
	}
};


class Solution {
public:
	vector<string> rec;
	vector<int> vis;

	void backtrack(const string& s, int i, int n, string& perm) {
		if (i == n) {
			rec.push_back(perm);
			return;
		}
		for (int j = 0; j < n; j++) {
			if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
				continue;
			}
			vis[j] = true;
			perm.push_back(s[j]);
			backtrack(s, i + 1, n, perm);
			perm.pop_back();
			vis[j] = false;
		}
	}

	vector<string> permutation(string s) {
		int n = s.size();
		vis.resize(n);
		sort(s.begin(), s.end());
		string perm;
		backtrack(s, 0, n, perm);
		return rec;
	}
};
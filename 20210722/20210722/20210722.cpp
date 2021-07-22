//输入字符串,输出其中的全排列
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

//找出只出现一次的数(数组内部)
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0, sub = 0; i < 32; ++i, sub = 0) {

			for (auto &n : nums) 
				sub += ((n >> i) & 1);

			if (sub % 3) 
				res |= (1 << i);
		}
		return res;
	}
};













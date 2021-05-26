class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> vec(k, 0);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; ++i) {
			vec[i] = arr[i];
		}
		return vec;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN, s = 0;
		for (auto x : nums)
		{
			if (s < 0) s = 0;
			s += x;
			res = max(res, s);
		}
		return res;
	}
};

class Solution {
public:
	char firstUniqChar(string s) {
		unordered_map<int, int> m;
		for (char ch : s) {
			++m[ch];
		}
		for (int i = 0; i < s.size(); ++i) {
			if (m[s[i]] == 1) {
				return s[i];
			}
		}
		return ' ';
	}
};

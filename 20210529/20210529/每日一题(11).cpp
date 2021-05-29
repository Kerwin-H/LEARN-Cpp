class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int l = 0; int r = nums.size() - 1;
		while (l < r) {
			if (target == nums[l] + nums[r]) {
				return vector<int>{nums[l], nums[r]};
			}
			else if (target > nums[l] + nums[r]) {
				l++;
			}
			else if (target < nums[l] + nums[r]) {
				r--;
			}
		}
		return vector<int>();
	}
};


class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> vec;
		vector<int> res;
		int sum = 0, limit = (target - 1) / 2; 
		for (int i = 1; i <= limit; ++i) {
			for (int j = i;; ++j) {
				sum += j;
				if (sum > target) {
					sum = 0;
					break;
				}
				else if (sum == target) {
					res.clear();
					for (int k = i; k <= j; ++k) {
						res.emplace_back(k);
					}
					vec.emplace_back(res);
					sum = 0;
					break;
				}
			}
		}
		return vec;
	}
};


class Solution {
public:
	string reverseWords(string s) {
		stack<char> word;
		string result = "";
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] != ' ') 
			{
				word.push(s[i]);
			}
			if (s[i] == ' ' || i == 0) 
			{
				bool flag = false;
				while (word.empty() == false)
				{
					result.push_back(word.top()); 
					word.pop();
					flag = true;
				}
				if (flag)
				{
					result += " ";
				}
			}
		}
		return result.substr(0, result.size() - 1); 
	}
};

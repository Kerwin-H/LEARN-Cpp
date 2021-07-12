struct Cmp {
	bool operator() (const string& s1, const string& s2) {
		if (s1[0] != s2[0]) return s1[0] < s2[0];
		return (s1 + s2).compare(s2 + s1) < 0;
	}
};

class Solution {
public:
	string minNumber(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return "";
		vector<string> str_arr;
		for (int num : nums) str_arr.push_back(to_string(num));
		string res = "";
		sort(str_arr.begin(), str_arr.end(), Cmp());
		for (string& str : str_arr) res += str;
		return res;
	}
};


class Solution {
public:
	int translateNum(int num) {
		string src = to_string(num);
		int p = 0, q = 0, r = 1;
		for (int i = 0; i < src.size(); ++i) {
			p = q;
			q = r;
			r = 0;
			r += q;
			if (i == 0) {
				continue;
			}
			auto pre = src.substr(i - 1, 2);
			if (pre <= "25" && pre >= "10") {
				r += p;
			}
		}
		return r;
	}
};

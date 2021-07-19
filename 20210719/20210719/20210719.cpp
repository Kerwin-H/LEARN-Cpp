class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1) { return s.length(); }

		int res = -1, right = 0;
		unordered_set<char> store;

		for (int left = 0; left < s.length(); ++left) {
			while (right < s.length() && !store.count(s[right])) {
				store.insert(s[right]);
				++right;
			}

			res = max(res, right - left);
			store.erase(s[left]);

			if (right >= s.length()) { break; }
		}

		return res;
	}
};


class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> factors = { 2, 3, 5 };
		unordered_set<long> seen;
		priority_queue<long, vector<long>, greater<long>> heap;
		seen.insert(1L);
		heap.push(1L);
		int ugly = 0;
		for (int i = 0; i < n; i++) {
			long curr = heap.top();
			heap.pop();
			ugly = (int)curr;
			for (int factor : factors) {
				long next = curr * factor;
				if (!seen.count(next)) {
					seen.insert(next);
					heap.push(next);
				}
			}
		}
		return ugly;
	}
};

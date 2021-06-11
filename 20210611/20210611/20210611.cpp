class Solution{

public:
	string reverseLeftWords(string s, int n) {
	
		reverse(s, 0, n - 1);
		reverse(s, n, s.size() - 1);
		reverse(s, 0, s.size() - 1);
		return s;
	}

	void reverse(string& str,int begin,int end){
		
		char tmp;
		while (begin < end){
			
			tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			++begin;
			--end;
		}
	}
};

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int king = 0;
		for (int i = 0; i < nums.size() - 1; i++) {

			if (nums[i] == 0) {
				king++;
				continue;
			}

			if (nums[i] == nums[i + 1])
				return false;

			if (nums[i + 1] == nums[i] + 1)
				continue;

			if (nums[i + 1] > nums[i] + 1) {
				king -= nums[i + 1] - nums[i] - 1;
				if (king < 0)
					return false;
			}
		}
		return true;
	}
};

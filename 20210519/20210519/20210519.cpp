class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i<n; ++i){
			for (int j = i + 1; j<n; ++j){
				if (nums[i] + nums[j] == target){
					return{ i, j };
				}
			}
		}
		return{};
	}
};

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int i = 0;
		while (i<nums.size()){

			if (nums[i] == i){
				i++;
				continue;
			}

			if (nums[i] == nums[nums[i]])
				return nums[i];
			swap(nums[i], nums[nums[i]]);
		}
		return -1;
	}
};

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int i = matrix.size() - 1;
		int j = 0;
		while (i >= 0 && j<matrix[0].size()){

			if (matrix[i][j]>target) i--;
			else if (matrix[i][j]<target) j++;
			else
				return true;
		}
		return false;
	}
};
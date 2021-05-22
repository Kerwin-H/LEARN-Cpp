class Solution {
public:
	vector<int> printNumbers(int n) {
		int max = 0;
		vector<int> v;
		while (n--){
			max += std::pow(10, n) * 9;
		}
		for (int i = 1; i <= max; ++i){
			v.push_back(i);
		}
		return v;
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
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val)
		{
			return head->next;
		}
		ListNode *cur = head;
		ListNode *prev = head;
		while (cur->val != val)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		return head;
	}
};


class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			if ((nums[left] & 1) != 0) {
				left++;
				continue;
			}
			if ((nums[right] & 1) != 1) {
				right--;
				continue;
			}
			swap(nums[left++], nums[right--]);
		}
		return nums;
	}
};

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto p = headA, q = headB;
		while (p != q)
		{
			if (p) p = p->next;
			else p = headB;
			if (q) q = q->next;
			else q = headA;
		}
		return q;
	}
};

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int ret = 0;
		if (n == 0)
			return 0;

		for (int i = 0; i<n; ++i){

			if (nums[i] == target)
				ret++;
		}
		return ret;
	}
};

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int ans;
		for (int i = 0; i<nums.size(); i++){
			if (i != nums[i]){
				ans = i;
				break;
			}
		}
		return ans;
	}
};

class Solution {
public:
	int minPairSum(vector<int>& nums) {
		int n = nums.size();
		int res = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n / 2; ++i) {
			res = max(res, nums[i] + nums[n - 1 - i]);
		}
		return res;
	}
};



class Solution {
private:
	int f[10000000 + 7];
	int maxdis[10000000 + 7];
public:
	int minJump(vector<int>& jump) {
		int n = jump.size();
		int w = 0;
		int ans = 1000000000;

		for (int i = 1; i <= n; ++i) {
			f[i] = 1000000000;
			maxdis[i] = 0;
		}
		f[1] = 0;
		maxdis[0] = 1;

		for (int i = 1; i <= n; ++i) {
			if (i > maxdis[w]) { // ���µ���ָ��
				++w;
			}
			f[i] = min(f[i], w + 1); // �� maxdis[w] ���� f[i]
			int next = i + jump[i - 1]; // ��һ����Ծ����

			if (next > n) {
				ans = min(ans, f[i] + 1);
			}
			else if (f[next] > f[i] + 1) {
				f[next] = f[i] + 1;
				maxdis[f[next]] = max(maxdis[f[next]], next);
			}
		}

		return ans;
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
		ListNode* DummyHead = new ListNode(-1);
		DummyHead->next = head;
		ListNode* cur = DummyHead;
		while (cur->next)
		{
			if (cur->next->val == val)
			{
				cur->next = cur->next->next;
				break;
			}
			cur = cur->next;
		}
		return DummyHead->next;
	}
};















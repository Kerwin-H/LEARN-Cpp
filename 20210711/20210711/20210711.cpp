/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//两个链表相加
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = 1;
		int len2 = 1;
		ListNode* p = l1;
		ListNode* q = l2;
		while (p->next != NULL)
		{
			len1++;
			p = p->next;
		}
		while (q->next != NULL)
		{
			len2++;
			q = q->next;
		}
		if (len1>len2)
		{
			for (int i = 1; i <= len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
		}
		else
		{
			for (int i = 1; i <= len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}
		}
		p = l1;
		q = l2;
		bool count = false;
		ListNode* l3 = new ListNode(-1);
		ListNode* w = l3;
		int i = 0;
		while (p != NULL&&q != NULL)
		{
			i = count + p->val + q->val;
			w->next = new ListNode(i % 10);
			count = i >= 10 ? true : false;
			w = w->next;
			p = p->next;
			q = q->next;
		}
		if (count)
		{
			w->next = new ListNode(1);
			w = w->next;
		}
		return l3->next;
	}
};



//最长回文子串
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;

		vector<vector<int>> dp(n, vector<int>(n));

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for (int L = 2; L <= n; L++) {	
			for (int i = 0; i < n; i++) {
				int j = L + i - 1;
				if (j >= n) {
					break;
				}
				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};

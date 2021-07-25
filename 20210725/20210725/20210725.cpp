//两串链表相加,形成新的链表,数字对应
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* head = new ListNode(-1);
		ListNode* h = head;
		int sum = 0;
		bool carry = false;

		while (l1 != NULL || l2 != NULL){

			sum = 0;
			if (l1 != NULL){

				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL){

				sum += l2->val;
				l2 = l2->next;
			}
			if (carry)
				sum++;
			h->next = new ListNode(sum % 10);
			h = h->next;
			carry = sum >= 10 ? true : false;
		}
		if (carry){

			h->next = new ListNode(1);
		}
		return head->next;
	}
};


//找出最长的回文子串
class Solution {
public:
	pair<int, int> expandAroundCenter(const string& s, int left, int right) {

		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return{ left + 1, right - 1 };
	}

	string longestPalindrome(string s) {
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i) {

			auto[left1, right1] = expandAroundCenter(s, i, i);
			auto[left2, right2] = expandAroundCenter(s, i, i + 1);
			if (right1 - left1 > end - start) {

				start = left1;
				end = right1;
			}
			if (right2 - left2 > end - start) {

				start = left2;
				end = right2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};

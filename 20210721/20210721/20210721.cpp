class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		// 排除输入是空指针和k<=0无意义
		if (head == nullptr || k <= 0)
			return nullptr;
		ListNode* fast = head, *slow = head;
		for (int i = 0; i < k; i++){
			// 排除k值大于链表长的情况
			if (fast == nullptr)
				return nullptr;
			fast = fast->next;
		}
		while (fast != nullptr){
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

class Solution {
	// 计算 x 的数位之和
	int get(int x) {
		int res = 0;
		for (; x; x /= 10) {
			res += x % 10;
		}
		return res;
	}
public:
	int movingCount(int m, int n, int k) {
		if (!k) return 1;
		queue<pair<int, int> > Q;
		// 向右和向下的方向数组
		int dx[2] = { 0, 1 };
		int dy[2] = { 1, 0 };
		vector<vector<int> > vis(m, vector<int>(n, 0));
		Q.push(make_pair(0, 0));
		vis[0][0] = 1;
		int ans = 1;
		while (!Q.empty()) {
			auto[x, y] = Q.front();
			Q.pop();
			for (int i = 0; i < 2; ++i) {
				int tx = dx[i] + x;
				int ty = dy[i] + y;
				if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
				Q.push(make_pair(tx, ty));
				vis[tx][ty] = 1;
				ans++;
			}
		}
		return ans;
	}
};

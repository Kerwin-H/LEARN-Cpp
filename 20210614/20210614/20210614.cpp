class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		rows = board.size();
		cols = board[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (dfs(board, word, i, j, 0)) return true;
			}
		}
		return false;
	}
private:
	int rows, cols;
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
		if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
		if (k == word.size() - 1) return true;
		board[i][j] = '\0';
		bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
			dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
		board[i][j] = word[k];
		return res;
	}
};


class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		int res = 0;
		queue<vector<int>> que;
		que.push({ 0, 0, 0, 0 });
		while (que.size() > 0) {
			vector<int> x = que.front();
			que.pop();
			int i = x[0], j = x[1], si = x[2], sj = x[3];
			if (i >= m || j >= n || k < si + sj || visited[i][j]) continue;
			visited[i][j] = true;
			res++;
			que.push({ i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj });
			que.push({ i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8 });
		}
		return res;
	}
};

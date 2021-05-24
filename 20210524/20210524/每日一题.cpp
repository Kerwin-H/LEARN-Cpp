/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		// 考虑为空情况
		if (root == nullptr)
		{
			return nullptr;
		}
		// left 和 right 反序, 临时保存left结点
		TreeNode* temp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(temp);
		return root;
	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		// 空的是对称的
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return dfs(root->left, root->right);
		}
	}

	// 判断左右是否相同的递归函数实现
	bool dfs(TreeNode* left, TreeNode* right)
	{
		if (left == nullptr && right == nullptr)
		{
			return true;
		}

		if (left == nullptr || right == nullptr || left->val != right->val)
		{
			return false;
		}

		return dfs(left->left, right->right) && dfs(left->right, right->left);
	}
};


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return{};
		//上下左右边界
		int top = 0, bottom = matrix.size() - 1;
		int left = 0, right = matrix[0].size() - 1;
		vector<int> res;
		//顺时针打印
		while (true){
			//top 从左到右
			for (int i = left; i <= right; ++i){
				res.push_back(matrix[top][i]);
			}
			++top;
			if (top>bottom) break;
			//right 从上到下
			for (int i = top; i <= bottom; ++i){
				res.push_back(matrix[i][right]);
			}
			--right;
			if (right<left) break;
			//bottom 从右到左
			for (int i = right; i >= left; --i){
				res.push_back(matrix[bottom][i]);
			}
			--bottom;
			if (bottom<top) break;
			//left 从下到上
			for (int i = bottom; i >= top; --i){
				res.push_back(matrix[i][left]);
			}
			++left;
			if (left>right) break;
		}
		return res;
	}
};


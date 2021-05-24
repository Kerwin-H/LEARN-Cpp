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
		// ����Ϊ�����
		if (root == nullptr)
		{
			return nullptr;
		}
		// left �� right ����, ��ʱ����left���
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
		// �յ��ǶԳƵ�
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return dfs(root->left, root->right);
		}
	}

	// �ж������Ƿ���ͬ�ĵݹ麯��ʵ��
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
		//�������ұ߽�
		int top = 0, bottom = matrix.size() - 1;
		int left = 0, right = matrix[0].size() - 1;
		vector<int> res;
		//˳ʱ���ӡ
		while (true){
			//top ������
			for (int i = left; i <= right; ++i){
				res.push_back(matrix[top][i]);
			}
			++top;
			if (top>bottom) break;
			//right ���ϵ���
			for (int i = top; i <= bottom; ++i){
				res.push_back(matrix[i][right]);
			}
			--right;
			if (right<left) break;
			//bottom ���ҵ���
			for (int i = right; i >= left; --i){
				res.push_back(matrix[bottom][i]);
			}
			--bottom;
			if (bottom<top) break;
			//left ���µ���
			for (int i = bottom; i >= top; --i){
				res.push_back(matrix[i][left]);
			}
			++left;
			if (left>right) break;
		}
		return res;
	}
};


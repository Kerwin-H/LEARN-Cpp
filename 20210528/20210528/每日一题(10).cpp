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
	vector<int> res;

	void dfs(TreeNode* root)
	{
		if (!root) return;

		dfs(root->left);
		res.push_back(root->val);
		dfs(root->right);
	}

	int kthLargest(TreeNode* root, int k) {
		dfs(root);

		reverse(res.begin(), res.end());

		return res[k - 1];
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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		return left>right ? left + 1 : right + 1;
	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root) {
			return true;
		}

		return depth(root) != -1;
	}

	int depth(TreeNode* root) {
		if (!root) {
			return 0;
		}

		int leftDepth = depth(root->left);
		if (leftDepth == -1) {
			return -1;
		}


		int rightDepth = depth(root->right);
		if (rightDepth == -1) {
			return -1;
		}

		if (abs(leftDepth - rightDepth) > 1) {
			return -1;
		}

		return max(leftDepth, rightDepth) + 1;
	}
};
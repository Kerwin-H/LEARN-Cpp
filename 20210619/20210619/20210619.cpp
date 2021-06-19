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
	bool hasSubTree(TreeNode* A, TreeNode* B) {
		if (B == nullptr),
			return true;
		if (A == nullptr || A->val != B->val)
			return false;
		return hasSubTree(A->left, B->left) && hasSubTree(A->right, B->right);
	}

	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;
		bool ret = false;
		if (A->val == B->val)
			ret = hasSubTree(A, B);
		if (ret == false)
			ret = isSubStructure(A->left, B) || isSubStructure(A->right, B);
		return ret;
	}
};

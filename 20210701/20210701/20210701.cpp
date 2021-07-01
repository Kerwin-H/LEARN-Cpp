/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) return nullptr;
		Node *cur = head;
		unordered_map<Node*, Node*> map;

		while (cur != nullptr) {
			map[cur] = new Node(cur->val);
			cur = cur->next;
		}
		cur = head;

		while (cur != nullptr) {
			map[cur]->next = map[cur->next];
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}

		return map[head];
	}
};

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
class Solution {
public:
	vector<Node*> s;
	void dfs(Node* root){
		if (root != nullptr){
			dfs(root->left);
			s.emplace_back(root);
			dfs(root->right);
		}
	}

	Node* treeToDoublyList(Node* root) {
		dfs(root);
		int n = s.size();
		if (n == 0) return nullptr;
		for (int i = 0; i < n - 1; ++i){
			s[i]->right = s[i + 1];
			s[i + 1]->left = s[i];
		}
		s[0]->left = s[n - 1];
		s[n - 1]->right = s[0];
		return s[0];
	}
};

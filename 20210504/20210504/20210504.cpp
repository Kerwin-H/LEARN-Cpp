#include<iostream>
using namespace std;

//二叉搜索树: 概念理解

template <class T>
struct BNode{

	T _data;
	typedef BNode<T> Node;
	Node* _left;
	Node* _right;

	BNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class T>
class BTree{

public:
	typedef BNode<T> Node;	//定义BNode对应的别名Node

	Node* find(const T& val){

		Node* cur = _root;
		while (cur){

			if (cur->_data == val)
				return cur;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root){

		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_data);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}

	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}

	//不插入重复的值
	bool insert(const T& val){

		if (_root == nullptr){

			_root = new Node(val);
			return true;
		}

		//搜索找到合适的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){

			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}

	void inorder(){

		_inorder(_root);
	}

	//搜索树的中序遍历有序
	void _inorder(Node* root){

		if (root){

			_inorder(root->_left);
			cout << root->_data << " ";
			_inorder(root->_right);
		}
	}

	void destory(Node* root){

		if (root){

			destory(root->_left);
			destory(root->_right);
			delete root;
		}
	}

	~BTree(){

		if (_root){

			destory(_root);
			_root = nullptr;
		}
	}


private:
	Node* _root;
};

void test(){

	BTree<int> b;
	b.insert(2);
	b.insert(5);
	b.insert(8);
	b.insert(7);
	b.insert(1);


}


int main(){

	test();

	system("pause");
	return 0;
}
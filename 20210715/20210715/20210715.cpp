
template <class K, class V>
struct BNode{


	K _key;
	V _value;
	typedef BNode<K, V> Node;
	Node* _left;
	Node* _right;

	BNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BTree{

public:
	typedef BNode<K, V> Node;

	Node* find(const K& key){

		Node* cur = _root;
		while (cur){

			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return cur;
	}


	Node* copy(Node* root){

		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_key, root->_value);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}

	BTree(const BTree<K, V>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}


	bool insert(const K& key, const V& value){

		if (_root == nullptr){

			_root = new Node(key, value);
			return true;
		}


		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){

			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(key, value);
		if (parent->_key > key)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}

	void inorder(){

		_inorder(_root);
		cout << endl;
	}


	void _inorder(Node* root){

		if (root){

			_inorder(root->_left);
			cout << root->_key << "-->" << root->_value << " ";
			_inorder(root->_right);
		}
	}

	void destory(Node* root){

		if (root){

			destory(root->_left);
			destory(root->_right);
			cout << "destory:" << root->_key << "-->" << root->_value << endl;
			delete root;
		}
	}

	~BTree(){

		if (_root){

			destory(_root);
			_root = nullptr;
		}
	}

	bool erase(const K& key){


		Node* cur = _root;
		Node* parent = nullptr;

		while (cur){

			if (cur->_key == key)
				break;
			parent = cur;
			if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}


		if (cur == nullptr)
			return false;


		if (cur->_left == nullptr&&cur->_right == nullptr){


			if (cur == _root){

				_root == nullptr;
			}
			else{

				if (parent->_left == cur)
					parent->_left == nullptr;
				else
					parent->_right = nullptr;
			}

			delete cur;
		}

		else if (cur->_left == nullptr){

			if (cur == _root){


				_root = cur->_right;
			}
			else{

				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}

			delete cur;
		}

		else if (cur->_right == nullptr){

			if (cur == _root){

				_root = cur->_left;
			}
			else{

				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}

			delete cur;
		}

		else{

			Node* leftRightMost = cur->_left;
			parent = cur;

			while (leftRightMost->_right){

				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);

			if (parent->_left == leftRightMost)
				parent->_left = leftRightMost->_left;
			else
				parent->_right = leftRightMost->_left;

			delete leftRightMost;
		}
		return true;
	}

private:
	Node* _root;
};

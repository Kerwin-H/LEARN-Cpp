#include<iostream>
#include<utility>
using namespace std;

enum COLOR{

	BLACK,
	RED
};

template <class V>
struct RBNode{

	RBNode<V>* _parent;
	RBNode<V>* _left;
	RBNode<V>* _right;

	V _val;

	COLOR _color;

	RBNode(const V& val = V())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _color(RED)
	{}
};

template<class V>
struct RBTreeIterator{

	typedef RBNode<V> Node;
	typedef RBTreeIterator<V> Self;

	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{}

	//解引用:*,->
	V& operator*(){

		return _node->_val;
	}

	V* operator->(){

		return &_node->_val;
	}

	bool operator!=(const Self& it){

		return _node != it._node;
	}

	//中序遍历
	Self& operator++(){

		if (_node->_right){

			//右子树的最左节点
			_node = _node->_right;
			while (_node->_left){

				_node = _node->_left;
			}
		}
		else{
			Node* parent = _node->_parent;
			while (_node == parent->_right){

				_node = parent;
				parent = parent->_parent;
			}
			//避免没有右子树的情况
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}

	Self& operator--(){

		if (_node->_left){

			//左子树的最右节点
			_node = _node->_left;
			while (_node->_right){

				_node = _node->_right;
			}
		}
		else{

			Node* parent = _node->_parent;
			while (_node == parent->_left){

				_node = parent;
				parent = parent->_parent;
			}
			//避免没有左子树的情况
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}
};

//KeyOfValue: 通过v获取对应的K
template<class K, class V, class KeyOfValue>
class RBTree{

public:
	typedef RBNode<V> Node;	//定义别名

	typedef RBTreeIterator<V> iterator;

	RBTree()
		:_header(new Node)
	{
		//创建空树
		_header->_left = _header->_right = _header;
	}

	iterator begin(){

		return iterator(_header->_left);
	}

	iterator end(){

		return iterator(_header);
	}

	iterator rbegin(){

		return iterator(_header->_right);
	}


	//bool insert(const V& val)
	pair<iterator, bool> insert(const V& val)
	{
		//1.搜索树的插入
		if (_header->_parent == nullptr){

			//创建对应的根节点
			Node* root = new Node(val);

			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;

			//改变根节点的颜色
			root->_color = BLACK;
			//return true;
			return make_pair(iterator(root), true);
		}

		Node* cur = _header->_parent;
		Node* parent = nullptr;

		KeyOfValue kov;
		while (cur){

			parent = cur;

			//if (cur->_val.first ==val.first)
			if (kov(cur->_val) == kov(val))
			{
				//return false;
				return make_pair(iterator(cur), false);
			}
			//else if (cur->_val.first > val.first)
			else if (kov(cur->_val)>kov(val))
			{
				cur = cur->_left;
			}
			else{
				cur = cur->_right;
			}
		}
		//创建要插入的节点
		cur = new Node(val);
		Node* node = cur;
		if (kov(parent->_val) > kov(cur->_val))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//2.修改颜色或者调整结构(看有无红色连续节点)
		while (cur != _header->_parent && cur->_parent->_color == RED){

			parent = cur->_parent;
			Node* gfather = parent->_parent;

			if (gfather->_left == parent){

				Node* uncle = gfather->_right;
				//1.uncle存在,且为红色
				if (uncle&&uncle->_color == RED){

					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续更新
					cur = gfather;
				}
				else{

					//判断是否是双旋的场景
					if (cur == parent->_right){

						//左旋
						RotateL(parent);
						//交换cur,parent指向,退化成右旋的场景
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else{
				//gfather->right=parent
				Node* uncle = gfather->_left;
				if (uncle&&uncle->_color == RED){

					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else{

					if (cur == parent->_left){

						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);

					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		//根节点颜色改为黑色
		_header->_parent->_color = BLACK;
		//更新header的左右指向
		_header->_left = leftMost();
		_header->_right = rightMost();

		//return true;
		return make_pair(iterator(node), true);
	}


	void RotateL(Node* parent){

		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		//判断根节点
		if (parent == _header->_parent){

			_header->_parent = subR;
			subR->_parent = _header;
		}
		else{

			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		parent->_parent = subR;
	}

	void RotateR(Node* parent){

		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		//判断根
		if (parent == _header->_parent){

			_header->_parent = subL;
			subL->_parent = _header;
		}
		else{

			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		parent->_parent = subL;
	}

	Node* leftMost(){

		Node* cur = _header->_parent;
		while (cur&&cur->_left){

			cur = cur->_left;
		}
		return cur;
	}

	Node* rightMost(){

		Node* cur = _header->_parent;
		while (cur&&cur->_right){

			cur = cur->_right;
		}
		return cur;
	}

	void inorder(){

		_inorder(_header->_parent);
		cout << endl;
	}

	void _inorder(Node* root){

		if (root){

			_inorder(root->_left);
			cout << root->_kv.first << " ";
			_inorder(root->_right);
		}
	}


	//1.根: 黑色
	//2.每条路径的给色数目相同
	//3.红色的不能连续
	bool isBalance(){

		if (_header->_parent == nullptr)
			return true;

		Node* root = _header->_parent;

		if (root->_color == RED)
			return false;
		//统计一条路径上黑色节点的个数
		int bCount = 0;
		Node* cur = root;
		while (cur){

			if (cur->_color == BLACK)
				++bCount;
			cur = cur->_left;
		}
		cout << "bCount: " << bCount << endl;
		//遍历每一条路径
		int curBCount = 0;
		return _isBalance(root, bCount, curBCount);
	}

	bool _isBalance(Node* root, int& bCount, int curBCount){

		//当root为空,则一条路径遍历结束
		if (root == nullptr){

			//判断黑色节点个数是否相同
			if (curBCount != bCount)
				return false;
			else
				return true;
		}

		//判断节点是否为黑色
		if (root->_color == BLACK)
			++curBCount;

		//判断是否存在红色连续的节点
		if (root->_parent&&root->_color == RED
			&&root->_parent->_color == RED)
		{
			cout << "data: " << root->_kv.first << endl;
			return false;
		}

		return _isBalance(root->_left, bCount, curBCount)
			&& _isBalance(root->_right, bCount, curBCount);
	}


private:
	Node* _header;
};


//========引入第三方的类模板来初始化不同的容器


template<class K, class T>
class Map{
	//通过这里的传值来体现map和set的不同
	struct MapKeyOfValue{
		const K& operator()(const pair<K, T>& val){

			return val.first;
		}
	};

public:

	typedef typename RBTree<K, pair<K, T>, MapKeyOfValue>::iterator iterator;

	pair<iterator, bool> insert(const pair<K, T>& kv)
	{
		return _rbt.insert(kv);
	}

	iterator begin(){

		return _rbt.begin();
	}

	iterator end(){

		return _rbt.end();
	}

	iterator rbegin(){

		return _rbt.rbegin();
	}

	T& operator[](const K& key){

		pair<iterator, bool> ret = _rbt.insert(make_pair(key, T()));
		return ret.first->second;
	}

private:
	typedef RBTree<K, pair<K, T>, MapKeyOfValue> rbt;
	rbt _rbt;
};

template<class K>
class Set{

	struct SetKeyOfValue{
		const K& operator()(const K& val){

			return val;
		}
	};
public:

	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;

	pair<iterator, bool> insert(const K& val){

		return _rbt.insert(val);
	}
private:
	typedef RBTree<K, K, SetKeyOfValue> rbt;
	rbt _rbt;
};


void test(){

	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(4, 1));
	m.insert(make_pair(3, 1));

	m[9] = 1;
	m[2] = 5;

	//Map<int, int>::iterator it = m.begin();
	Map<int, int>::iterator it = m.rbegin();
	while (it != m.end()){

		cout << it->first << " " << it->second << endl;
		//++it;
		--it;
	}


	/*Set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);*/



}


int main(){

	test();

	system("pause");
	return 0;
}
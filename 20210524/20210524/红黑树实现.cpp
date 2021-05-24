#include<iostream>
#include<utility>
using namespace std;

enum COLOR{ 

	BLACK,
	RED
};

template <class K,class V>
struct RBNode{

	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	pair<K, V> _kv;

	COLOR _color;

	RBNode(const pair<K, V>& kv = pair<K, V>())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		, _color(RED)
	{}
};

template<class K,class V>
class RBTree{

public:
	typedef RBNode<K, V> Node;	//定义别名

	RBTree()
		:_header(new Node)
	{
		//创建空树
		_header->_left = _header->_right = _header;  
	}

	bool insert(const pair<K, V>& kv){
		
		//1.搜索树的插入
		if (_header->_parent == nullptr){
			
			//创建对应的根节点
			Node* root = new Node(kv);
		
			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;

			//改变根节点的颜色
			root->_color = BLACK;
			return true;
		}

		Node* cur = _header->_parent;
		Node* parent = nullptr;
		while (cur){
			
			parent = cur;

			if (cur->_kv.first == kv.first){
				
				return false;
			}
			else if (cur->_kv.first > kv.first){
				
				cur = cur->_left;
			}
			else{
				cur = cur->_right;
			}
		}
		//创建要插入的节点
		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first)
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


void test(){
	
	RBTree<int, int> r; 
	int n;
	cin >> n;
	for (int i = n; i > 0; --i){
		
		r.insert(make_pair(i, i));
	}
	r.inorder();
	cout << r.isBalance() << endl;
}


//void test(){
//	
//
//	RBTree<int, int> r;
//	r.insert(make_pair(10, 10));
//	r.insert(make_pair(15, 15));
//	r.insert(make_pair(5, 5));
//	r.insert(make_pair(1, 40));
//	r.insert(make_pair(16, 10));
//}



int main(){
	
	test();

	system("pause");
	return 0;
}
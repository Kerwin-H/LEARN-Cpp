#include<iostream>
#include<time.h>
using namespace std;

template<class T>
struct AVLNode{

	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	//平衡因子
	int _bf;

	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)
	{}
};

template<class T>
class AVLTree{

public:
	typedef AVLNode<T> Node;

	bool insert(const T& val){

		//二叉搜索树
		if (_root == nullptr){

			_root = new Node(val);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){

			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;

		//调整,从parent开始
		while (parent){

			//更新parent的平衡因子
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if (parent->_bf == 0)	//parent短的子树高度+1
				break;
			else if (parent->_bf == 1 || parent->_bf == -1){

				//继续向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2){

				if (parent->_bf == -2 && cur->_bf == -1){

					//左边的左边高,则右旋
					RotateR(parent);
				}

				else if (parent->_bf == 2 && cur->_bf == 1){

					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1){

					Node* subLR = cur->_right;
					int bf = subLR->_bf;

					RotateL(cur);
					RotateR(parent);

					if (bf == 1){

						parent->_bf = 0;
						cur->_bf = -1;
					}
					else if (bf == -1){

						parent->_bf = 1;
						cur->_bf = 0;
					}
				}
				else if (parent->_bf == 2 && cur->_bf == -1){

					//先将subRL对应的bf获取
					Node* subRL = cur->_left;
					int bf = subRL->_bf;

					RotateR(cur);
					RotateL(parent);

					//在发生右左双旋后,对应的子节点的bf值可能会不同,需要更新
					//这里运用判断的方式来区分所挂的节点在那一个位置,然后再进行对应bf的更新
					if (bf == 1){

						cur->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1){

						cur->_bf = 1;
						parent->_bf = 0;
					}
				}
				break;
			}
		}
		return true;
	}


	void RotateR(Node* parent){

		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		if (subLR)
			subLR->_parent = parent;
		//判断parent是否是根节点
		if (parent == _root){

			//根节点
			_root = subL;
			subL->_parent = nullptr;
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

		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent){

		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root){

			_root = subR;
			subR->_parent = nullptr;
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
		parent->_bf = subR->_bf = 0;
	}

	void inorder(){
		
		_inorder(_root);
		cout << endl;
	}

	void _inorder(Node* root){
		
		if (root){
			
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}

	int Height(Node* root){
		
		if (root == nullptr)
			return 0;

		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root){
		
		if (root == nullptr)
			return true;

		//查看平衡因子是否和左右子树高度差一致
		int left = Height(root->_left);
		int right = Height(root->_right);
		if (right - left != root->_bf){
			
			cout << " Node: " << root->_val << " bf:"
				<< root->_bf << " height gap: " << right - 1;
			return false;
		}

		return abs(root->_bf) < 2
			&& _isBalance(root->_left)
			&& _isBalance(root->_right);
	}

	bool isBalance(){
		
		return _isBalance(_root);
	}

private:
	Node* _root = nullptr;
};
//
//void test(){
//	
//	AVLTree<int> avl;
//	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	//int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < num; ++i){
//		
//		avl.insert(arr[i]);
//	}
//	avl.inorder();
//	cout << avl.isBalance() << endl;
//}

void test(){
	
	srand(time(nullptr));
	cout << "num : " << endl;
	int num;
	cin >> num;
	AVLTree<int> avl;
	for (int i = 0; i < num; ++i){
		
		avl.insert(rand());
	}
	avl.inorder();
	cout << avl.isBalance() << endl;
}


//void test(){
//
//	AVLTree<int> a;
//	a.insert(1);
//	a.insert(0);
//	a.insert(5);
//	a.insert(-1);
//	a.insert(0.3);
//	a.insert(3);
//	a.insert(10);
//	a.insert(-10);
//	a.insert(-0.5);
//	a.insert(0.2);
//	a.insert(0.4);
//	a.insert(2);
//	a.insert(4);
//	a.insert(6);
//	a.insert(15);
//	a.insert(-11);
//	a.insert(0.1);
//	a.insert(1.9);
//	a.insert(2.1);
//	a.insert(4.5);
//	a.insert(20);
//
//}

int main(){

	test();

	system("pause");
	return 0;
}
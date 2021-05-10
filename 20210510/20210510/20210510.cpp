#include<iostream>
using namespace std;

//����������: �������

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
	typedef BNode<T> Node;	//����BNode��Ӧ�ı���Node

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

	//�������������������ݺͽṹ
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

	//�������ظ���ֵ
	bool insert(const T& val){

		if (_root == nullptr){

			_root = new Node(val);
			return true;
		}

		//�����ҵ����ʵ�λ��
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

	//�������������������
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

	bool erase(const T& val){
		
		//����
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){
			
			if (cur->_data == val)
				break;
			parent = cur;
			if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//�ж��Ƿ��ҵ���Ҫɾ���Ľڵ�
		if (cur == nullptr)
			return false;

		//ɾ��
		//1.ɾ����ΪҶ�ӽڵ�
		if (cur->_left == nullptr&&cur->_right == nullptr){
			
			//�ж��Ƿ��Ǹ��ڵ�
			if (cur == _root){
				
				_root = nullptr;
			}
			else{
				
				//�ж���Ҫɾ���Ľڵ��ڸ��ڵ����һ��
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			//ɾ���ڵ�
			delete cur;
		}

		//2.��Ҷ�ӽڵ�
		else if (cur->_left == nullptr){
			
			//�ж�ɾ���Ƿ�Ϊ���ڵ�
			if (cur == _root){
				
				//����
				_root = cur->_right;
			}
			else{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			//ɾ���ڵ�
			delete cur;
		}
		else if (cur->_right == nullptr){
		
			if (cur->_right == _root){
				
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
			
			//��������������
			//1.�����������������ҽڵ�
			Node* leftRightMost = cur->_left;
			parent = cur;

			while (leftRightMost->_right){
				
				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			//2.����
			swap(cur->_data, leftRightMost->_data);

			//3.ɾ�����ҽڵ�
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

void test(){

	BTree<int> b;
	b.insert(5);
	b.insert(3);
	b.insert(7);
	b.insert(1);
	b.insert(4);
	b.insert(6);
	b.insert(8);
	b.insert(0);
	b.insert(2);
	b.insert(9);

	

	b.erase(5);
	b.inorder();
	cout << endl;
	b.erase(3);
	b.inorder();
	cout << endl;
	b.erase(8);
	b.inorder();
	cout << endl;
	b.erase(9);
	b.inorder();
	cout << endl;
}


int main(){

	test();

	system("pause");
	return 0;
}
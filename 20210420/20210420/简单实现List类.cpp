#include<string> 
using namespace std;
//list的实现:双向带头循环链表

template <class T>
struct ListNode{	//将函数的私有类封装成一个简单的节点

	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}

};


template<class T>
class List{

public:
	typedef ListNode<T> Node;
	typedef Node* pNode;

	List()
		:_header(new Node())
	{	//对于一个简单的list的创建,要让其内部的两个指针指向自己,才能完成初始化

		_header->_next = _header->_prev = _header;
	}

	List(size_t n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;

		for (size_t i = 0; i < n; ++i){

			pushBack(val);
		}
	}

	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		while (first != last){

			pushBack(*first);
			++first;
		}
	}


	void pushBack(const T& val){

		Node* prev = _header->_prev;
		Node* newNode = new Node(val);

		prev->_next = newNode;	//和上一个元素之间的指向
		newNode->_prev = prev;

		newNode->_next = _header; //和下一个元素,也就是对应的头结点之间的指向
		_header->_prev = newNode;
	}

	~List(){

		if (_header){

			Node* node = _header->_next;
			while (node != _header){

				Node* next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}



private:
	ListNode<T>* _header;
};



void test(){

	List<int>lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);

	List<int>lst2((size_t)10, 5);

	string str = "123456";
	List<char>lst3(str.begin(), str.end());

}

int main(){

	test();

	return 0;
}
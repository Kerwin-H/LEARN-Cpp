#include<iostream>
#include<vector>
#include<string>
using namespace std;
template <class T>
struct ListNode{

	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		: _data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};


template <class T>
class List{

public:
	typedef ListNode<T>Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*>iterator;
	typedef ListIterator<T, const T&, const T*>const_iterator;

	iterator begin(){
		return iterator(_header->_next;)
	}

	const_iterator begin() const{
		return const_iterator(_header->_next);
	}

	iterator end(){
		return iterator(_header);
	}

	const_iterator end() const{
		return const_iterator(_header);
	}

	List()
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
	}

	List(int n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (int i = 0; i < n; ++i){
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
		
		//

		insert(end(), val);
	}

	void pushFront(const T& val){
		insert(begin(), val);
	}

	void insert(iterator pos, const T& val){
		
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		pNode newNode = new Node(val);

		prev->_next = newNode;
		newNode->_prev = prev;

		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator erase(iterator pos){
		
		//判断是否是end迭代器
		if (pos != end()){
			
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;

			delete cur;

			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}
		return pos;
	}

	~List(){

		if (_header){
			//释放每一个节点的空间
			pNode node = _header->_next;
			while (node != _header){
				
				pNode next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}


private:
	pNode _header;

};
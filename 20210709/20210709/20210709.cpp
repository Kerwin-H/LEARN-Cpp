#include<string> 
using namespace std;


template <class T>
struct ListNode{			
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

private:
	ListNode<T>* _header;		


public:	

	typedef ListNode<T> Node;
	typedef Node* pNode;

	List()	
		:_header(new Node())
	{	

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

		prev->_next = newNode;	
		newNode->_prev = prev;

		newNode->_next = _header; 
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
};

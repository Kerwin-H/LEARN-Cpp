//=====1.用vector实现栈
class Stack1{

public:
	void push(const T& val){

		_st.push_back(val);
	}

	void pop(){

		_st.pop_back();
	}

	T& top(){

		return _st.size();
	}

	size_t size() const
	{
		return _st.size();
	}

	bool empty() const
	{

		return _st.empty();
	}
private:
	vector<T> _st;
};

//=====2.用list实现栈
#include<list>
template <class T>

class Stack2{

public:
	void push(const T& val){

		_st.push_front(val);
		//_st.push_back(val);
	}

	void pop(){

		_st.pop_front();
		//_st.pop_back();
	}

	T& top(){

		return _st.front();
		//return _st.back();
	}

	bool empty() const{

		return _st.empty();
	}

	size_t size() const{

		return _st.size();
	}

private:
	list<T> _st;
};
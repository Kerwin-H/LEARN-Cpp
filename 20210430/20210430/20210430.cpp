template<class T, class Container = vector<T>>
class PriorityQueue{

private:
	vector<T> v;

public:
	void shiftUp(int child){

		int parent = (child - 1) / 2;
		//���е���
		while (child > 0){

			if (v[parent] < v[child]){

				swap(v[parent], v[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}

	}

	void shiftDown(){

		int parent = 0;
		int child = 2 * parent + 1;
		while (child < v.size()){

			//�����Һ������ҵ����ֵ
			if (child + 1 < v.size() && v[child] < v[child + 1])
				++child;
			if (v[parent] < v[child]){

				swap(v[parent], v[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	void push(const T& val){

		v.push_back(val);
		shiftUp(v.size() - 1);
	}

	void pop(){

		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		shiftDown();
	}

	T& top(){

		return v[0];
		//return v.front();
	}

	size_t size() const{

		return v.size();
	}

	bool empty() const{

		return v.empty();
	}


};


template <class T>
struct Greater{

	bool operator()(const T& val1, const T& val2){

		return val1 > val2;
	}
};

template <class T>
struct Less{

	bool operator()(const T& val1, const T& val2){

		return val1 < val2;
	}
};

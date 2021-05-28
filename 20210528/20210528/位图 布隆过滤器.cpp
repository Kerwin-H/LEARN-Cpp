#include<vector>
using namespace std;

//位图:
//使用场景: 存放不重复数据,且数据的量比较大的时候


class BitSet{

public:

	//位图的内存大小和数据范围有关系
	BitSet(size_t range)
		:_bit(range / 8 + 1)
	{}

	//存储
	void set(size_t num)
	{
		//0.计算整数位置
		int idx = num / 8;
		//1.计算比特位位置
		int bitIdx = num % 8;
		//2.对应的比特位变为1
		//按位进行或运算

		_bit[idx] |= 1 << bitIdx;
	}

	//查找
	bool test(size_t num){

		int idx = num / 32;
		int bitIdx = num % 32;
		return (_bit[idx] >> bitIdx) & 1;
	}
	//删除
	void reset(size_t num){

		int idx = num / 32;
		int bitIdx = num % 32;
		_bit[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _bit;
};


//m: 需要比特位的大小
//n: 元素个数
//k:哈希函数个数
//k=m/n *ln2    m=k*n*1.4
//时间复杂度: O(k)
//场景: 存放各种数据的简单信息
//概率: 判断存在,结果不一定正确
//==存在误删

template<class T, class Hash1, class Hash2, class Hash3>
class BloomFilter{

public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		, _bitCount(5 * num)
	{}

	//存储信息: 使用多个比特位存储信息
	void set(const T& val){

		Hash1 h1;
		Hash2 h2;
		Hash3 h3;

		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;

		_bit.set(idx1);
		_bit.set(idx2);
		_bit.set(idx3);
	}

	bool test(const T& val){

		Hash1 h1;
		Hash2 h2;
		Hash3 h3;

		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;

		if (!_bit.test(idx1))
			return false;
		if (!_bit.test(idx2))
			return false;
		if (!_bit.test(idx3))
			return false;

		//可能存在
		return true;
	}

private:
	BitSet _bit;
	//记录比特位的个数
	size_t _bitCount;
};


int main(){

	//BitSet q(16);

	//
	//q.set(16);
	//q.set(8);
	//q.set(33);
	//q.set(50);
	//q.set(65);


	//bool ret=q.test(16);
	//ret=q.test(5);


	BloomFilter <int, int, int, int>  b(10);

	b.set(1);
	b.set(2);
	b.set(3);

	bool ret = b.test(4);





	system("pause");
	return 0;
}

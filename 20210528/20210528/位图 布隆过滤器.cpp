#include<vector>
using namespace std;

//λͼ:
//ʹ�ó���: ��Ų��ظ�����,�����ݵ����Ƚϴ��ʱ��


class BitSet{

public:

	//λͼ���ڴ��С�����ݷ�Χ�й�ϵ
	BitSet(size_t range)
		:_bit(range / 8 + 1)
	{}

	//�洢
	void set(size_t num)
	{
		//0.��������λ��
		int idx = num / 8;
		//1.�������λλ��
		int bitIdx = num % 8;
		//2.��Ӧ�ı���λ��Ϊ1
		//��λ���л�����

		_bit[idx] |= 1 << bitIdx;
	}

	//����
	bool test(size_t num){

		int idx = num / 32;
		int bitIdx = num % 32;
		return (_bit[idx] >> bitIdx) & 1;
	}
	//ɾ��
	void reset(size_t num){

		int idx = num / 32;
		int bitIdx = num % 32;
		_bit[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _bit;
};


//m: ��Ҫ����λ�Ĵ�С
//n: Ԫ�ظ���
//k:��ϣ��������
//k=m/n *ln2    m=k*n*1.4
//ʱ�临�Ӷ�: O(k)
//����: ��Ÿ������ݵļ���Ϣ
//����: �жϴ���,�����һ����ȷ
//==������ɾ

template<class T, class Hash1, class Hash2, class Hash3>
class BloomFilter{

public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		, _bitCount(5 * num)
	{}

	//�洢��Ϣ: ʹ�ö������λ�洢��Ϣ
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

		//���ܴ���
		return true;
	}

private:
	BitSet _bit;
	//��¼����λ�ĸ���
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

////========��ǰn���
class Solution {
public:
	//�ڲ���
	class Sum{
	public:
		Sum(){

			//ֱ�ӷ����ⲿ��ľ�̬��Ա
			_sum += _i;
			++_i;
		}
	};

	int Sum_Solution(int n) {
		//��������
		_sum = 0;
		_i = 1;

		Sum array[n];
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};

int Solution::_i = 1;
int Solution::_sum = 0;
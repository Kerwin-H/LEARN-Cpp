////========求前n项和
class Solution {
public:
	//内部类
	class Sum{
	public:
		Sum(){

			//直接访问外部类的静态成员
			_sum += _i;
			++_i;
		}
	};

	int Sum_Solution(int n) {
		//进行重载
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
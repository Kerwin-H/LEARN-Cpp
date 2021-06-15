class Solution {
public:
	int cuttingRope(int n) {

		if (n <= 3)  return n - 1;

		int a = n / 3, b = n % 3;

		if (b == 0)  return pow(3, a);
		if (b == 1)  return pow(3, a - 1) * 4;
		return pow(3, a) * 2;
	}
};

class Solution {
public:
	int cuttingRope(int n) {
		if (n<3) return 1;
		if (n == 3) return 2;
		long ans = 1;
		while (n>4){
			ans = ans * 3 % (1000000007);
			n = n - 3;
		}
		ans = ans*n % (1000000007);
		return ans;
	}
};

class Solution {
	int f(int n, int m) {
		if (n == 1) {
			return 0;
		}
		int x = f(n - 1, m);
		return (m + x) % n;
	}
public:
	int lastRemaining(int n, int m) {
		return f(n, m);
	}
};


class Solution {
public:
	int add(int a, int b) {

		if (a == 0 || b == 0) {
			return a == 0 ? b : a;
		}

		int sum = 0, carry = 0;
		while (b != 0) {
			sum = a ^ b;
			carry = (unsigned int)(a & b) << 1;
			a = sum;
			b = carry;
		}
		return a;
	}
};

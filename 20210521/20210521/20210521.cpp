class Solution {
public:
	int fib(int n) {
		if (n == 0 || n == 1){
			return n;
		}
		int a = 0, b = 1;
		for (int i = 2; i <= n; ++i){
			long temp = b;
			b = (a + b) % 1000000007;
			a = temp;
		}
		return b;
	}
};

class Solution {
public:
	const long num = 1000000007;
	int numWays(int n) {
		if (n == 0 || n == 1) return 1;
		int a[2] = { 1, 1 };
		for (int i = 2; i <= n; ++i){
			long tmp = a[1];
			a[1] = (a[0] + a[1]) % num;
			a[0] = tmp;
		}
		return a[1];
	}
};

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int i = 0, j = numbers.size() - 1;
		while (i<j){
			int m = (i + j) / 2;
			if (numbers[m]>numbers[j]) i = m + 1;
			else if (numbers[m]<numbers[j]) j = m;
			else j--;
		}
		return numbers[j];
	}
};
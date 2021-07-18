
class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		// 返回结果的计算
		vector<int> b(n, 1);
		// 从上到下，左下角的遍历
		for (int i = 1; i < n; ++i)
		{
			b[i] *= b[i - 1] * a[i - 1];
		}


		int accu = 1; // 累计乘积的结果，用于和b[i] 来计算
		// 从下到上，左上角的遍历
		for (int i = n - 2; i >= 0; --i)
		{
			accu *= a[i + 1];
			b[i] *= accu;
		}

		return b;
	}
};



class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<double> dp(6, 1.0 / 6.0);
		for (int i = 2; i <= n; i++) {
			vector<double> tmp(5 * i + 1, 0);
			for (int j = 0; j < dp.size(); j++) {
				for (int k = 0; k < 6; k++) {
					tmp[j + k] += dp[j] / 6.0;
				}
			}
			dp = tmp;
		}
		return dp;
	}
};

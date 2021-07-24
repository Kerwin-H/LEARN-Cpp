#include<iostream>
#include<vector>
using namespace std;



//Ѱ�Ҳ��ظ����Ӵ��ַ���
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		if (s.size() == 0) 
			return 0;
		int left = 0, right = 0;
		int res = 0;

		vector<int> index(128, -1);

		while (right < s.size()) {
			if (index[s[right]] != -1) {

				left = max(left, index[s[right]] + 1);
			}
			index[s[right]] = right;

			res = max(res, right - left + 1);

			right++;
		}
		return res;
	}
};


//Ѱ�����������е�ĳһλ������
class Solution {
public:
	int findNthDigit(int n) {

		int weishu = 1;
		long long firstNum = 1;
		long long count = weishu * firstNum * 9;

		while (n > count){

			n -= count;
			weishu++;
			firstNum *= 10;
			count = weishu * firstNum * 9;
		}

		long long num = firstNum + (n - 1) / weishu;

		string s = to_string(num);

		return s[(n - 1) % weishu] - '0';
	}
};
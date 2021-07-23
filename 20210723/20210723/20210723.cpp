#include<iostream>
#include<vector>
#include<string>
using namespace std;

//将输入的字符串进行简单的赋值
class Solution {
public:
	bool isNumber(string s) {
		if (s.size() == 0)
			return false;
		while (!s.empty() && s[0] == ' ')
			s.erase(s.begin());
		while (!s.empty() && *(s.end() - 1) == ' ')
			s.erase(s.end() - 1);
		if (s.empty())
			return false;
		int current = 0;
		bool hasSign = false, hasDot = false, hasE = false, hasNum = false;
		for (auto ch : s)
		{
			if (ch == '+' || ch == '-')
			{
				if (hasSign || hasNum || hasDot)
					return false;
				hasSign = true;

			}
			else if (ch == '.')
			{
				if (hasDot || hasE)
					return false;
				hasDot = true;
			}
			else if (ch == 'e' || ch == 'E')
			{
				if (hasNum && !hasE)
				{
					hasSign = false;
					hasDot = false;
					hasE = true;
					hasNum = false;
				}
				else
					return false;
			}
			else if (ch >= '0' && ch <= '9')
			{
				hasNum = true;
				continue;
			}
			else
				return false;
		}
		if (!hasNum && (hasDot || hasE || hasSign))
			return false;
		return true;
	}
};


//将数字翻译成字符串
class Solution {
public:
	int translateNum(int num) {
		string src = to_string(num);
		int p = 0, q = 0, r = 1;
		for (int i = 0; i < src.size(); ++i) {
			p = q;
			q = r;
			r = 0;
			r += q;
			if (i == 0) {
				continue;
			}
			auto pre = src.substr(i - 1, 2);
			if (pre <= "25" && pre >= "10") {
				r += p;
			}
		}
		return r;
	}
};


int main(){

	system("pause");
	return 0;
}
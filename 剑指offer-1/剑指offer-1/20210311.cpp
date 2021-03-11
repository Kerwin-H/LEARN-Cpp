#include<iostream>
using namespace std;



//========JZ 2
class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	*
	* @param s string字符串
	* @return string字符串
	*/
	string replaceSpace(string s) {
		// write code here
		int len = s.size();
		for (int i = 0; i<len; ++i){

			if (s[i] == ' '){

				s.replace(i, 1, "%20");
				len += 2;
				i += 2;
			}
		}
		return s;
	}
};



//========JZ 7
class Solution {
public:
	int Fibonacci(int n) {

		if (n<2)
			return n;
		int a = 0, b = 1, c = 0;

		for (int i = 2; i <= n; ++i){		//=重点

			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};


//========JZ 8
class Solution {
public:
	int jumpFloor(int number) {
		if (number<3)
			return number;

		int a = 1, b = 1, c;
		for (int i = 2; i <= number; ++i){

			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};


//========JZ 9
class Solution {
public:
	int jumpFloorII(int number) {

		int n;
		if (number<3)
			return number;

		int a = 1, b = 2;
		int sum = a + b;
		int res = 0;
		for (int i = 3; i <= number; ++i){

			res = sum + 1;
			sum += res;
		}
		return res;
	}
};

//========JZ 10  可以理解为跳台阶问题,横的为2
class Solution {
public:
	int rectCover(int number) {

		if (number<3)
			return number;

		int a = 1, b = 2, c;

		for (int i = 3; i <= number; ++i){

			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};
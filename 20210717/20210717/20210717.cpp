class Solution {
private:
	int to_int(string& s) {
		int num = 0;
		int len = s.length() - 1;
		bool neg = false;
		for (int i = 0; i <= len; i++) {
			if (i == 0 && s.at(i) == '-') {
				
				neg = true;
				continue;
			}
			
			if ((num == INT_MAX / 10 && s.at(i)>'7') || num > INT_MAX / 10) {
				if (neg) return INT_MIN;
				return INT_MAX;
			}
			num = num * 10 + (s.at(i) - '0');
		}
		if (neg) num = -num;
		return num;
	}
	bool is_num(char& c) {
		return c >= '0' && c <= '9';
	}
public:
	int strToInt(string str) {
		string num;
		int len = str.length() - 1;
		int i = 0;

		
		while (i <= len && str.at(i) == ' ') i++;
		
		if (i > len) return 0;

		
		char start = str.at(i);

		
		if (!is_num(start) && i == len) return 0;
		
		else if (is_num(str.at(i)) || ((start == '-' || start == '+') && i < len && is_num(str.at(++i)))) {
			
			if (start == '-') {
				num += move(start);
			}

			
			while (i <= len && is_num(str.at(i))) {
				num += move(str.at(i));
				i++;
			}

		}
		return to_int(num);
	}
};

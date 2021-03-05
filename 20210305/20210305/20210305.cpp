#include<iostream>
using namespace std;

class Date{

public:
	Date(int y = 1, int m = 1, int d = 1){


		if (y <= 0 || m <= 0 || m > 12 ||
			d <= 0 || d > getDay(y, m)){

		
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "日期无效则为默认值:1-1-1" << endl;
		}
		else{
			_y = y;
			_m = m;
			_d = d;
		}
	}

	int getDay(int y, int m){

		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
	
		if (m == 2 && ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0){

			day += 1;
			return day;
		}
	}


	Date& operator+=(int day){

	
		if (day < 0)
			return *this -= -day;

		
		_d += day;

		while (_d > getDay(_y, _m)){


			_d -= getDay(_y, _m);

	
			++_m;
			if (_m == 13){

				
				++_y;
				_m = 1;
			}
		}
		return *this;
	}


	Date operator+(int day){
		Date tmp = *this;
		tmp += day;
		return tmp;
	}

	Date& operator++(){

		return *this += 1;
	}

	
	Date operator++(int){

		Date copy(*this);
		*this += 1;
		
		return copy;
	}

	Date& operator-=(int day){

		
		if (day < 0)
			return *this += -day;


	
		_d -= day;

	
		while (_d <= 0){

			
			--_m;
		
			if (_m == 0){

			
				_y--;
				_m = 12;
			}
			_d += getDay(_y, _m);
		}
		return *this;
	}

	
	Date operator-(int day){
		Date copy(*this);
		copy -= day;
		return copy;
	}

	Date& operator--(){
		return *this -= 1;
	}
	
	Date operator--(int){
		Date copy(*this);
		*this -= 1;
		return copy;
	}


	bool operator==(const Date& d){

		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}
	
	bool operator!=(const Date& d){

		return !(*this == d);
	}
	
	bool operator>(const Date& d){

		if (_y > d._y)
			return true;

		else if (_y == d._y){

			if (_m > d._m)
				return true;

			else if (_m == d._m){

				if (_d > d._d)
					return true;
			}
		}
		return false;
	}
	
	bool operator<(const Date& d){
		return !(*this >= d);
	}
	
	bool operator>=(const Date& d){
		return *this>d || *this == d;
	}
	
	bool operator<=(const Date& d){
		return !(*this>d);
	}



	int operator-(const Date& d){

		
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min){

			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max){

			++min;
			++day;
		}
		return flag*day;
	}

private:
	int _y;
	int _m;
	int _d;
};

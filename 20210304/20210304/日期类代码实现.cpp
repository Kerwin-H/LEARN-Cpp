#include<iostream>
using namespace std;

class Date{

public:
	Date(int y = 1, int m = 1, int d = 1){
		
		//====判断日期是否有效
		if (y <= 0 || m <= 0 || m > 12 ||
			d <= 0 || d > getDay(y, m)){
			
			//日期无效
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
	//====定义的日期是否在所在范围内
	int getDay(int y, int m){

		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
		//如果是2月,为闰年,则要修改天数
		if (m == 2 && ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0){

			day += 1;
			return day;
		}
	}

	//====日期的运算
	//Date+=int 
	//左操作数+=有操作数:左操作数的具体内容发生变化 ,返回值:相加之后的值
	Date& operator+=(int day){
		
		//判断日期是否为负数
		if (day < 0)
			return *this -= -day;

		//Date :2021.2.4
		//假设两个日期相加如果没有约束的时候,它的值就会无限制的增长
		//无法按照我们的想法来进行月份的叠加,所以我们需要利用函数进行操作
		//1.首先将天数进行相加,看其对应的内容是否会进行溢出
		_d += day;
		//判断天数是否会溢出
		while(_d > getDay(_y, _m)){
			
			//减去当月的天数
			_d -= getDay(_y, _m);

			//月份进行进位
			++_m;
			//判断月份是否溢出
			if (_m == 13){
				
				//年份进位
				++_y;
				_m = 1;
			}
		}
		return *this;
	}

	//====Date+int
	//加法: 返回相加之后的结果,操作数不能改变
	//注意调用拷贝
	Date operator+(int day){
		Date tmp = *this;
		 tmp += day;
		return tmp;
	}

	//====前置
	//++Date
	Date& operator++(){
		
		return *this += 1;
	}

	//====后置
	//Date++
	Date operator++(int){		//用来区分
	
		Date copy(*this);
		*this += 1;
		//返回++之前的值
		return copy;
	}

	//====减法
	Date& operator-=(int day){
		
		//判断日期是否为负数
		if (day < 0)
			return *this += -day;


		//首先对对应的日进行相减
		_d -= day;

		//判断
		while (_d <= 0){
			
			//用上一个月的天数回补
			--_m;
			//判断这个月份是否溢出(向下)
			if (_m == 0){
				
				//需要会退到上一年的12月份
				_y--;
				_m = 12;
			}
			_d += getDay(_y, _m);
		}
		return *this;
	}

	//==Date - int
	Date operator-(int day){
		Date copy(*this);
		copy -= day;
		return copy;
	}
	//==	--Date
	Date& operator--(){
		return *this -= 1;
	}
	//==	Date--
	Date operator--(int){
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	//==
	bool operator==(const Date& d){
		
		return _y == d._y
			&&_m == d._m
			&&_d == d._d;
	}
	//!=
	bool operator!=(const Date& d){
		
		return !(*this == d);
	}
	//>
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
	//<
	bool operator<(const Date& d){
		return !(*this >= d);
	}
	//>=
	bool operator>=(const Date& d){
		return *this>d || *this == d;
	}
	//<=
	bool operator<=(const Date& d){
		return !(*this>d);
	}


	//日期相减: Date -Date
	int operator-(const Date& d){
	
		//计算比较小的日期要经过多少次的自加运算,才能和大的日期相同	
		//自加的次数就是相差的天数
		Date max=*this;
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

//==加对应
//void test(){
//	
//	Date d1(2021, 1, 1);
//	Date d2(2021, 1, 1);
//	Date d3(2021, 1, 1);
//	Date d4(2021, 1, 1);
//
//	d1.operator+=(1);
//
//
//	d2 += 30;
//
//	d3 += 90;
//
//	d4 += 100;
//
//	d3 = d4 + 50;
//
//	//前置
//	d4 = ++d3;
//
//	//后置
//	d4 = d3++;
//	d4 = d3.operator++(10);	//添加参数值没用
//}

//==减对应
//void test(){
//	
//	Date d1(2021, 2, 5);
//	Date d2(2021, 2, 5);
//	Date d3(2021, 2, 5);
//	Date d4(2021, 2, 5);
//
//	d1 -= 1;
//	d2 -= 30;
//	d3 -= 40;
//	d4 -= 360;
//
//	d3 = d4 - 30;
//
//	d3 = d4 - 30;
//	d3 = --d4;
//	d3 = d4--;
//
//	
//}


//void test(){
//	
//	Date d1(2021, 4, 1);
//	Date d2(2021, 1, 5);
//	Date d3(2021, 3, 5);
//	
//
//	bool ret = d1 == d1;
//	ret = d1 > d2;
//	ret = d1 >= d2;
//	ret = d1 < d3;
//
//}

void test(){
	
	Date d1(2020, 2, 5);
	//Date d2(2021, 6, 28);
	Date d2 = d1 + 335;
	int day = d1 - d2;

}



int main(){

	test();

	system("pause");
	return 0;
}
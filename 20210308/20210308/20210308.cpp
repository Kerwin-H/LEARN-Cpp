#include<iostream>

using namespace std;
//输入一个日期,对其进行累计天数,并将其累计好的进行输出
//int main(){
//	
//	int n;
//	while (cin >> n){
//		
//		for (int i = 0; i < n; ++i){
//			
//			int y, m, d, num; 
//			int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//			cin >> y >> m >> d >> num;
//
//			while (num>days[m - 1]){
//			
//				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//					days[1] = 29;
//				else
//					days[1] = 28;
//				
//				num -= days[m - 1] - d;
//
//				d = 0;
//				m++;
//				if (m == 13){
//					
//					y++;
//					m = 1;
//				}
//			}
//			printf("%4d-%02d-%02d\n",y,m,num);
//		}
//	}
//	return 0;
//}

//int main(){
//	
//	int n;
//	while (cin >> n){
//		
//		for (int i = 0; i < n; ++i){
//			
//			int y, m, d, num;
//			int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
//			cin >> y >> m >> d >> num;
//
//			while (num>day[m - 1]){
//				
//				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//					day[1] = 29;
//				else
//					day[1] = 28;
//
//				num -= day[m - 1] - d;
//
//				d = 0;
//				m++;
//				if (m == 13){
//					
//					y++;
//					m = 1;
//				}
//			}
//			printf("%4d-%02d-%02d",y,m,num);
//		}
//	}
//	return 0;
//}
//
//int main(){
//	
//	int n;
//	while (cin >> n){
//		
//		for (int i = 0; i < n; ++i){
//			
//			int y, m, d, num;
//			int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//			cin >> y >> m >> d >> num;
//
//			while (num>day[m - 1]){
//				
//				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//					day[1] = 29;
//				else
//					day[1] = 28;
//				
//				num -= day[m - 1] - d;
//				d = 0;
//				m++;
//				if (m = 13){
//					
//					y++;
//					m = 1;
//				}
//			}
//			printf("%4d-%02d-%02d",y,m,num);
//		}
//	}
//	return 0;
//}

//输入年份和第多少天,计算出这一年中对应得具体时间
//int main(){
//
//	int y;
//	int d;
//
//	int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> y >> d){
//
//		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//			mon[1] = 29;
//		else
//			mon[1] = 28;
//
//		for (int i = 0; i < 12; ++i){
//
//			if (d <= mon[i]){
//
//				printf("%4d%-02d-%02d\n", y, i + 1, d);
//				break;
//			}
//			else
//				d = d - mon[i];
//		}
//
//		return 0;
//	}
//}
//
//int main(){
//	
//	int y;
//	int d;
//	int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> y >> d){
//		
//		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//			mon[1] = 29;
//		else
//			mon[1] = 28;
//
//		for (int i = 0; i < 12; ++i){
//			
//			if (d <= mon[i]){
//
//				printf("%4d-%02d-%02d", y, i + 1, d);
//				break;
//			}
//			else
//				d = d - mon[i];
//		}
//	}
//	return 0;
//}

//int main(){
//	
//	int y, d;
//	int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> y >> d){
//		
//		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//			mon[1] = 29;
//		else
//			mon[1] = 28;
//
//		for (int i = 0; i < 12; ++i){
//			
//			if (d <= mon[i]){
//
//				printf("%4d-%02d-%02d", y, i + 1, d);
//				break;
//			}
//			else
//				d = d - mon[i];
//		}
//	}
//	return 0;
//}

//求出日期之间的差值
//int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
//
//int count(int y, int m, int d){
//	
//	int yd = 365 * y + y / 4 - y / 100 + y / 400;
//
//	int mid = mon[m - 1];
//
//	if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
//		mid += 2;
//
//	return y + mid + d;
//}

//前N项和
class A{

public:
	class Sum{
	public:
		Sum(){
			
			_sum += _i;
			++_i;
		}
	};

	int Sum_solution(int n){
		
		_sum = 0;
		_i = 1;

		Sum array[n];
		return _sum;
	}

private:
	static int _sum;
	static int _i;
};

int A::_i = 1;
int A::_sum = 0;
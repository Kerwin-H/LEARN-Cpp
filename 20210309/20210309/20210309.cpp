#include<iostream>

using namespace std;
//日期加天数得新的日期练习
int main(){

	int n;
	while (cin >> n){

		for (int i = 0; i < n; ++i){

			int y, m, d, num;
			int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			cin >> y >> m >> d >> num;

			while (num>day[m - 1]){

				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
					day[1] = 29;
				else
					day[1] = 28;

				num -= day[m - 1] - d;

				d = 0;
				m++;
				if (m == 13){

					y++;
					m = 1;
				}
			}
			printf("%4d-%02d-%02d\n", y, m, num);
		}
	}
	return 0;
}



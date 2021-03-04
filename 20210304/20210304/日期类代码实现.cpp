#include<iostream>
using namespace std;

class Date{

public:
	Date(int y = 1, int m = 1, int d = 1){
		
		//====�ж������Ƿ���Ч
		if (y <= 0 || m <= 0 || m > 12 ||
			d <= 0 || d > getDay(y, m)){
			
			//������Ч
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "������Ч��ΪĬ��ֵ:1-1-1" << endl; 
		}
		else{ 
			_y = y;
			_m = m;
			_d = d;
		}
	}
	//====����������Ƿ������ڷ�Χ��
	int getDay(int y, int m){

		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
		//�����2��,Ϊ����,��Ҫ�޸�����
		if (m == 2 && ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0){

			day += 1;
			return day;
		}
	}

	//====���ڵ�����
	//Date+=int 
	//�������+=�в�����:��������ľ������ݷ����仯 ,����ֵ:���֮���ֵ
	Date& operator+=(int day){
		
		//�ж������Ƿ�Ϊ����
		if (day < 0)
			return *this -= -day;

		//Date :2021.2.4
		//������������������û��Լ����ʱ��,����ֵ�ͻ������Ƶ�����
		//�޷��������ǵ��뷨�������·ݵĵ���,����������Ҫ���ú������в���
		//1.���Ƚ������������,�����Ӧ�������Ƿ��������
		_d += day;
		//�ж������Ƿ�����
		while(_d > getDay(_y, _m)){
			
			//��ȥ���µ�����
			_d -= getDay(_y, _m);

			//�·ݽ��н�λ
			++_m;
			//�ж��·��Ƿ����
			if (_m == 13){
				
				//��ݽ�λ
				++_y;
				_m = 1;
			}
		}
		return *this;
	}

	//====Date+int
	//�ӷ�: �������֮��Ľ��,���������ܸı�
	//ע����ÿ���
	Date operator+(int day){
		Date tmp = *this;
		 tmp += day;
		return tmp;
	}

	//====ǰ��
	//++Date
	Date& operator++(){
		
		return *this += 1;
	}

	//====����
	//Date++
	Date operator++(int){		//��������
	
		Date copy(*this);
		*this += 1;
		//����++֮ǰ��ֵ
		return copy;
	}

	//====����
	Date& operator-=(int day){
		
		//�ж������Ƿ�Ϊ����
		if (day < 0)
			return *this += -day;


		//���ȶԶ�Ӧ���ս������
		_d -= day;

		//�ж�
		while (_d <= 0){
			
			//����һ���µ������ز�
			--_m;
			//�ж�����·��Ƿ����(����)
			if (_m == 0){
				
				//��Ҫ���˵���һ���12�·�
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


	//�������: Date -Date
	int operator-(const Date& d){
	
		//����Ƚ�С������Ҫ�������ٴε��Լ�����,���ܺʹ��������ͬ	
		//�ԼӵĴ���������������
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

//==�Ӷ�Ӧ
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
//	//ǰ��
//	d4 = ++d3;
//
//	//����
//	d4 = d3++;
//	d4 = d3.operator++(10);	//��Ӳ���ֵû��
//}

//==����Ӧ
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
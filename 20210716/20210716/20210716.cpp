#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class A{

public:
	int find(int a){
		

		int arr[10] = {0};
		printf("please enter\n ");
		for (int i = 0; i < 10; ++i){
			
			cin >> arr[i];
		}

		cout << "num" << endl;
		
		int toFind = 0;
		cin >> toFind;
		int left = 0;
		int right = sizeof(arr) / sizeof(arr[0]) - 1;
		while (left <= right){

			int mid = (left + right) / 2;
			if (toFind < arr[mid]){
				right = mid - 1;
			}
			else if (toFind>arr[mid]){
				left = mid + 1;
			}
			else{

				printf("�ҵ���ӦԪ��,�±�Ϊ:%d\n", mid);
				break;
			}
		}
		if (left > right){
			printf("��Ԫ�ز�����!\n");
			
			return 0;
		}
	}

};


int main(){

	A s;
	s.find(5);



	
	system("pause");
	return 0;
}
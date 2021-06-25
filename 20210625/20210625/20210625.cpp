#include<iostream>
using namespace std;


void Swap(int* arr, int pos1, int pos2){
	
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

//Ã°Åİ
void bubble(int* arr, int n){

	
	int end = n;
	while (end > 1){
		
		for (int i = 1; i < end; ++i){
			
			if (arr[i - 1]>arr[i]){
				Swap(arr, i - 1, i);
			}
		}
		--end;
	}
}

//¿ìÅÅ
int getMid(int* arr, int begin, int end){
	
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid]){
		
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else{
		
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}


void printArr(int* arr, int n){

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(){

	int arr[] = { 1, 5, 7, 9, 6, 3, 8, 4 };
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	bubble(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));



	getMid(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}

int main(){

	test();

	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}


//==========≤Â»Î≈≈–ÚÀ„∑®  
void insertSort(int* arr, int n){


	for (int i = 0; i < n; ++i){


		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data){

			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//==========œ£∂˚≈≈–Ú
void shellSort(int* arr, int n){

	int gap = n;

	while (gap > 1){

		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i){

		
			int end = i - gap;

			int data = arr[i];
			while (end >= 0 && arr[end]>data){

				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

//—°‘Ò≈≈–Ú
void selectSort(int* arr, int n){

	int start = 0;
	int end = n - 1;
	while (start < end){


		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; ++i){

			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		
		Swap(arr, start, minIdx);
	
		++start;
	}
}

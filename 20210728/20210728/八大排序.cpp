#include<iostream>
using namespace std;


void Swap(int *arr,int m,int n){
	
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}



//插入排序
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
//希尔排序
void shellSort(int * arr, int n){
	
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

//选择排序
void selectSort(int* arr, int n){

	int start = 0;
	int end = n - 1;

	while (start < end){
		
		int min = start;
		int i;
		for (i = start + 1; i <= end; ++i){
			
			if (arr[i] < arr[min]){
				
				min = i;
			}
		}

		Swap(arr, start, min);
		++start;
	}
}

//堆排序
void shiftdown(int *arr, int n, int parent){
	
	int child = 2 * parent + 1;
	while (child < n){
		
		if (child + 1 < n&&arr[child + 1] > arr[child])
			++child;

		if (arr[child]>arr[parent]){

			Swap(arr, child, parent);

			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void heapSort(int *arr, int n){
	
	for (int i = (n - 1) / 2; i >= 0; --i){
		
		shiftdown(arr,n,i);
	}

	int end = n - 1;

	while (end > 0){
		
		Swap(arr, end, 0);
		shiftdown(arr, end, 0);
		--end;
	}
}

//冒泡排序
void bubbleSort(int *arr, int n){
	
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

//快排hoare法
//获取基准值
//下面输出的都会基准值
//这段代码主要是理解,其结构不难,不进行过多的注释
int getMid(int* arr, int begin, int end){

	int mid = begin + (end - begin) / 2;

	if (arr[begin] > arr[mid]){			//==========1.开始大于中间

		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else{								//=========2.开始小于等于中间

		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}

//划分函数    实现数组的划分,进行分别遍历的操作
int partion(int* arr, int begin, int end){

	//获取基准值位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, end);

	//首先选择基准值
	int key = arr[begin];
	int start = begin;

	while (begin < end){		//后置比较大的时候

		//1.==============================从后向前找小于基准值的位置
		while (begin < end&&arr[end] >= key)
			--end;

		//2.===============================从前向后找大于的位置
		while (begin < end&&arr[begin] <= key)
			++begin;
		//3.===============================用函数交换
		Swap(arr, begin, end);
	}
	//交换基准值与相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

//快速排序
void quickSort(int* arr, int begin, int end){

	if (begin >= end)
		return;

	//div:一次划分后基准值
	int div = partion(arr, begin, end);
	//分别进行左右两边的快排
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}


//计数排序
void countSort(int *arr, int n){
	
	int max, min;
	min = max = arr[0];

	for (int i = 1; i < n; ++i){
		
		if (arr[i]>max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int range = max - min + 1;

	int* countarr = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < n; ++i){
		
		countarr[arr[i] - min]++;
	}

	int idx = 0;
	for (int i = 0; i < range; ++i){
		
		while (countarr[i]--){
			
			arr[idx++] = i + min;
		}
	}

}


int main(){ 
	int arr[10] = { 1, 4, 6, 7, 8, 9, 7, 4, 2, 3 }; 
	
	//insertSort(arr, 10);
	//shellSort(arr, 10);
	//selectSort(arr, 10);
	//heapSort(arr, 10);
	//bubbleSort(arr, 10);
	countSort(arr, 10);


	return 0;
}












#include<iostream>
using namespace std;


void Swap(int *arr,int m,int n){
	
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}



//��������
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
//ϣ������
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

//ѡ������
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

//������
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

//ð������
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

//����hoare��
//��ȡ��׼ֵ
//��������Ķ����׼ֵ
//��δ�����Ҫ�����,��ṹ����,�����й����ע��
int getMid(int* arr, int begin, int end){

	int mid = begin + (end - begin) / 2;

	if (arr[begin] > arr[mid]){			//==========1.��ʼ�����м�

		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else{								//=========2.��ʼС�ڵ����м�

		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}

//���ֺ���    ʵ������Ļ���,���зֱ�����Ĳ���
int partion(int* arr, int begin, int end){

	//��ȡ��׼ֵλ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, end);

	//����ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;

	while (begin < end){		//���ñȽϴ��ʱ��

		//1.==============================�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end&&arr[end] >= key)
			--end;

		//2.===============================��ǰ����Ҵ��ڵ�λ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//3.===============================�ú�������
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	return begin;
}

//��������
void quickSort(int* arr, int begin, int end){

	if (begin >= end)
		return;

	//div:һ�λ��ֺ��׼ֵ
	int div = partion(arr, begin, end);
	//�ֱ�����������ߵĿ���
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}


//��������
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












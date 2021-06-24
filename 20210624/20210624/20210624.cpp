
void Swap(int* arr, int a, int b){

	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

//—°‘Ò≈≈–Ú
void selectSort(int* arr, int n){

	int start = 0;
	int end = n - 1;

	while (start < end){

		int minIdx = start;
		int maxIdx = start;

		for (int j = start + 1; j <= end; ++j){

			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j]>arr[maxIdx])
				maxIdx = j;
		}
		Swap(arr, start, minIdx);

		if (maxIdx == start)
			maxIdx = minIdx;
		Swap(arr, end, maxIdx);

		++start;
		--end;
	}
}

//∂—≈≈–Ú
void shiftDown(int* arr, int n, int parent){

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

void heapSort(int* arr, int n){

	for (int i = (n - 2) / 2; i >= 0; ++i){

		shiftDown(arr, n, i);
	}
	int end = n - 1;

	while (end > 0){

		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}

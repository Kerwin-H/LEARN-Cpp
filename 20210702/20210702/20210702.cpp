void merge(int* arr, int begin, int mid, int end, int* tmp){

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	
	int idx = begin;


	while (begin1 <= end1&&begin2 <= end2){

		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];

		else
			tmp[idx++] = arr[begin2++];
	}

	if (begin1 <= end1)	
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

	
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp){

	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n){

	
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}



void mergeSortNoR(int* arr, int n){

	int* tmp = (int*)malloc(sizeof(int)*n);
	
	int step = 1;
	while (step < n){
		for (int idx = 0; idx < n; idx += 2 * step){

			
			int begin = idx;
			int mid = idx + step - 1;
		
			if (mid >= n - 1)
				continue;	
			int end = idx + 2 * step - 1;
			
			if (end > n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}

		
		step *= 2;
	}
}


void countSort(int* arr, int n){

	
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i){

		if (arr[i]>max)
			max = arr[i];
		if (arr[i < min])
			min = arr[i];
	}
	
	int range = max - min + 1;
	
	int* countArr = (int*)calloc(range, sizeof(int));


	for (int i = 0; i < n; ++i){

		countArr[arr[i] - min]++;
	}

	
	int idx = 0;
	for (int i = 0; i < range; ++i){

		while (countArr[i]--){

			arr[idx++] = i + min;
		}
	}
}

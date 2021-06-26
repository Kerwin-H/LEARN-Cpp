
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

//划分函数
int partion(int* arr, int begin, int end){

	//获取基准值位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, end);

	//首先选择基准值
	int key = arr[begin];
	int start = begin;

	while (begin < end){

		//从后向前找小于基准值的位置
		while (begin < end&&arr[end] >= key)
			--end;

		//从前向后找大于的位置
		while (begin < end&&arr[begin] <= key)
			++begin;
		//调用函数交换
		Swap(arr, begin, end);
	}
	//交换基准值与相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

void quickSort(int* arr, int begin, int end){

	if (begin >= end)
		return;
	//div:一次划分后基准值
	//int div = partion(arr, begin, end);
	//int div = partion2(arr, begin, end);
	int div = partion3(arr, begin, end);
	//分别进行左右两边的快排
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}

void printArr(int* arr, int n){

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//===============================1=======================
//快排2  挖坑法
int partion2(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);

	//第一个基准值,也就是初始为坑的位置
	int key = arr[begin];
	while (begin < end){
		//从后往前找到小的
		while (begin < end&&arr[end] >= key)
			--end;
		//进行填坑
		arr[begin] = arr[end];
		//从前往后找大的
		while (begin < end&&arr[begin] <= key)
			++begin;
		//填坑
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}




//================================快排3前后指针
int partion3(int* arr, int begin, int end){

	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	//上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;

	int key = arr[begin];
	while (cur <= end){

		//当cur走到下一个基准值的位置的时候,判断是否连续
		if (arr[cur]<key && ++prev != cur) {

			//不连续,交换数据
			Swap(arr, prev, cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}


//非递归快排
void quickSortNoR(int* arr, int n){

	//创建一个顺序表,保持划分区间
	seqList sq;
	initSeqList(&sq);

	//先保存整个区间
	//首先放右,在放左
	pushBack(&sq, n - 1);
	pushBack(&sq, 0);

	//遍历顺序表,处理区间
	while (!empty(&sq)){

		//取出一个区间
		int left = seqListBack(&sq);
		popBack(&sq);

		int right = seqListBack(&sq);
		popBack(&sq);

		//划分区间
		int div = partion(arr, left, right);

		//保存产生的新区间
		if (left < div - 1){

			pushBack(&sq, div - 1);
			pushBack(&sq, left);
		}
		if (div + 1 < right){

			pushBack(&sq, div + 1);
			pushBack(&sq, right);
		}
	}
}



void quickSort(int *array, int left, int right)
{
	if (left < right)
	{
		int pivot = array[left];
		int low = left, high = right;
		while (low < high)
		{
			while (array[high] >= pivot && low < high)
				high--;
			array[low] = array[high];

			while (array[low] <= pivot && low < high)
				low++;
			array[high] = array[low];
		}
		array[low] = pivot;

		quickSort(array, left, low - 1);
		quickSort(array, low + 1, right);
	}
}



void quicksort(int* a, int p, int q)
{
	int i = p;
	int j = q;
	int temp = a[p];

	while (i < j)
	{
		
		while (a[j] >= temp && j > i) j--;

		if (j > i)
		{
			a[i] = a[j];
			i++;

			
			while (a[i] < temp && i < j)  i++;
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
	}
	a[i] = temp;

	for (int k = p; k <= q; k++)
	{
		if (k == i)
		{
			printf("(%d) ", a[k]);
			continue;
		}
		printf("%d ", a[k]);
	}
	printf("\n");

	if (p < (i - 1)) quicksort(a, p, i - 1);
	if ((j + 1) < q) quicksort(a, j + 1, q);
}


void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left>right)
		return;

	temp = a[left]; 
	i = left;
	j = right;
	while (i != j)
	{
		
		while (a[j] >= temp && i<j)
			j--;
		
		while (a[i] <= temp && i<j)
			i++;
		
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
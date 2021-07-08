//i=1的写法（标准写法）
for (int i = 1; i < array.Length; i++)
{
	if (array[i] < array[i - 1])
	{
		int temp = array[i];
		int j;
		for (j = i; j > 0 && array[j - 1] > temp; j--)
		{
			array[j] = array[j - 1];
		}
		array[j] = temp;
	}
}


//i=0的写法
for (int i = 0; i < array.Length - 1; i++)
{
	if (array[i + 1] < array[i])
	{
		int temp = array[i + 1];
		int j;
		for (j = i + 1; j > 0 && array[j - 1] > temp; j--)
		{
			array[j] = array[j - 1];
		}
		array[j] = temp;
	}
}


int increment = array.Length;
while (increment > 1)
{
	increment /= 2;
	for (int i = 0; i < increment; i++)
	{
		for (int j = i + increment; j < array.Length; j += increment)
		{
			if (array[j] < array[j - increment])
			{
				int temp = array[j];
				int k;
				for (k = j - increment; k >= 0 && array[k] > temp; k -= increment)
				{
					array[k + increment] = array[k];
				}
				array[k + increment] = temp;
			}
		}
	}
}


using System;

class Program
{
	static int[] array = { 5, 6, 9, 8, 3, 7, 4, 1, 2 };
	static void Main(string[] args)
	{
		Sort(0, 8);
	}

	//快速排序的递归调用函数
	static void Sort(int low, int high)
	{
		if (low < high)
		{
			int pivot = Partition(low, high);
			Sort(low, pivot - 1);
			Sort(pivot + 1, high);
		}
	}

	
	static int Partition(int low, int high)
	{
		
		int m = low + (high - low) / 2;
		if (array[high] < array[low])
		{
			int temp = array[high];
			array[high] = array[low];
			array[low] = temp;
		}
		if (array[m] > array[high])
		{
			int temp = array[m];
			array[m] = array[high];
			array[high] = temp;
		}
		if (array[m] < array[low])
		{
			int temp = array[m];
			array[m] = array[low];
			array[low] = temp;
		}
		

		int key = array[low];
		while (low < high)
		{
			while (low < high && array[high] >= key)
			{
				high--;
			}
			array[low] = array[high];
			while (low < high && array[low] <= key)
			{
				low++;
			}
			array[high] = array[low];
		}
		array[low] = key;
		return low;
	}
}

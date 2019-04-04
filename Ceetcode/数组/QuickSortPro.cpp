/* 三个方面的改进 */

/*函数作用：取待排序序列中low、mid、high三个位置上数据，选取他们中间的那个数据作为枢轴*/
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);//计算数组中间的元素的下标

										//使用三数取中法选择枢轴
	if (arr[mid] > arr[high])//目标: arr[mid] <= arr[high]
	{
		swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high])//目标: arr[low] <= arr[high]
	{
		swap(arr[low], arr[high]);
	}
	if (arr[mid] > arr[low]) //目标: arr[low] >= arr[mid]
	{
		swap(arr[mid], arr[low]);
	}
	//此时，arr[mid] <= arr[low] <= arr[high]
	return arr[low];
	//low的位置上保存这三个位置中间的值
	//分割时可以直接使用low位置的元素作为枢轴，而不用改变分割函数了
}

void InsertSort(int *arr, int low, int high)
{
	for (int i = low + 1; i<=high; i++)
	{
		int temp = arr[i];
		int j = i;
		while (j>low && temp<arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0;
	int rightLen = 0;

	if (high - low + 1 < 10)
	{
		InsertSort(arr, low, high);
		return;
	}

	//一次分割
	int key = SelectPivotMedianOfThree(arr, low, high);//使用三数取中法选择枢轴

	while (low < high)
	{
		while (high > low && arr[high] >= key)
		{
			if (arr[high] == key)//处理相等元素
			{
				swap(arr[right], arr[high]);
				right--;
				rightLen++;
			}
			high--;
		}
		arr[low] = arr[high];
		while (high > low && arr[low] <= key)
		{
			if (arr[low] == key)
			{
				swap(arr[left], arr[low]);
				left++;
				leftLen++;
			}
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	//一次快排结束
	//把与枢轴key相同的元素移到枢轴最终位置周围
	int i = low - 1;
	int j = first;
	while (j < left && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i--;
		j++;
	}
	i = low + 1;
	j = last;
	while (j > right && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	QSort(arr, first, low - 1 - leftLen);
	QSort(arr, low + 1 + rightLen, last);
}


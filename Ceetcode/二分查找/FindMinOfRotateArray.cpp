int MinInOrder(int *arr,int left,int right)
{
	int result = arr[left];
	for (int i = left+1; i < right; i++)
	{
		if (result > arr[i])
			result = arr[i];
	}
	return result;
}

int MinOfRotateArray(int *arr, int length)
{
	if (length <= 1)
		return arr[0];
	int left = 0;  
	int right = length - 1;
	int mid = left; // 防止出现没有旋转的情况，这样可以直接返回 arr[mid]=arr[0]。
	while (arr[left] >= arr[right])
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		int mid = (left + right) / 2;
		if (arr[mid] == arr[right] && arr[mid] == arr[left]) //三点相等的特殊情况
			return MinInOrder(arr, left, right);
		if (arr[mid] <= arr[right]) // arr[mid]<=arr[right]一定确定mid位于右区间
			right = mid;
		else // 不在右区间，那么肯定在左区间，由arr[mid]>=arr[left]一定确定位于左区间
			left = mid;
	}
	return arr[mid];
}

int SearchInRotateArray(int *arr, int length, int target)
{

	int left = 0;
	int right = length - 1;
	int mid = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] < arr[right])
		{
			if (target > arr[mid] && arr[right] >= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			if (target < arr[mid] && target >= arr[left])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}

bool SearchInRotateArray2(int* arr, int lenght, int target)
{
	if (lenght < 1)
		return false;

	int left = 0;
	int right = lenght - 1;
	int mid = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return true;
		if (arr[mid] < arr[right])
		{
			if (arr[mid] < target && arr[right] >= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else if (arr[mid] > arr[right])
		{
			if (arr[mid] > target && arr[left] <= target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
			right--;
	}
	return false;
}


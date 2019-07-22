int MinInOrder(int *arr,int left,int right)
{
	int result = arr[left];
	for (int i = left+1; i < right; i++) // 这里仅仅是因为前提 arr[left] = arr[right]，所以 i<right，而不是 i<=right;
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


bool searchInRotatedArray2(int* array, int length, int target)
{
	int left = 0, right = length-1;

	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(array[mid]==target)
			return true;
		if(array[mid]<array[right]){
			if(array[mid]<target && array[right]>=target)
				left = mid +1;
			else
				right = mid -1;
		}
		else if(array[mid]>array[right]){
			if(array[mid]>target && array[left]<=target)
				right = mid -1;
			else
				left = mid +1;
		}
		else
			right--;
	}
	return false;
}

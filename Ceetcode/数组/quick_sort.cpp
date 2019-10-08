int Partition(int* array, int start, int end){
	int left = start, right = end;
	int pivot = array[end];
	while (left<right){
		while (left<right && array[left]<pivot)
			left++;
		while (left<right && array[right] >= pivot)
			right--;
		if (left<right)
			swap(array[left], array[right]);
	}
	swap(array[left], array[end]);
	return left;
}

void QuickSort(int* array, int start, int end){
	if (start<end) { // 至少有两个元素
		int k = Partition(array, start, end);
		QuickSort(array, start, k - 1); // K-1, k +1
		QuickSort(array, k + 1, end);
	}
}
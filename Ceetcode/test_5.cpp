int lower_bound(vector<int>& nums, int target){
	int res = -1;
	int start = 0, end = nums.size();
	while(start<end){
		int mid = start + (end-start)/2;
		if(nums[mid]==target){
			res = mid;
			left = mid+1;
		}
		if(nums[mid]<target)
			left = mid+1;
		else
			right = mid;
	}
	return start;
}

void QuickSort(int* array, int start, int end) {// 左闭右闭
	if(start<end){
		int k = partition(array, start, end);
		QuickSort(array, start, k-1);
		QuickSort(array, k+1, end);
	}
}

int partition(int* array, int start, int end){
	int pivot = array[end];
	int left = start, right = end;
	while(left<right){
		while(left<right && array[left]<pivot)
			left++;
		while(left<right && array[right]>=pivot)
			right--;
		if(left<right)
			swap(array[left],array[right]);
	}
	swap(array[left],array[end]);
	return left;
}

void merge(int* array, int left, int mid, int right) {// 左闭右开
	int l1 = mid-left, l2 = right -mid;
	int* p1 = new int[l1];
	int* p2 = new int[l2];
	for(int i=0;i<l1;i++){
		p1[i] = array[left+i];
	}
	for(int j=0;j<l2;j++){
		p2[j] = array[mid+j];
	}
	int i=0, j = 0, k = left;
	while(i<l1 && j<l2){
		if(p1[i]<p2[j])
			array[k++]=p1[i++];
		else
			array[k++]=p2[j++];
	}
	while(i<l1)
		array[k++]=p1[i++];
	while(j<l2)
		array[k++]=p2[j++];
	delete[]p1;
	delete[]p2;
}

void MergeSort(int* array, int start, int end){
	if(end-start>=2){
		int mid = start + (end-start)/2;
		MergeSort(array, start, mid);
		MergeSort(array, mid, end);
		merge(array, start, mid, end);
	}
}

bool SearchInRotateArray2(int* arr, int length, int target){
	int left = 0, right = length-1;
	while(left<=right){
		int mid = left +(right-left)/2;
		if(arr[mid]==target)
			return true;
		if(arr[mid]<arr[right]){
			if(arr[mid]<target && array[right]>=target)
				left = mid+1;
			else
				right = mid-1;
		}
		else if(arr[mid]>arr[right]){
			if(arr[mid]>target && arr[left]<=target)
				right = mid-1;
			else
				left = mid+1;
		}
		else
			right--;
	}
}

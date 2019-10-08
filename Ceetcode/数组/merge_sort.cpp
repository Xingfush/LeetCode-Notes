void Merge(int a[], int left, int mid, int right){
	// 两端区间长度
	int length1 = mid - left;
	int length2 = right - mid;

	//分配内存
	int *l1 = new int[length1];
	int *l2 = new int[length2];

	for (int i = 0; i<length1; i++)
		l1[i] = a[left + i];
	for (int j = 0; j<length2; j++)
		l2[j] = a[right + j];

	int i = 0, j = 0;
	while (i<length1 && j<length2){
		if (l1[i] <= l2[j])
			a[left++] = l1[i++];
		else
			a[left++] = l2[j++];
	}
	while (i<length1)
		a[left++] = l1[i++];
	while (j<length2)
		a[left++] = l2[j++];

	// 删除分配的内存
	delete[] l1;
	delete[] l2;
}

void MergeSort(int a[], int left, int right){
	if (right - left > 1) {
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}
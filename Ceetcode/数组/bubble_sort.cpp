void BubbleSort(int* array, int length){
	for (int i = 0; i<length; i++){
		for (int j = 0; j<length - i - 1; j++){
			if (array[j]<array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}

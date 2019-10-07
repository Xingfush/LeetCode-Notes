/* 题目要求比较严格，n个元素的数组，每个元素的范围是[0,n-1]，但是有若干个元素重复了
   若干次，请找出任意一个重复的元素
   要求：线性时间复杂度，空间复杂度为常数，即不能使用哈希表
   方法：不断地使用交换法，使i位置的数组元素的值为i，直至找到array[i]==array[array[i]]返回 */

int FindDuplicateElement(int *array, int length){
	if (array == nullptr|| length<1)
		return -1;

	for (int i = 0; i < length; i++){
		if (array[i] > length - 1|| array[i] < 0)
			return -1;
	}

	for (int i = 0; i < length; i++){
		while (array[i] != i){
			if (array[array[i]] == array[i])
				return array[i];
			swap(array[i], array[array[i]]);
		}
	}
	return -1;
}


/* 进阶：当有限定 n 个元素为 [1,n]时，也就是以1开始，找出唯一重复元素 */

int FindDuplicateElement(int *array, int length){
    for (int i = 0; i<length; i++) {
        while (array[i] != i + 1) {
            if (array[array[i] - 1] == array[i])
                return array[i];
            swap(array[i], array[array[i] - 1]);
        }
    }
    return -1;
}

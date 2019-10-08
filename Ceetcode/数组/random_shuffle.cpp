/* 洗牌算法：对一个数组进行乱序洗牌，
1. 首先从所有元素中随机选取一个与第一个元素进行交换，
2.然后在第二个之后选择一个元素与第二个交换，直到最后一个元素。
这样能确保每个元素在每个位置的概率都是1/n。 */

void RandomShuffle(int* array, int n)
{	
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int tmp = rand() % (n - i) + i; // 这一句是关键，使用 rand()%(n-i) + i
		if (tmp != i)
			swap(array[tmp], array[i]);
	}
}

// 代码很容易，关键是知道是这个过程

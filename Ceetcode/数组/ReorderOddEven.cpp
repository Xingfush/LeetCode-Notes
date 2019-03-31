void ReorderOddEven(int *pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
		return;
	
	int *left = pData, *right = pData + length-1;
	while (left < right)
	{
		while (left<right && *left & 0x1 == 1) //必须加上left<right
			left++;
		while (left<right && *right & 0x1 == 0) //必须加上left<right
			right--;
		if (left < right)
		{
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}
}

/* 当数组全是奇数或者偶数时，left或right会越界，所以要加上两个判断 */
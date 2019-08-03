int partition(int* array, int start, int end)
{
	int left = start, right = end;
	int pivot = array[end];

	while(left<right) // 终止条件肯定是 left撞上 right，array[right,left]肯定大于等于pivot
	{
		while(left<right && array[left]<pivot)
			left++;
		while(left<right && array[right]>=pivot)
			right--;
		if(left<right)
			swap(array[left], array[right]);
	}
	swap(array[right], array[end]);
	return left;
}

int findMedian(int* array, int length)
{
	int k = (length-1)/ 2;
	int left = 0, right = length-1;
	int result = 0;
	while(true)
	{
		int q = partition(array, left, right); 
		if(q==k){
			result = array[q]; // 防止 q 局部变量在while外失效
			break;
		}
		else if(q<k)
			left = q+1;
		else
			right = q-1;
	}
	return result;
}


// C++优先队列默认是大顶堆，也就是队头元素最大，这里将其变为小顶堆
struct myCompare
{
	int operator()(int left, int right)
	{
		return left > right;
	}
};

int getMiddle(int* array, int length)
{
	int half = (length-1)/2; 
	priority_queue<int, vector<int>, myCompare> q;

	for(int i=0;i<half;i++)
		q.push(array[i]);

	for(int i=half;i<length;i++){
		if(array[i]>q.top()){
			q.pop();
			q.push(array[i]);
		}
	}
	if(!q.empty())
		return q.top();
}
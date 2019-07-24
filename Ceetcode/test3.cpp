int BinarySearchFirst(int* array, unsigned left, unsigned right)
{
	int res = -1;
	while(left < right)
	{
		unsigned mid = left + (right - left) /2;
		if (array[mid]==key)
		{
			res = mid;
			right = mid;			
		}
		else if (array[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return res;
}

int BinarySearchFirst(int* array, unsigned left, unsigned right, int key)
{
	int res = -1;
	while(left < right)
	{
		unsigned mid = (right - left) /2 +left;
		if(array[mid] == key){
			res = mid;
			left = mid + 1;		
		}
		else if (array[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return res;
}


int partition(int* array, int start, int end)
{
	int left = start, right = end;
	int pivot = array[end];
	while(left<right)
	{
		while(left<right && array[left]<pivot)
			left ++;
		while(left<right && array[right]>=pivot)
			right --;
		if(left<right)
			swap(array[left], array[right]);
	}
	swap(array[left],array[end]);
	return left;
}

void QuickSort(int* array, int start, int end)
{
	if (start<end){ // 至少有一个元素
		int k = partition(array, start, end);
		QuickSort(array, start, k-1); // K-1, k +1
		QuickSort(array, k+1, end);
	}
}


int findMedian(vector<int>& nums)
{
	int k = (nums.size() - 1) >> 1;
	int left = 0, right = nums.size() -1;
	int result = 0;
	while(true)
	{
		int q = partition(nums, left, right);
		if(q==k)
		{
			result = nums[q];
			break;
		}
		else if(q<k)
			left = q + 1;
		else
			right = q - 1;
	}
}


void Merge(int a[], int left, int mid, int right)
{
	// 两端区间长度
	int length1 = mid -left;
	int length2 = right -mid;

	//分配内存
	int *l1 = new int[length1];
	int *l2 = new int[length2];

	for (int i=0; i<length1; i++)
		l1[i] = a[left+i];
	for (int j=0; j<length2; j++)
		l2[j] = a[right+j];

	int i=0, j=0;
	while(i<length1 && j<length2)
	{
		if(l1[i]<=l2[j])
			a[left++] = l1[i++];
		else
			a[left++] = l2[j++];
	}
	while(i<length1)
		a[left++] = l1[i++];
	while(j<length2)
		a[left++] = l2[j++];

	// 删除分配的内存
	delete[] l1;
	delete[] l2;
}

void MergeSort(int a[], int left, int right)
{
	if (right-left > 1)
	{
		int mid = (left+right)/2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

void InsertSort(int* array, int length)
{
	for(int i=1;i<length;i++)
	{
		int temp = array[i];
		while(i>0 && temp<array[i-1])
			array[i--] = array[i-1];
		array[i] = temp;
	}
}

void ShellSort(int* array, int length)
{
	int gap = length/2;
	while(gap != 0)
	{
		for(int i = gap; i<length; i++)
		{
			int temp = array[i];
			while(i>gap && temp < array[i-gap]){
				array[i] = array[i-gap];
				i -= gap;
			}
			array[i] = temp;
		}
		gap /= 2;
	}
}

void BubbleSort(int* array, int length)
{
	for (int i=0;i<length;i++)
	{
		for (int j=0;j<length-i-1;j++)
		{
			if(array[j]<array[j+1])
				swap(array[j],array[j+1]);
		}
	}
}

// 或许只有对于 array 指针引用，这样的方式才是有意义的
void Heapify(int* array, int n, int i)
{
	// 设定 n 为 array 的元素个数
	int left = 2*i+1;
	int right = 2*i +2;
	int largest = i;

	if(left<n-1 && array[left]>array[i])
		largest = left;
	if(left<n-1 && array[right]>array[i])
		largest = right;
	if(largest!=i){
		swap(array[largest],array[i]);
		Heapify(array,n,largest);
	}
	
}

void HeapSort(int* array, int length)
{
	if(array==nullptr || length<=1)
		return;
	for(int i=(length>>1);i>=0;i--){
		Heapify(array,length,i);
	}
	for(int n=length;n>=1;n--)
	{
		swap(array[n-1],array[0]);
		Heapify(array,n-1,0);
	}
}


int MinOfOrder(int *arr, int left, int right)
{
	int result = arr[left];
	for(int i= left+1;i<right;i++)
	{
		if(result>arr[i])
			result = arr[i];
	}
	return result;
}


int MinOfRatateArray(int *array, int length)
{
	if(length<=1)
		return arr[0]; // 特殊情况，边界条件
	int left = 0;
	int right = length - 1;
	int mid = left;
	while (array[left]>=array[right])
	{
		if(right - left==1)
		{
			mid = right;
			break;
		}
		int mid = (left+right)/2;
		if(array[mid]==array[right] && arr[mid] == arr[left])
			return MinOfOrder(arr, left, right);
		if(array[mid]<=arr[right])
			right = mid;
		else
			left = mid;
	}
	return arr[mid];
}

int SearchInRotateArray(int *arr, int length, int target)
{
	int left = 0;
	int right = length -1;
	int mid = 0;
	while(left<=right)
	{
		int mid = left + (right-left) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] < arr[right])
		{
			if (arr[mid]<target && arr[right]>=target)
				left = mid +1;
			else
				right = mid -1;
		}
		else if(arr[mid] > arr[right])
		{
			if (arr[mid] > target && arr[left]<=target)
				right = mid -1;
			else
				left = mid +1;
		}
		else
			right --;
	}
	return -1;
}


int mySqrt(int x)
{
	if(x<2) return x;
	int left = 0, right = x;
	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(x/mid>=mid)
			left = mid + 1;
		else
			right = mid;
	}
	reutrn left -1;
}

class ListNode
{
	int val;
	ListNode* next;
	ListNode(){ val = 0; next = nullptr;}
}

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};

ListNode* MergeKSortedLists(ListNode* arr[], int length)
{
	while(length!=0)
	{
		int i=0,j=length;
		while(i<j)
		{
			arr[i]=mergeTwoSortedLists(arr[i],arr[j]);
			i++,j--;
			if(i>=j)
			{
				length = j;
			}
		}
	}
	return arr[0];
}

struct compare{
	bool operator()(const ListNode* l1, const ListNode* l2)
	{
		return l1->val>l2->val;
	}
}


ListNode* MergeKSortedLists(vector<ListNode*> &lists)
{
	priority_queue<ListNode*, vector<ListNode*>,compare> q;

	// 第一轮遍历，添加
	for(auto l:lists){
		if(l)
			q.push(l);
	}

	if(q.empty())
		return nullptr;

	ListNode* result = q.top();
	q.pop();
	if(result->next)
		q.push(result->next);
	// top->pop->push 三个步骤合一
	ListNode* tail = result;
	while(!q.empty()){
		tail->next=q.top();
		q.pop();
		tail = tail->next;
		if(tail->next)
			q.push(tail->next);
	}
	return result;
}

void preOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode)
	{
		if(pNode){
			cout<<pNode->val<<" ";
			st.push(pNode);
			pNode=pNode->left;
		}
		else{
			TreeNode* temp = st.top();
			st.pop();
			pNode = temp->right;
		}
	}
}

void inOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;			
		}
		else{
			TreeNode* temp = st.top();
			cout<<temp->val;
			st.pop();
			pNode = pNode->right;
		}
	}
}


int countPrimes(int n){
	int res = 0;
	vector<bool> isPrime(n, true);
	for(int i=2;i<n;i++){
		if(isPrime[i]){
			res++;
			for(int j=2;j*i<n;j++)
				isPrime[i*j] = false;
		}
	}
	return res;
}

int findDuplicate(int *array, int length)
{
	if (array==nullptr || length<=1)
		return -1;

	for (int i=0;i<length;i++)
	{
		if(array[i] > length-1 || array[i]<0)
			return -1;
	}

	for (int i=0;i<length;i++)
	{
		while(array[i]!=i){
			if(array[array[i]]==array[i])
				return array[i];
			swap(array[i], array[array[i]]);
		}
	}
	return -1;
}

int findDuplicate(int *array, int length)
{
	for (int i=0;i<length;i++){
		while(array[i]!=i+1){
			if(array[array[i]-1]==array[i])
				return array[i];
			swap(array[i], array[array[i]-1]);
		}
	}
	return -1;
}

int majorityElement(vector<int> & nums)
{
	int counter = 1;
	int majorInd = 0; // 首先从第一个元素开始，那么 counter = 1, majorInd=0
	for(int i=1;i<nums.size();i++){
		nums[i]==nums[majorInd]?counter++:counter--;
		if(counter==0){
			counter = 1;
			majorInd = i;
		}
	}

	counter = 0;
	for(int i=0;i<nums.size();i++){
		if(nums[i] == nums[majorInd])
			counter++;
	}

	return nums[majorInd];
}

int maxSubArray(vector<int>& nums)
{
	int max_end_here = nums[0];
	int max_so_far = nums[0];
	for(int i=1;i<nums.size();i++){
		max_end_here = max(max_end_here+nums[i],nums[i]);
		max_so_far = max(max_so_far,max_end_here);
	}
	return max_so_far;
}

vector<int> maxSubArray(vector<int>& nums)
{
	int start =0, end =0;
	int max_end_here = nums[0];
	int max_so_far = nums[0];
	int j=0;
	for(int i =1;i<nums.size();i++)
	{
		if(max_end_here<0){
			max_end_here = 0;
			j = i;
		}
		max_end_here += nums[i];
		if(max_end_here>max_so_far){
			max_so_far = max_end_here;
			start = j;
			end = i;
		}
	}

	return {start,end};
}

int maxDepth(TreeNode* root)
{
	return root == nullptr?0:max(maxDepth(root->left),maxDepth(root->right));
}


vector<double> GreedyFindBin(const double* distinct_values,
	const int* counts, int num_distinct_values, int max_bin,
	size_t total_cnt, int min_data_in_bin)
/* 
num_distinct_values: 特征去重后的数目
counts: 对应每个unique feature 的数目
*/
{
	vector<double> bin_upper_bound;
	// 特征取值数比 max_bin 数量少，直接取 distinct_values 的中间点位置，即全分
	if(num_distinct_values <= max_bin){
		bin_upper_bound.clear();
		int cur_cnt_inbin = 0; // 当前 bin 中特征点数目
		for(int i=0;i<num_distinct_values-1;i++){
			cur_cnt_inbin += counts[i];
			if(cur_cnt_inbin >= min_data_in_bin){ // 如果大于了成bin的数量要求
				auto val = GetDoubleUpperBound((distinct_values[i] + 
					distinct_values[i+1]) / 2.0);
				if (bin_upper_bound.empty() || 
					!CheckDoubleEqualOrdered(bin_upper_bound.back(),val
					))
				{
					bin_upper_bound.push_back(val);
					cur_cnt_inbin = 0;
				}
			}
		}
		// 最后会剩下一部分，单独的设立一个 bin，上界设为 inf
		cur_cnt_inbin += counts[num_distinct_values-1];
		bin_upper_bound.push_back(std::numeric_limits<double>::infinity());
	}
	else{ // 特征取值比 max_bin 来的大，说明几个特征值要共用一个 bin
		if(min_data_in_bin > 0){
			max_bin = min(max_bin, static_cast<int>(total_cnt/ min_data_in_bin));
			max_bin = max(max_bin,1);
		}
		double mean_bin_size = static_cast<double>(total_cnt) / max_bin;

		// mean size for one bin
		int rest_bin_cnt = max_bin;
		int res_sample_cnt = static_cast<int>(total_cnt);
		vector<bool> is_big_count_value(num_distinct_values, false);

		// 标记一个特征数超过 mean，因为这些特征需要单独一个 bin
		for(int i=0;i<num_distinct_values;i++){
			if(counts[i]>=mean_bin_size){
				is_big_count_value[i] = true;
				--rest_bin_cnt;
				res_sample_cnt -= counts[i];
			}
		}

		// 剩下的特征值中平均每个 bin 的取值个数
		mean_bin_size = static_cast<double>(res_sample_cnt) / rest_bin_cnt;
		vector<double> upper_bounds(max_bin, numeric_limits<double>::infinity());
		vector<double> lower_bounds(max_bin, numeric_limits<double>::infinity());

		int bin_cnt =0;
		lower_bounds[bin_cnt] = distinct_values[0];
		int cur_cnt_inbin = 0;
		for(int i=0;i<num_distinct_values-1;i++){
			if(!is_big_count_value[i]){
				res_sample_cnt -= counts[i];
			}
			cur_cnt_inbin += counts[i];
			// need a new bin, 如果当前特征是需要单独成一个 bin，或者当前几个特征计数
			//超过了 mean_bin_size，或者是下一个必须单独成列
			if(is_big_count_value[i] || cur_cnt_inbin>=mean_bin_size ||
				(is_big_count_value[i+1] && 
					cur_cnt_inbin>=max(1.0,mean_bin_size*0.5f))){
					upper_bounds[bin_cnt] = distinct_values[i];
					++bin_cnt;
					// 下一个 bin 最小就是 distinct_values[i+1]，注意这里已经 bin_cnt++
					lower_bounds[bin_cnt] = distinct_values[i+1];
					if(bin_cnt>=max_bin-1) {break;}
					cur_cnt_inbin =0;
					if(!is_big_count_value[i]){
						--rest_bin_cnt;
						mean_bin_size = res_sample_cnt/ static_cast<double>(rest_bin_cnt);
					}
				}
			}
			++bin_cnt;
			// update bin upper bound
			bin_upper_bound.clear();
			for(int i=0;i<bin_cnt-1;i++){
				auto val = GetDoubleUpperBound((upper_bounds[i]+lower_bounds[i+1])/2.0);
				if(bin_upper_bound.empty() || CheckDoubleEqualOrdered(bin_upper_bound.back()))
					bin_upper_bound.push_back(val);
			}
			bin_upper_bound.push_back(numeric_limits<double>::infinity());
		}
		return bin_upper_bound;
}


void FindBestThresholdNumerical(double sum_gradient, double sum_hessian, data_size_t num_data, double min_constraint, double max_constraint, SplitInfo* output) {
    is_splittable_ = false;
    double gain_shift = GetLeafSplitGain(sum_gradient, sum_hessian,
                                         meta_->config->lambda_l1, meta_->config->lambda_l2, meta_->config->max_delta_step);
    double min_gain_shift = gain_shift + meta_->config->min_gain_to_split;
    FindBestThresholdSequence(sum_gradient, sum_hessian, num_data, min_constraint, max_constraint, min_gain_shift, output, -1, true, false);
    FindBestThresholdSequence(sum_gradient, sum_hessian, num_data, min_constraint, max_constraint, min_gain_shift, output, 1, true, false);
    output->gain -= min_gain_shift;
    output->monotone_type = meta_->monotone_type;
    output->min_constraint = min_constraint;
    output->max_constraint = max_constraint;
  }



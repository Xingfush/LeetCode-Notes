#include<set>
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	vector<double> res;
	multiset<double> ms(nums.begin(),nums.begin()+k);
	auto mid = next(ms.begin(),k/2);
	for(int i=0;;i++){
		res.push_back((*mid+*pre(mid,1-k%2))/2);
		if(i==nums.size()) return res;
		if(nums[i]<*mid) --mid;
		if(nums[i-k]<=*mid) ++mid;
		ms.erase(ms.lower_bound(nums[i-k]));
	}
	return res;

}

#include<queue>
vector<int> maxSlidingWindow(vector<int> & nums, int k){
	vector<int> res;
	deque<int> q;
	for(int i=0;i<nums.size();i++){
		if(!q.empty() && q.front()==i-k) q.pop_front();
		while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
		q.push(nums[i]);
		if(i>=k-1)
			res.push_back(nums[q.front()]);
	}
	return res;

}

int findPeakElement(vector<int>& nums) {
	int left = 0, right = nums.size()-1;
	while(left<right){
		int mid = left+(right-left)/2;
		if(nums[mid]<nums[mid+1]) left = mid+1;
		else right= mid;
	}
	return left;

}

int findPeakElement(vector<int>& nums){
	for(int i=1;i<nums.size();i++){
		if(nums[i]<nums[i-1])
			return nums[i-1];
	}
	return nums[nums.size()-1];
}

vector<int> findPeak2D(vector<vector<int>> & matrix){
	int n = matrix.size();
	int top = 1, bottom = n-2;
	vector<int> result;
	while(top<=bottom){
		int mid = (top+bottom)/2;
		int col = findPeakElement(matrix[mid]);
		if(matrix[mid][col]<matrix[mid+1][col]) top = mid+1;
		else if(matrix[mid][col]<matrix[mid-1][col]) bottom = mid-1;
		else{
			result.push_back(mid);
			result.push_back(col);
			return result;
		}
	}
}

int majorityElement(vector<int>& nums) {
	int count = 1, candidate = nums[0];
	for(int i=1;i<nums.size();i++){
		nums[i]==candidate?count++:count--;
		if(count==0){
			candidate = nums[i];
			count = 1;
		}
	}
	count = 0;
	for(int i=0;i<nums.size();i++){
		if(candidate==nums[i]) count++;
	}
	if(count>nums.size()/2) return candidate;
}

int majorityElement(vector<int>& nums){
	int count_a = 0, count_b = 0;
	int a =0, b=0;
	for(auto num:nums){
		if(num==a) count_a++;
		else if(num==b) count_b++;
		else{
			if(count_a==0){
				count_a=1;
				a = num;
			}
			else if(count_b==0){
				count_b=1;
				a = num;
			}
			else{
				count_a--,count_b--;
			}
		}
	}
	count_a = 0,count_b=0;
	for(auto num:nums){
		if(num==a) count_a++;
		else if(num==b) count_b++;
	}
	vector<int> result;
	if(count_a>n/3) result.push_back(a);
	if(count_b>n/3) result.push_back(b);
	return result;
}













/* b站之耻，永世不忘 */

void reorderArray(vector<int>& nums)
{
	int even = 0, odd = 1, n = nums.size();
	while (even<n && odd<n) {
		while (nums[even] & 1) even += 2;
		while ((nums[odd] & 1)==0) odd += 2;
		swap(nums[even], nums[odd]);
		even += 2;
		odd += 2;
	}
}
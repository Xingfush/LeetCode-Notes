/* 将数组等分为三个连续的子数组，这三个子数组的和相等 */
/* 解题思路：
   1.首先求得数组的和，将其三等份，这里为了后面的运算，使用累加运算；
   2.再次遍历，寻找和等于三等份点的数组 */

bool canThreePartsEqualSum(vector<int>& nums, int parts = 0)
{
	int total = accumulate(nums.begin(),nums.end(),0);
	if(total%3!=0) return false;
	for(int i=0, sum=0;i<nums.size() && parts<(total!=0?2:3);i++)
	{
		sum += nums[i];
		if(sum==total/3){
			++parts;
			sum = 0;
		}
	}
	return parts == (total!=0?2:3);
}

/* 本题看似简单，实则暗藏玄机，以至于连大佬都忽视了这个边界条件，那就是
	当 totoal =0 的时候，这是 target_sum = 0, 
	例如 [-2, 2, -3, 3],如果我们只找出两份 parts，那么第三份就会为空，
	这种情况就是错误的，而且这种情况只会在 total=0 的时候出现，因为
	当 total!=0，我们找到了 两份 parts，后面一份绝对不会为空，因为数组里面肯定还有值。
	所以，对于 total!=0?2:3，对要找到的 parts 的份数做出了限制。 */


/* 解法：定一个变量 miss，表示[0,n]之间最小的不能表示的值，那么
初始化为1，此时我们能表示的范围为[0,miss)，
如果此时的 num<=miss，那么我们能够把能表示的数的范围扩大至[0,miss+num)，
上面那句话仔细理解，如果miss=4,num=3,那么miss=7，想想6怎么表示，因为[0,4)都可以表示，
我们只需要组个3再加上num不就等于6了吗，厉害啊！
如果 num>miss，那么我们此时就需要添加一个数了，为了最大限度地增加表示的数的范围，
我们加上miss 它本身，以此类推直至遍历完整的数组，我们得到结果。 */

int minPatches(const vector<int>& nums, int n){
	int miss = 1, res = 0, i = 0;
	while(miss<=n){
		if(i<nums.size() && nums[i]<=miss){
			miss += nums[i++];
		} else {
			miss += miss; // 此时必须加上一个值为miss的数
			++res;
		}
	}

	return res;
}
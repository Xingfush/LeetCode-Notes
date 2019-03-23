#include<vector>
#include<algorithm>

using namespace std;

int getUniqueDuplicates(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int result = 1;
	int pre = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] != pre)
		{
			result++;
			pre = nums[i];
		}
	}
	return result;
}

void removeDuplicates(vector<int>& nums) {
	if (nums.empty())
		return;
	int pre = nums[0];
	for (auto iter = nums.begin() + 1; iter != nums.end();)
	{
		if (*iter != pre)
		{
			pre = *iter;
			iter++;
		}
		else
		{
			iter = nums.erase(iter);
		}
	}
}

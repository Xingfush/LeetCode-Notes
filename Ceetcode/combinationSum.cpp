/* 题目1：找出所有和为target的元素组合，数组元素无重复，元素可重复使用，组合不能有重复 */
/* 使用回溯法 */ 

vector<vector<int> > combinationSum(vector<int> & candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int> > result;
	vector<int> combination;
	combinationSum(candidates, target, result, combination, 0); // 需要进行传引用的 result combination
	return result;
}


/* 这里注意begin的使用，去除重复查找，后面的元素配对时，不能再使用前面的元素 */
void combinationSum(vector<int> & candidates, int target, 
	vector<vector<int> > &result, vector<int> &combination, int begin)
{
	if(target==0)// 判断成功
	{
		result.push_back(combination);
		return;
	}
	// 开始选优搜索,target>=candidates[i]配合前面的排序，起到了提前
	for(int i=begin; i<candidates.size() && target>=candidates[i]; i++)
	{
		combination.push_back(candidates[i]);
		combinationSum(candidates, target-candidates[i], result, combination, i);
		// 继续搜索的 begin 从i 开始，表示元素可以重复使用
		combination.pop_back(candidates[i]);
	}
}

/* 题目2：数组元素有重复，元素不可重复使用 */
// trick1：排序后，遍历是必要的，遇见重复的元素，直接跳过，不做判断
// trick2：继续搜索时，begin 从i+1 开始，表示，这个元素不能重复使用

void combinationSum(vector<int> & candidates, int target, 
	vector<vector<int> > &result, vector<int> &combination, int begin)
{
	if(target==0)// 判断成功
	{
		result.push_back(combination);
		return;
	}
	// 开始选优搜索,target>=candidates[i]配合前面的排序，起到了提前
	for(int i=begin; i<candidates.size() && target>=candidates[i]; i++)
	{
		if(i==begin || candidates[i]!=candidates[i-1])
		{
			combination.push_back(candidates[i]);
			combinationSum(candidates, target-candidates[i], result, combination, i+1);
			// 继续搜索的 begin 从i 开始，表示元素可以重复使用
			combination.pop_back(candidates[i]);	
		}
	}
}


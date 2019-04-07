vector<vector<int> > combinationSum(vector<int> & candidates, int target){
	vector<int> combination;
	vector<vector<int> > result;
	sort(candidates.begin(),candidates.end());
	combinationSum(candidates, target, combination, result, index);
	return result;
}

void combinationSum(vector<int>& candidates, int target, vector<int> combination, vector<vector<int>>& result, int index){
	if(target==0){
		result.push_back(combination);
		return 0; // 非负数组，一次遍历只有一个可能
	}
	for(int i=index;i<candidates.size() && target>=candidates[i];i++){
		if(i==index || candidates[i]==candidates[i-1]){ // 后判别
			combination.push_back(candidates[i]);
			combinationSum(candidates, target-candidates[i], combination, result, i+1);
			combination.pop_back();
		}
	}
}



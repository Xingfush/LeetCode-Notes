Node* SortedMerge(Node* a, Node* b)
{
	Node* result=NULL;

	// Base cases
	if (a==NULL)
		return b;
	else if(b==NULL)
		return a;

	// recur
	if(a->data<b->data)
	{
		result=a;
		result->next=SortedMerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=SortedMerge(a,b->next);
	}
	return result;
}

Node* mergeKLists(Node* arr[], int last)
{
	// Leetcode出错原因，没有处理arr为空的时候
	// 如果传入的是 vector<Node*> list,那么
	// if(list.empty()) return nullptr

	while(last!=0)
	{
		int i=0,j=last;
		//(i,j) forms a pair
		while(i<j)
		{
			arr[i]=SortedMerge(arr[i],arr[j]);
			i++,j--;
			if(i>=j)
				last=j;
		}
	}
	return arr[0]
}

//另一种组合的解法是，从开头两两组合
//但是 list.erase 的用法导致了 vector 的整体移动，时间复杂度会升高

Node* mergeKLists(vector<Node*> &lists)
{
	if(lists.empty())
		return nullptr;
	while(list.size()>1)
	{
		lists.push_back(SortedMerge(list[0],list[1]));
		list.erase(list.begin());
		list.erase(list.begin());
	}
	return lists.front();
}


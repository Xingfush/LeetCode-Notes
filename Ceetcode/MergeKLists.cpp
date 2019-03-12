struct Node
{
	int data;
	Node* next;
};

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


// 使用 优先队列 完成
struct compare{
	bool operator()(const Node* l, const Node* r)
	{
		return l->val>r->val;
	}
}

Node* mergeKLists(vector<Node*> &lists)
{
	// 定义priority_queue
	priority_queue<Node*, vector<Node*>,compare> q;

	// 第一轮遍历
	for (auto l:lists)
	{
		if(l)
			q.push(l);
	}

	if(q.empty()) //如果为空
		return nullptr;

	Node* result=q.top();
	q.pop();
	if(result->next) //如果不是单元素的
		q.push(result->next);
	// top->pop->push，3个步骤是一体的，不能分割
	// result是合并后新链表的头结点，不动
	// tail不断地移动

	Node* tail=result;
	while(!q.empty()){
		tail->next=q.top(); // 只有这一句话是真正改变结点指向，构建新链表的
		q.pop();
		tail=tail->next;
		if(tail->next)
			q.push(tail->next);
	}

}

// 使用优先队列的另一种解法
Node *mergeKLists(vector<Node*> &lists)
{
	priority_queue<Node*,vector<Node*>,compare> heap;
	Node* result=new Node(0); // 新建一个空的头结点
	Node* tail = result;
	
	int k =lists.size();

	for(int i=0;i<k;i++)
		if(lists[i])
			heap.push(lists[i])

	// tail在不同的LinkList 上来回变
	while(!heap.empty())
	{
		tail->next=heap.top();
		tail = curNode->next;
		heap.pop();
		if(tail->next)
			heap.push(tail->next);
	}
	return result->next;
}

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
		if(tail->next) // 入队的时候一定要事先检查
			q.push(tail->next);
	}
	return result;

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

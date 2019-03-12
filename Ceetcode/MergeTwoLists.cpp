ListNode* MergeTwoLists(ListNode* a, ListNode* b)
{
	ListNode* result=nullptr;

	if(a==nullptr)
		return b
	if(b==nullptr)
		return a

	if(a->val<b->val)
	{
		result= a;
		result->next = MergeTwoLists(a->next,b);
	}
	else
	{
		result= b;
		result->next = MergeTwoLists(a,b->next);
	}
	return result;
}
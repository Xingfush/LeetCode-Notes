LinkNode* hasCircle(LinkNode* head)
{
	if(head==nullptr||head->next==nullptr)
		return nullptr;

	LinkNode *slow=head, *fast=head;
	while(fast!=nullptr && fast->next!=nullptr)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(fast==slow)
			return fast;
	}
	return nullptr;
}

LinkNode* detectCircle(LinkNode* head)
{
	LinkNode* meetingNode=hasCircle(head);

	if(meetingNode==nullptr)
		return nullptr;

	int nodesInLoop=1;
	LinkNode* temp=meetingNode;
	while(temp->next!=meetingNode)
	{
		temp=temp->next;
		++nodesInLoop;
	}

	LinkNode* pAhead=head,*pBehind=head;

	for(int i=0;i<nodesInLoop;i++)
		pAhead=pAhead->next;

	while(pAhead!=pBehind)
	{
		pAhead=pAhead->next;
		pBehind=pBehind->next;
	}

	return pAhead;

}
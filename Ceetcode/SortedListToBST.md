### 排序链表转换为二叉搜索树

这一题是将排序链表转换为二叉搜索树，对比之前的题目Sorted Array to BST，其不同点在于对于 Array 来说，通过索引访问元素非常容易，因而最简单的思路就是使用层序遍历，从上层往下层建立结点，使用分治法的思想。利用二叉搜索树最本质的特征，左孩子小于中间结点值，右孩子大于中间结点值。

具体的解如下：

```c++
using iter=vector<int>::const_iterator; //使用常量迭代器，有针对性

TreeNode* sortedArrayToBST(vector<int> & nums)
{
    if(nums.empty())
        return nullptr;
    return buildBST(nums.begin(),nums.end()); //传递STL数组的标准方式
}

TreeNode* buildBST(iter b, iter e)
{
    if(b>=e) // 左开右闭的判别条件
        return nullptr;
    iter m = b +(e-b)/2;
    TreeNode* root = new TreeNode(*m);
    root->left = buildBST(b,m);
    root->right = buildBST(m+1,e);
    
    return root;
}
```

但是对于 Convert sorted list to BST 的问题，由于链表的按索引访问是非常困难的，这时我们有两种选择：

1. 找到访问链表中点元素的方式：
   1. 使用快慢指针；
   2. 建立一个`vector<ListNode*> vec`来保存链表的所有元素，使其可以按照array的方式访问；

2. 从中序遍历等于排序这个性质入手。

首先要体会中序遍历的真正含义，中序遍历是一种访问树的方式，这个访问可以代表删除，建立，赋值等不同形式的操作，中序遍历只是一种访问方式，中序遍历和前序、后序相比最大的性质就是中序遍历的输出是排序数组。这里的排序和sorted list的概念刚好对应，如果我们建立树的方式是中序的，那么结点建立的顺序肯定是排序数组的顺序，每建立一个结点，就访问一个sorted list的元素，然后建立下一个结点，访问下一个元素。很棒，建立结点的顺序和链表的顺序刚好一样，也就代表我们不需要刻意的每次为新建的结点从链表中找元素了。二叉树的建立按照中序方式是从底向上bottom-up，但是前向递归的时候，数组是对半划分的，划分的时候具体划分哪些元素我们是不知道的，只是使用其个数进行代表，具体建立的时候会自动从链表按顺序取。

具体的代码如下：

```c++
int count(ListNode* head){ // 统计链表的元素个数
    return if(head)?1+count(head->next):0;
}

TreeNode* buildBST(ListNode* &head,int n)
{
    if(n<=0)
        return nullptr；
        
    TreeNode* left=buildBST(head,n/2);
    TreeNode* root=new TreeNode(head->val);
    root->left = left;
    head=head->next;
    root->right = buildBST(head,n-n/2-1);
    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    int n = count(head);
    return build(&head,n);
}
```

这里有几个要点需要注意：

1. `buildBST(ListNode* &head)`，这里的引用一定不能少，每建立一个结点 `head`都会向后移一次，如果不加引用，那么函数使用按值传递，改变的只是`head`的副本，无法改变`head`，因此要使用引用；
2. `buildBST(ListNode* &head, int n)` ，这里的`n`代表的就是元素的个数的意思，虽然不知道元素具体将会是谁，但是要根据元素个数来递归，这里可以理解为就是一个占位的作用。从此，可以看出，分析一个变量的边界条件时，首先要明确这个变量到底代表什么含义。

这种方法使用中序遍历建立，时间复杂度为$O(n)$。


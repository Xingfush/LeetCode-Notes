/* 解题思路：多数投票算法 Boyer-Moore Algorithm
    问题描述：对于一个无序的数组找出一个出现次数大于n/2的元素，可能不存在。
    思路1：先排序，找到中间位置的元素，然后遍历一遍，看是否确实是出现次数大于n/2
        时间复杂度 O(nlgn)，空间复杂度 O(1)
    思路2：使用 hash 表，遍历一次进行统计，时间复杂度为 O(n)，空间复杂度为 O(n)
    思路3：多数投票法，维持两个变量 candidate 和 count，分别是候选元素和出现次数
    两次遍历：1.是 candidate则count++，否 count--，至 count==0,更新 candidate，count reset to 1
             2.判断 candidate出现是否确实为 n/2 次 */

int majorityElement(vector<int>& nums) {
    int counter = 1;
    int MajorInd = 0;
    for(int i=1;i<nums.size();i++){
        nums[i]==nums[MajorInd]?counter++:counter--;
        if(counter==0){
            counter =1;
            MajorInd = i;
        }
    }
    return nums[MajorInd];
}

/* 问题2：对于一个无序数组，找出出现次数大于 n/3 次的元素
    设置2个候选 candidate，只有当 元素都非这两个 candidates 时才会 counter_a--,couter_b-- */

vector<int> majorityElement(vector<int>& nums) {
    int a =0, counter_a = 0;
    int b =0, counter_b = 0;
    for(auto num:nums){
        if(num==a) counter_a++;
        else if(num==b) counter_b++; // 注意这里是 else if 的关系，即使 a=b，这里也是当做不知道 a=b，看做两个不同的元素
        else{
            if(counter_a==0){
                counter_a=1;
                a=num;
            }
            else if(counter_b==0){
                counter_b=1;
                b=num;
            }
            else{ // 只有当 a,b 都不为零，不用重新设置时，才会计数减1
                 counter_a--,counter_b--;
            }
        }
    }
    counter_a=0,counter_b=0;
    for(auto num:nums){
        if(a==num) counter_a++;
        else if(b==num) counter_b++;
    }
    vector<int> result;
    if(counter_a>nums.size()/3) result.push_back(a);
    if(counter_b>nums.size()/3) result.push_back(b);
    return result;
}
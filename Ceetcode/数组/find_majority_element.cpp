/* 解题思路：多数投票算法 Boyer-Moore Algorithm
    问题描述：对于一个无序的数组找出一个出现次数大于n/2的元素，可能不存在。
    思路1：先排序，找到中间位置的元素，然后遍历一遍，看是否确实是出现次数大于n/2
        时间复杂度 O(nlgn)，空间复杂度 O(1)
    思路2：使用 hash 表，遍历一次进行统计，时间复杂度为 O(n)，空间复杂度为 O(n)
    思路3：多数投票法，维持两个变量 candidate 和 count，分别是候选元素和出现次数
    两次遍历：1.是 candidate则count++，否 count--，至 count==0,更新 candidate，count reset to 1
             2.判断 candidate出现是否确实为 n/2 次 */

int FindMajorityElement(int* array, int length){
    // 这里缺少异常处理机制，待补充
    
    int ind = 0, counter = 1;
    for(int i=1;i<length;i++){
        array[i]==array[ind]?counter++:counter--;
        if(counter==0){
            counter=1;
            ind=i;
        }
    }

    return array[ind];
}

/* 问题2：对于一个无序数组，找出出现次数大于 n/3 次的元素
    设置2个候选 candidate，只有当 元素都非这两个 candidates 时才会 counter_a--,couter_b-- */

vector<int> FindMajorityElement(const vector<int>& nums){
    int a = 0, b = 0;
    int counter_of_a = 0, counter_of_b = 0;
    for(int x:nums){
        if(x==a) counter_of_a++;
        else if(x==b) counter_of_b++;
        else{
            if(counter_of_a==0){
                a=x;
                counter_of_a=1;
            }
            else if(counter_of_b==0){
                b=x;
                counter_of_b=1;
            }
            else{
                counter_of_a--,counter_of_b--;
            }
        }
    }

    counter_of_a=0,counter_of_b=0;
    for(auto x:nums){
        if(x==a) counter_of_a++;
        else if(x==b) counter_of_b++;
    }
    vector<int> result;
    if(counter_of_a>=nums.size()/3) result.push_back(a);
    if(counter_of_b>=nums.size()/3) result.push_back(b);

    return result;
}

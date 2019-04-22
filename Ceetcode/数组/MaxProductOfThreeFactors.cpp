/* 本题的思想就是：最大三元素乘积肯定是 最大三数乘积 或 最大数和最小两数的乘积和，
    证明很简单，只要分全负、全正、正负具有三种情况即可

本题的亮点是，求取 最大三数和最小两数的 代码技巧。 */

int maximumProduct(vector<int>& nums) {
    int mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
    int mn1=INT_MAX,mn2=INT_MAX;
    for(int num:nums){
        if(num>mx1){  // 是否大于最大，是则逐个降级，更新
            mx3=mx2,mx2=mx1,mx1=num;
        }
        else if(num>mx2){   // 是否大于第二大
            mx3=mx2,mx2=num;
        }
        else if(num>mx3){ // 
            mx3=num;
        }
        if(num<mn1){ // 是否小于最小
            mn2=mn1,mn1=num;
        }
        else if(num<mn2){
            mn2=num;
        }
    }
    return max(mx1*mx2*mx3,mx1*mn1*mn2);
}

/* 一定要注意五个判别条件，最大值内部使用 if else if，最小值和最大值一定要分开使用 if
因为当最大三元素和最小两个元素可能发生重叠。 */

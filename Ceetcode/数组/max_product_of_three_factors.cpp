/* 本题的思想就是：最大三元素乘积肯定是 最大三数乘积 或 最大数和最小两数的乘积和，
    证明很简单，只要分全负、全正、正负具有三种情况即可

本题的亮点是，求取 最大三数和最小两数的 代码技巧。 */

int MaximumProduct(int* array, int length){
    int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for(int i=0;i<length;i++){
        if(array[i]>mx1){
            mx3 = mx2, mx2 = mx1, mx1 = array[i];
        }
        else if(array[i]>mx2){
            mx3 = mx2, mx2 = array[i];
        }
        else if(array[i]>mx3){
            mx3 = array[i];
        }

        if(array[i]<mn1){
            mn2 = mn1, mn1 = array[i];
        }
        else if(array[i]<mn2){
            mn2 = array[i];
        }
    }

    return max(mx1*mx2*mx3, mx1*mn1*mn2);
}

/* 一定要注意五个判别条件，最大值内部使用 if else if，最小值和最大值一定要分开使用 if
因为当最大三元素和最小两个元素可能发生重叠。 */

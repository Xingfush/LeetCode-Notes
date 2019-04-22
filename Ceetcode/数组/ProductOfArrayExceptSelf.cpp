/* 思想比较经典，双向遍历，例如 [1 2 3 4]，那么
    forwards:  [1 1 2 6]
    backwards: [24 12 4 1]
此时，直接使用 forwards[i]*backwards[i]，边界条件自然而然地解决了 */

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> forwards(n,1),backwards(n,1),res(n,1);
    for(int i=1;i<n;i++){
        forwards[i]=forwards[i-1]*nums[i-1];
    }
    for(int j=n-2;j>=0;j--){
        backwards[j]=backwards[j+1]*nums[j+1];
    }
    for(int k=0;k<n;k++){
        res[k]= forwards[k]*backwards[k];
    }
    return res;
}
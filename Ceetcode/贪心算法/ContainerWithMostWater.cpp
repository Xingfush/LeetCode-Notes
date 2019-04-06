/* 设定左右指针不断向中间移动，每次从短板开始移动，符合贪心的思想 */

int maxArea(vector<int>& height) {
    int left =0,right =height.size()-1;
    int res=0;
    while(left<right){
        res = max(res,min(height[left],height[right])*(right-left));
        height[left]<height[right]?++left:--right; // 移动方向的确定是关键点
    }
    return res;
}
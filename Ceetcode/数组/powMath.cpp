/* 题目虽小，很多细节必须注意：
	1.时间复杂度上必须使用分治法，需要注意 i 为奇数的情况，res += x;
	2.循环的条件 i=n;i!=0;i/=2，不断二分，注意 i 可能为负数，所以必须使用 i!=0，而不是 i>0;
	3.当 n<0 的时候的处理； */

double myPow(double x, int n) {
    double res =1.0;
    for(int i=n;i!=0;i/=2){
        if(i%2!=0) res *=x;
        x *=x;
    }
    return n<0?1/res:res;
}
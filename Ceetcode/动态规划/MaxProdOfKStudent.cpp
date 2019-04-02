/* 一道牛客上面的笔试真题 */

int main()
{
	int n;
	cin >> n; // 输入学生的个数
	vector<long long> a(n+1,0); // 动态数组
	for(int i=1;i<n+1;i++) // 最好是不要使用0索引，更加直观
		cin >> a[i];
	int k,d; // 输入其他参数
	cin >> k>> d;

	vector<vector<long long> > dp_max(n+1, vector<long long>(k+1,0));
	vector<vector<long long> > dp_min(n+1, vector<long long>(k+1,0)); // 同样地k也是1索引
	long long res=	LLONG_MIN;

	for(int i=1;i<=n;i++)// 以i 个结尾的 j 个学生
	{
		dp_max[i][1] = dp_min[i][1] = a[i]; // 初始化为一个学生的能力
		for(int j=2;j<=k && j<=i;j++) // 从两个学生开始，出现乘法
		{
			for(int l=1;l<=d && i-l>=1;l++)
			{
				dp_max[i][j]=max(dp_max[i][j],
					max(dp_max[i-l][j-1]*a[i],dp_min[i-l][j-1]*a[i]));// 涉及到正负问题
				dp_min[i][j]=min(dp_min[i][j],
					min(dp_max[i-l][j-1]*a[i],dp_min[i-l][j-1]*a[i]));
			}
		}
		res = max(res,dp_max[i][k]);
	}
	cout<<res<<endl;
}


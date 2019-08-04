/* 读取一行任意长度输入 */

vector<string> strs;
string str;
do {
    cin >> str;
    strs.push_back(str);
} while (cin.get() != '\n');


/* 读取多行任意长度输入 */

vector<vector<string>> strs;
vector<string> str;
int m;
cin >> m;
cin.get(); // 把行数输入后面的回车键从缓存区去掉
string a;
for (int i = 0; i < m; i++)
{
    do { 
        cin >> a;
        str.push_back(a);
    } while (cin.get() != '\n');
    strs.push_back(str);
}

/* 读取多行固定长度输入 */

int m, n;
cin >> m >> n;
vector<vector<int>> nums(m, vector<int>(n, 0));
for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        cin >> nums[i][j];
    }
}
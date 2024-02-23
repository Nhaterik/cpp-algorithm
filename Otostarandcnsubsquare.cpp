#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> p[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void out(vector<vector<char>> &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
}
void Turn(vector<vector<char>> &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] != '*')
                s[i][j] = '1';
        }
    }
}
void transf(int i, int j, vector<vector<char>> &s, int n)
{
    s[i][j] = '*';
    for (int k = 0; k < 4; k++)
    {
        int in = i + p[k].first;
        int jn = j + p[k].second;
        if (in >= 0 && in < n && jn >= 0 && jn < n && s[in][jn] == 'O')
            transf(in, jn, s, n);
    }
}
void createIsland(vector<vector<char>> &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == 'O')
            transf(i, 0, s, n);
        if (s[i][n - 1] == 'O')
            transf(i, n - 1, s, n);
        if (s[0][i] == 'O')
            transf(0, i, s, n);
        if (s[n - 1][i] == 'O')
            transf(n - 1, i, s, n);
    }
    Turn(s, n);
}
int countSquare(vector<vector<char>> &s, vector<vector<int>> &dp, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == '1')
            dp[i][0] = s[i][0] - '0';

        else
            dp[i][0] = 0;
       
        if (s[0][i] == '1')
            dp[0][i] = s[0][i] - '0';

        else
            dp[0][i] = 0;
      
    }
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n;j++)
       {
        if(s[i][j]=='1')
        dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
        else 
        dp[i][j]=0;
       }
    }
    int res=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
res=max(dp[i][j],res);
    }
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<vector<char>> s(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(n));
        createIsland(s, n);
      cout<<  countSquare(s,  dp, n)<<endl;
    }
    return 0;
}

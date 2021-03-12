// Simple 2d dp
// code is self explanatory
#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
int main()
{
    int h,w;
    cin>>h>>w;
    vector<string> grid(h);
    for(int i=0;i<h;i++)
    {
        cin>>grid[i];
    }
    vector<vector<int>> dp(h,vector<int>(w,0));
    dp[0][0]=1;
    for(int i=1;i<w;i++)
    {
        if(grid[0][i]=='.')
        {
            dp[0][i]=dp[0][i-1];
        }
    }
    for(int i=1;i<h;i++)
    {
        if(grid[i][0]=='.')
        {
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int i=1;i<h;i++)
    {
        for(int j=1;j<w;j++)
        {
            if(grid[i][j]=='.')
            {
                dp[i][j]=(dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}
// Description :
// 3 arrays of activities are given
// Condition is, one can't select 2 or more activities from the
// same stream consecutively
// Objective is to find the max points gained

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(3,0)),dp(n, vector<int>(3,0));
    for(int i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        if(i==0)
        {
            dp[0][0] = v[0][0];
            dp[0][1] = v[0][1];
            dp[0][2] = v[0][2];
        }
        else
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(j!=k)
                    {
                        dp[i][j] = max(dp[i][j], v[i][j] + dp[i-1][k]);
                    }
                }
            }
        }
    }
    cout<<*max_element(dp[n-1].begin(),dp[n-1].end())<<endl;
}
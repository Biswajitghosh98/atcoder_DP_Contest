/*
N coins each with prob pi of getting heads. Find total probability of getting more heads than tails.
Hint : dp state -> dp[heads till now][i] 
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<double> p(n);
    vector<vector<double>> dp(n+1,vector<double>(n,0));
    for(int i=0;i<n;i++)cin>>p[i];
    dp[0][0] = 1.0 - p[0];
    dp[1][0] = p[0];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=i+1;j++)
        {
            dp[j][i+1] += dp[j][i]*(1.0 - p[i+1]);
            dp[j+1][i+1] += dp[j][i]*(p[i+1]);
        }
    }
    double ans=0;
    for(int i=(n+1)/2;i<=n;i++)
    {
        ans+=dp[i][n-1];
    }
    cout<<setprecision(12)<<ans<<endl;
}
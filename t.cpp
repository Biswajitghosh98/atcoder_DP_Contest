//Explnation : https://codeforces.com/blog/entry/64250?#comment-482526
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[1][1] = 1;
    string s;
    cin>>s;
    for(ll i=1;i<=s.size();i++)
    {
        for(ll j=1;j<=i+1;j++)
        {
            if(s[i-1]=='>')
            {
                dp[i+1][j] = (dp[i][i] - dp[i][j-1] + MOD)%MOD;
            }
            else
            {
                dp[i+1][j] = dp[i][j-1];
            }
            dp[i+1][j] += dp[i+1][j-1];
            dp[i+1][j] %= MOD;
        }
    }
    cout<<dp[n][n]<<endl;
}
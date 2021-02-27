// Problem statement same as Knapsack 1
// The only difference being, here W is very large of the scale 1e9
// but, vi's are max 1e3 and N is max 100

// Approach :
// O(sum(v[i])*N) max value of v whose weight is less than or equal to W

#include <bits/stdc++.h>
using namespace std;
#define prv(a) for(auto x:a){cout<<x<<" ";}cout<<endl;
typedef long long int ll;
int main()
{
    ll n,W;
    cin>>n>>W;
    vector<ll> w(n+1,0),v(n+1,0);
    ll tmp=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        tmp+=v[i];
    } 
    vector<vector<ll>> dp(tmp+1,vector<ll>(n+1,-1));
    ll ans=0;
    for(ll i=0;i<=n;i++)dp[0][i]=0;
    for(ll i=0;i<=tmp;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(j>1)
            {
                if(dp[i][j-1]!=-1)
                {
                    if(dp[i][j]==-1)dp[i][j]=dp[i][j-1];
                    else dp[i][j]=min(dp[i][j],dp[i][j-1]);
                }
            }
            if(i-v[j]>=0)
            {
                if(dp[i-v[j]][j-1]!=-1)
                {
                    if(dp[i][j]==-1)dp[i][j]=dp[i-v[j]][j-1] + w[j];
                    else dp[i][j] = min(dp[i][j],dp[i-v[j]][j-1] + w[j]);
                }
            }
            if(dp[i][j]!=-1 && dp[i][j]<=W)ans=i;
        }
        // prv(dp[i])
    }
    cout<<ans<<endl;
}
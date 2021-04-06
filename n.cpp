#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll> tmp(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        tmp[i]+=a[i-1]+tmp[i-1];
    }
    vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));
    for(ll i=0;i<n;i++)dp[i][i] = 0;
    for(ll len=2;len<=n;len++)
    {
        for(ll i=0;i+len-1<n;i++)
        {
            for(ll j=i;j<i+len-1;j++)
            {
                dp[i][i+len-1] = min(dp[i][i+len-1], dp[i][j] + dp[j+1][i+len-1] + tmp[i+len] - tmp[i]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
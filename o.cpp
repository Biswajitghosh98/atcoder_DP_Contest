//hint : basics of bitmask + dp
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1000000007;
ll func(vector<vector<ll>> &dp, vector<vector<ll>> &a, ll idx, ll mask, ll n)
{
    if(dp[idx][mask]!=-1)return dp[idx][mask];
    dp[idx][mask]=0;
    for(ll i=0;i<n;i++)
    {
        if(a[idx][i] == 1 && ((1<<i)&mask) == 0)
        {
            dp[idx][mask]+=func(dp,a,idx+1,mask ^ (1<<i), n);
            dp[idx][mask]%=MOD;
        }
    }
    return dp[idx][mask];
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll> (n));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(1<<n,-1));
    ll num = (1<<n)-1;
    for(ll i=0;i<n;i++)
    {
        if(a[n-1][i]==1)
        {
            dp[n-1][num^(1<<i)] = 1;
        }
    }
    cout<<func(dp,a,0,0,n)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define endl "\n"
ll max(ll a, ll b)
{
    if(a>b)return a;
    return b;
}
ll func(ll t, vector<ll> &dp, vector<ll> &precalc)
{
    if(dp[t]!=-1)return dp[t];
    ll temp;
    temp = max(precalc[t],0);
    for(ll x=t;x>0;x=(x-1)&t)
    {
        if(x==t)continue;
        temp = max(temp, func(x,dp,precalc) + func(t^x,dp,precalc));
    }
    return dp[t]=temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<ll> precalc(1<<n ,0);
    for(ll i=1;i<(1<<n);i++)
    {
        vector<ll> v;
        for(ll j=0;j<n;j++)
        {
            if((i&(1<<j)) != 0)
            {
                v.pb(j);
            }
        }
        for(ll j=0;j<v.size();j++)
        {
            for(ll k=j+1;k<v.size();k++)
            {
                precalc[i]+=a[v[j]][v[k]];
            }
        }
    }
    vector<ll> dp(1<<n,-1);
    for(ll i=0;i<n;i++)dp[1<<i]=0;
    ll ans = func((1<<n)-1,dp,precalc);
    cout<<ans<<endl;
}
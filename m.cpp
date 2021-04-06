//ref : Demoralizer
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vl vector<ll>
ll MOD = 1e9+7;
ll min(ll a, ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(n,vector<ll>(k+1,0));
    vl a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<=a[0];i++)dp[0][i]=1;
    for(ll i=0;i<n;i++)dp[i][0]=1;
    for(ll i=1;i<n;i++)
    {
        vl tmp(k+1,0);
        tmp[0] = dp[i-1][0];
        for(ll j=1;j<=k;j++)
        {
            tmp[j]+=dp[i-1][j] + tmp[j-1];
            tmp[j]%=MOD;
        }
        for(ll j=1;j<=k;j++)
        {
            if(j<=a[i])
            {
                dp[i][j] += tmp[j];
                dp[i][j]%=MOD;
            }
            else
            {
                dp[i][j] += (MOD + tmp[j] - tmp[j-a[i]-1]);
                dp[i][j] %= MOD;
            }
        }
    }
    cout<<dp[n-1][k]<<endl;
}
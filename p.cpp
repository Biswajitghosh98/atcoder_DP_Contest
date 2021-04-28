#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1000000007;
#define pb push_back
ll func(ll src, ll s,vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &dp)
{
    if(dp[s]!=-1)return dp[s];
    ll a=1,b=1;
    for(auto x:adj[s])
    {
        if(x!=src)
        {
            a *= func(s,x,adj,vis,dp);
            a %= MOD;
            for(auto y : adj[x])
            {
                if(y!=s)
                {
                    b*= func(x,y,adj,vis,dp);
                    b%=MOD;
                }
            }
        }
    }
    return dp[s] = (a + b)%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1,vector<ll>());
    vector<bool> vis(n+1,false);
    vector<ll> dp(n+1,-1);
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i=2;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            dp[i]=2;
        }
    }
    cout<<func(-1,1,adj,vis,dp)<<endl;
}
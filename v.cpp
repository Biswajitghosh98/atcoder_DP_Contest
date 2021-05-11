#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define endl "\n"
ll m;
ll func(ll s, vector<ll> &dp, vector<ll> &par, vector<vector<ll>> &adj)
{
    if(dp[s]!=-1)return dp[s];
    dp[s] = 1;
    for(auto x:adj[s])
    {
        if(x!=par[s])
        {
            par[x] = s;
            dp[s]*=(func(x,dp,par,adj) + 1);
            dp[s]%=m; 
        }
    }
    return dp[s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1,vector<ll>());
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> dp1(n+1,-1), dp2(n+1,-1), par(n+1,-1);
    func(1,dp1,par,adj);
    vector<vector<ll>> children(n+1,vector<ll>());
    vector<bool> tempvis(n+1,false);
    queue<ll> q;
    q.push(1);
    while(!q.empty())
    {
        ll s = q.front();
        tempvis[s] = true;
        q.pop();
        for(auto x:adj[s])
        {
            if(tempvis[x]==false)
            {
                children[s].pb(x);
                q.push(x);
            }
        }
    }
    vector<vector<ll>> prefix_prod, suffix_prod;
    for(ll i=0;i<=n;i++)
    {
        if(children[i].size()!=0)
        {
            sort(children[i].begin(),children[i].end());
        }
        vector<ll> tempvec(children[i].size()+2,1);
        prefix_prod.pb(tempvec);
        suffix_prod.pb(tempvec);
        for(ll j=1;j<=children[i].size();j++)
        {
            prefix_prod[i][j]*=(prefix_prod[i][j-1]*(dp1[children[i][j-1]]+1));
            prefix_prod[i][j]%=m;
        }
        for(ll j=children[i].size();j>=1;j--)
        {
            suffix_prod[i][j]*=(suffix_prod[i][j+1]*(dp1[children[i][j-1]]+1));
            suffix_prod[i][j]%=m;
        }
    }
    vector<bool> vis(n+1,false); 
    // func2(1,dp2,dp1,par,children,prefix_prod,suffix_prod,vis);
    dp2[1] = 1;
    while(!q.empty())q.pop();
    q.push(1);
    while(!q.empty())
    {
        ll s = q.front();
        vis[s] = true;
        q.pop();
        for(auto x:adj[s])
        {
            if(vis[x]==true)continue;
            ll idx = (ll)(lower_bound(children[s].begin(),children[s].end(),x) - children[s].begin()) + 1;
            ll tmp = 1;
            tmp*=prefix_prod[s][idx-1];
            tmp%=m;
            tmp*=suffix_prod[s][idx+1];
            tmp%=m;
            dp2[x] = 1 + dp2[s]*tmp;
            dp2[x]%=m;
            q.push(x);
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<((dp1[i]*dp2[i])%m)<<endl;
    }

}
// Knapasack 1 :
// N items are given and the i'th item has weight wi and value vi
// tha capacity of the knapsack is W
// Find max possible sum of values 

// Approach :
// The ith object can either be included or discared
// starting from the first item, if we branch out by either selecting an element or 
// discarding an element, we are essentially covering all the cases that are present with us
// which would be pow(2,N)
// We can see that for a good number of cases, the subtrees repeat itself
// brute force TC : O(N*pow(2,N))
// TC dp based approach : O(N*W)
// so if W<<pow(2,N) (here N=1e5 and W=100 max so this holds)

//Relation dp[w][i] = max(dp[w][i-1], dp[w-v[i]][i-1] + v[i])

#include <bits/stdc++.h>
using namespace std;
#define prv(a) for(auto x:a) {cout<<x<<" ";}cout<<endl;
typedef long long int ll;
int main()
{
    ll n,W;
    cin>>n>>W;
    vector<ll> w(n+1,0),v(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    vector<vector<ll>> dp(W+1, vector<ll>(n+1,0));
    for(ll i=0;i<=W;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i-w[j]>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-w[j]][j-1] + v[j]);
            }
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    cout<<*max_element(dp[W].begin(),dp[W].end())<<endl;
}
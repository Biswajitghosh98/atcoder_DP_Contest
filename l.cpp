/*
Description :  2 players, select elements turn by turn from extremeties of an array, find the difference of their scores
Ans : Logic explained in state transition below
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
ll max(ll a, ll b)
{
    return (a>b)?a:b;
}
int main()
{
    //dp[i][j] : 
    /* 
        dp[i][j]= max(a[i] + sum(i+1..j)-dp[i-1][j], a[j] + sum(i..j-1)-dp[i][j-1])
    */
   ll n;
   cin>>n;
   vector<vector<ll>> dp(n,vector<ll>(n,-1));
   vector<ll> sm(n+1,0),a(n);
   for(ll i=0;i<n;i++)
   {
       cin>>a[i];
       sm[i+1]+=a[i]+sm[i];
       dp[i][i] = a[i];
   }
   for(ll step=2;step<=n;step++)
   {
       for(ll i=0;i+step-1<n;i++)
       {
           dp[i][i+step-1] = max(a[i] + sm[i+step]-sm[i+1] - dp[i+1][i+step-1],a[i+step-1] + sm[i+step-1]-sm[i] - dp[i][i+step-2]);
       }
   }
   ll x = dp[0][n-1];
   ll y = sm[n] - x;
   cout<<x-y<<endl;
}
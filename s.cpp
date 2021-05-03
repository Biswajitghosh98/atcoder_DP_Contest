#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define prv(a) for(auto x:a){cout<<x<<" ";}cout<<endl;
ll MOD = 1000000007;
ll d;
ll func(ll pos, ll rem, ll flag, vector<ll> &num, vector<vector<vector<ll>>> &dp)
{
    if(pos==num.size())return 0;
    if(dp[pos][rem][flag]!=-1)return dp[pos][rem][flag];
    ll LMT;
    if(flag==1)LMT = num[pos];
    else LMT = 9;
    if(pos==num.size()-1)
    {
        ll tmp=0;
        for(ll i=0;i<=LMT;i++)
        {
            if((rem-i+10*d)%d==0)tmp+=1;
        }
        return dp[pos][rem][flag] = tmp;
    }
    ll ans = 0;
    for(ll i=0;i<=LMT;i++)
    {
        if(i<LMT)
        {
            ans += func(pos+1,(rem-i+10*d)%d, 0, num, dp);
            ans %= MOD;
        }
        else
        {
            ans += func(pos+1,(rem-i+10*d)%d, flag, num, dp);
            ans %= MOD;
        }
    }
    return dp[pos][rem][flag] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    cin>>d;
    vector<ll> num((int)s.size(),0);
    for(ll i=0;i<(int)s.size();i++)
    {
        num[i] = (ll)(s[i]-'0');
    }
    // prv(num)
    //position,remainder,flag,num,dp
    vector<vector<vector<ll>>> dp(num.size(),vector<vector<ll>>(d,vector<ll>(2,-1))); 
    ll ans = (func(0,0,1,num,dp)-1+MOD)%MOD;
    cout<<ans<<endl;
}
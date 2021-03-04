// Description : standard lcs with backtrack
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = max(max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1)),dp[i][j]);
            }
            else dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i][j]);
        }
    }
    int i=s1.size(), j=s2.size();
    string ans="";
    while(i>0 && j>0)
    {
        int mx=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
        if(mx==dp[i][j])
        {
            if(dp[i-1][j]==mx)i-=1;
            else j-=1;
        }
        else
        {
            ans.pb(s1[i-1]);
            i-=1;
            j-=1;
        }
    }  
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl; 
}
// Description : A sorted array 'a' is given which contains number of elements that can be removed with initially k elements
// One needs to identify which player wins (the one who fails to make a move loses)
// Solution : Simply memozie all the states [player_number][items_remaining]
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool dp[2][k+1];
    for(int i=0;i<=k;i++)
    {
        dp[0][i]=false;
        dp[1][i]=false;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n && a[j]<=i;j++)
        {
            if(dp[1][i-a[j]]==false)dp[0][i]=true;
            if(dp[0][i-a[j]]==false)dp[1][i]=true;
        }
    }
    if(dp[0][k]==true)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
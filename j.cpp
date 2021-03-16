//Help : https://codeforces.com/blog/entry/64250?#comment-482538
//tl;dr : Choose your state variables smartly
//Also, for reference, see Demoralizers youtube video on the same
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    int n;
    cin>>n;
    double dp[n+1][n+1][n+1] = {0};
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp==1)one+=1;
        else if(tmp==2)two+=1;
        else if(tmp==3)three+=1;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++)
            {
                if(i==0 && j==0 && k==0)continue;
                if(i+j+k>n)continue;
                double tmp=1.0;
                if(i>0)
                {
                    tmp += (i*1.0/(n))*(dp[i-1][j+1][k]);
                }
                if(j>0)
                {
                    tmp += (j*1.0/(n))*(dp[i][j-1][k+1]);
                }
                if(k>0)
                {
                    tmp += (k*1.0/(n))*(dp[i][j][k-1]);
                }
                dp[i][j][k] = tmp/(1.0 - (1.0*(n-(i+j+k)))/n);
            }
        }
    }
    cout<<setprecision(15)<<dp[three][two][one]<<endl;
}
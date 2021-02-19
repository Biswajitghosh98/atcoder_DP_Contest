// Description :
// Same problem as 'a', the only difference being, instead of jumping one or two 
// steps, we can jump upto k steps in one move

// Approach :
// Will follow a similar approach, because k is max 100, so order would be 
// O(100n)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> height(n), cost(n,INT_MAX);
    cost[0] = 0;
    for(int i=0;i<n;i++)cin>>height[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<min(i+k+1,n);j++)
        {
            cost[j] = min(cost[j], cost[i] + abs(height[j]-height[i]));
        }
    }
    cout<<cost[n-1]<<endl;
}
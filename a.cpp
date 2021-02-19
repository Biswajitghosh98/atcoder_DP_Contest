// Description :
// an array is given a(n)
// cost of moving from i -> j = abs(a[j]-a[i])
// find total cost of moving from 1->n if valid steps are +1 and +2

// Approach :
// at any point of time, we know minimum cost to reach i from 1
// minimum cost to reach i+1 and i+2 would be min(cost[i] + abs(a[i+1]-a[i]) , cost[i+1])
// and min(cost[i] + abs(a[i+2] - a[i]), a[i+2])

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> height(n), cost(n,INT_MAX);
    cost[0] = 0;
    for(int i=0;i<n;i++)cin>>height[i];
    for(int i=0;i<n;i++)
    {
        if(i+1 < n)cost[i+1] = min(cost[i] + abs(height[i+1]-height[i]), cost[i+1]);
        if(i+2 < n)cost[i+2] = min(cost[i] + abs(height[i+2]-height[i]), cost[i+2]);
    }
    cout<<cost[n-1]<<endl;
}
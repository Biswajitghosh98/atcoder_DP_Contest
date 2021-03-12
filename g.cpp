/*
Description : In a directed graph with no cycles, find the longest path

Solution :  Find all the nodes with no incoming edges, then from their neighbours, remove their edges and proceed forward.
The solution then is very intuitive.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj_in(n+1),adj_out(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj_in[y].insert(x);
        adj_out[x].insert(y);
    }
    int ans=0;
    queue<int> q,tmp;
    while(!q.empty())q.pop();
    while(!tmp.empty())tmp.pop();
    for(int i=1;i<=n;i++)
    {
        if(adj_in[i].size()==0)q.push(i);
    }
    while(true)
    {
        while(!q.empty())
        {
            int fr = q.front();
            q.pop();
            for(auto x:adj_out[fr])
            {
                adj_in[x].erase(adj_in[x].find(fr));
                if(adj_in[x].size()==0)tmp.push(x);
            }
        }
        if(tmp.size()==0)
        {
            break;
        }
        ans+=1;
        swap(q,tmp);
    }
    cout<<ans<<endl;
}
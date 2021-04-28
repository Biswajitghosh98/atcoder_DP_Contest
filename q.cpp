//n^2 won't do. Optimize 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define vl vector<ll>
ll max(ll a, ll b)
{
    if(a>b)return a;
    return b;
}
void build(vector<ll> &a, vector<ll> &tree, ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a,tree, v*2, tl, tm);
        build(a,tree, v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

ll get_max(vector<ll> &tree, ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)return LLONG_MIN;
    if (l == tl && r == tr)return tree[v];
    ll tm = (tl + tr) / 2;
    return max(get_max(tree, v*2, tl, tm, l, min(r, tm)), get_max(tree, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(vector<ll> &tree, ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) 
    {
        tree[v] = new_val;
    } 
    else 
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(tree, v*2, tl, tm, pos, new_val);
        else
            update(tree, v*2+1, tm+1, tr, pos, new_val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}
bool cfun(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b)
{
    return a.first.first > b.first.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>> v;
    for(ll i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        v.pb(mp(mp(tmp,0),i));
    }
    for(ll i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        v[i].first.second = tmp;
    }
    sort(v.begin(),v.end(),cfun);
    vl a(n,0), tree(4*n,0);
    for(ll i=0;i<n;i++)
    {
        ll tmp = get_max(tree, 1, 0, n-1, v[i].second, n-1);
        a[v[i].second] = v[i].first.second + tmp;
        update(tree, 1, 0, n-1, v[i].second, a[v[i].second]);
    }
    cout<<*max_element(a.begin(),a.end())<<endl;
}
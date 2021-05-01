#include <bits/stdc++.h>
const double PI  =3.141592653589793238463; 
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n'; 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
inline ll add(ll a, ll b){a += b; if(a >= MOD)a -= MOD; return a;}
inline ll sub(ll a, ll b){a -= b; if(a < 0)a += MOD; return a;}
inline ll mul(ll a, ll b){return (ll)((ll) a * b %MOD);}
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {
 
        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base);//%MOD;
        }
        base = (base * base);//%MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
void dfs(ll s,vector<vector<ll>> &adj,vector<bool> &vis, vector<ll> &arr) 
{
	if(vis[s]) return;
	vis[s]=true;
    arr.pb(s);
	for(auto x:adj[s])
	{
		if(vis[x]==false)
		{
            dfs(x,adj,vis,arr);
		}
	}
}
void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &level, vector<ll> &parent)
{
	queue<ll> q;
	vis[x] = true;
	q.push(x);
	while (!q.empty()) 
	{
		ll s = q.front(); 
		q.pop();
		// process node s
		for (auto u : adlist[s]) 
		{
			if (vis[u]) continue;
			vis[u] = true;
            parent[u]=s;
            level[u]=level[s]+1;
			q.push(u);
		}
	}
}
bool bpchk(vector< vector < ll > > &adj, vector<ll> &color)
{
    color[1] = 1;
    queue < ll > q;
    q.push(1);
 
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
 
        for(auto x : adj[u])
        {
            if(color[x] == -1)
            {
                color[x] = color[u]^1;
                q.push(x);
            }
        }
    }
 
    for(ll i = 1; i < adj.size();i++)
    {
        for(auto x : adj[i])
        {
            if(color[x] == color[i]) return false;
        }
    }
 
    return true;    
}
void swap(ll *a, ll *b)
{
    ll tmp=*a;
    *a = *b;
    *b = tmp;
}
void SieveOfEratosthenes(ll n, unordered_set<ll> &s) 
{  
    vector<bool> prime(n+1,true);  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        {   
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }  
    for (ll p=2; p<=n; p++) 
       if (prime[p]) s.insert(p); 
} 
const long long MOD2 = static_cast<long long>(MOD) * MOD;
 
struct Matrix
{
	vector< vector<int> > mat;
	int n_rows, n_cols;
 
	Matrix() {}
 
	Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
		n_cols(values[0].size()) {}
 
	static Matrix identity_matrix(int n)
	{
		vector< vector<int> > values(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			values[i][i] = 1;
		return values;
	}
 
	Matrix operator*(const Matrix &other) const 
	{
		int n = n_rows, m = other.n_cols;
		vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				long long tmp = 0;
				for(int k = 0; k < n_cols; k++) {
					tmp += mat[i][k] * 1ll * other.mat[k][j];
					while(tmp >= MOD2)
						tmp -= MOD2;
				}
				result[i][j] = tmp % MOD;
			}
 
		return move(Matrix(move(result)));
	}
 
	inline bool is_square() const
	{
		return n_rows == n_cols;
	}
};
 
// binary exponentiation, returns a^p
Matrix pw(Matrix a,int p){
	Matrix result = Matrix::identity_matrix(a.n_cols);
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}
 
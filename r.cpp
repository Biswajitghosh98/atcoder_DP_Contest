#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
 
struct Matrix
{
	vector< vector<ll> > mat;
	ll n_rows, n_cols;
 
	Matrix() {}
 
	Matrix(vector< vector<ll> > values): mat(values), n_rows(values.size()),
		n_cols(values[0].size()) {}
 
	static Matrix identity_matrix(ll n)
	{
		vector< vector<ll> > values(n, vector<ll>(n, 0));
		for(ll i = 0; i < n; i++)
			values[i][i] = 1;
		return values;
	}
 
	Matrix operator*(const Matrix &other) const 
	{
		ll n = n_rows, m = other.n_cols;
		vector< vector<ll> > result(n_rows, vector<ll>(n_cols, 0));
		for(ll i = 0; i < n; i++)
			for(ll j = 0; j < m; j++) {
				long long tmp = 0;
				for(ll k = 0; k < n_cols; k++) {
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
Matrix pw(Matrix a,ll p){
	Matrix result = Matrix::identity_matrix(a.n_cols);
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>v[j][i];
        }
    }
    vector<vector<ll>> v2(n,vector<ll>(1,1));
    Matrix a(v), b(v2);
    Matrix fin = pw(a,k)*b;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans += fin.mat[i][0];
        ans%=MOD;
    }
    cout<<ans<<endl;
}
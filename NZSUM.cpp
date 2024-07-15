#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define len length

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Matrix{
	public:
		int row, col;
		ll a[25][25];
		
		Matrix operator*(Matrix other){
			Matrix res;
			if (this->col != other.row){
				res.row = res.col = 0;
				res.a[1][1] = -1;
				return res;
			}
			res.row = this->row;
			res.col = other.col;
			FOR(x, 1, res.row){
				FOR(y, 1, res.col){
					res.a[x][y] = 0LL;
					FOR(k, 1, this->col){
						ll g = (this->a[x][k] * other.a[k][y]) % MOD;
						res.a[x][y] = (res.a[x][y] + g) % MOD;
					}
				}
			}
			return res;
		}
};

Matrix Identity(int sz){
	Matrix res;
	res.row = res.col = sz;
	FOR(x, 1, sz){
		FOR(y, 1, sz) res.a[x][y] = 0LL;
	}
	FOR(x, 1, sz) res.a[x][x] = 1LL;
	return res;
}

Matrix Pow(Matrix A, ll P){
	if (P == 0) return Identity(A.row);
	Matrix tmp = Pow(A, P >> 1);
	tmp = (tmp * tmp);
	return ((P & 1) ? tmp * A : tmp);
}

ll n, cnt[11], dp[11];
Matrix S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cnt[0] = 1;
	dp[0] = 0;
	
	FOR(x, 1, 9){
	    cnt[x] = (1 << (x - 1));
	    
		FOR(y, 1, x) dp[x] = (dp[x] + 10 * dp[x - y] + y * cnt[x - y]) % MOD;
	}
	
	S.row = S.col = 18;
	
	FOR(row, 1, 18){
	    FOR(col, 1, 18) S.a[row][col] = 0;
	}
	
	FOR(col, 1, 18){
	    if (col <= 9) S.a[1][col] = 10;
	    else S.a[1][col] = col - 9;
	}
	
	FOR(row, 2, 9) S.a[row][row - 1] = 1;
	
	FOR(col, 10, 18) S.a[10][col] = 1;
	
	FOR(row, 11, 18) S.a[row][row - 1] = 1;
	
	while (cin >> n){
		if (n <= 9) cout << dp[n] << "\n";
		else{
			Matrix P;
			P = Pow(S, n - 9);
			ll res = 0LL;
			FOR(x, 1, 18){
				if (x <= 9) res = (res + P.a[1][x] * dp[10 - x]) % MOD;
				else res = (res + P.a[1][x] * cnt[19 - x]) % MOD;
			}
			
			cout << res << "\n";
		}
	}
	
	return 0;
}

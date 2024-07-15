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
		ll val[155][155];
		
		Matrix operator*(Matrix O){
			Matrix res;
			
			if (this->col != O.row){
				res.row = res.col = -1;
				return res;
			}
			
			res.row = this->row;
			res.col = O.col;
			
			FOR(x, 1, res.row){
				FOR(y, 1, res.col){
					res.val[x][y] = 0;
					
					FOR(k, 1, O.row){
						res.val[x][y] += ((this->val[x][k] * O.val[k][y])) % MOD;
						res.val[x][y] %= MOD;
					}
				}
			}
			
			return res;
		}
};

Matrix Id(int M){
	Matrix res;
	res.row = res.col = M;
	
	FOR(x, 1, M){
		FOR(y, 1, M) res.val[x][y] = 0;
	}
	
	FOR(x, 1, M) res.val[x][x] = 1;
	return res;
}

Matrix Pow(Matrix A, ll N){
	if (!N) return Id(A.row);
	
	Matrix tmp = Pow(A, N >> 1LL);
	tmp = (tmp * tmp);
	
	return (N & 1 ? tmp * A : tmp);
}

int n;
ll p, res = 0LL;
Matrix S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p;
	S.row = S.col = n;
	
	FOR(x, 1, n){
		FOR(y, 1, n) cin >> S.val[x][y];
	}
	
	S = Pow(S, p);
	FOR(x, 1, n){
		FOR(y, 1, n) res = (res + S.val[x][y]) % MOD;
	}
	cout << res;
	
	return 0;
}

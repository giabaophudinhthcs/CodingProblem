#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e6 + 10;
const int mMax = 150;
const ll MOD = 998244353;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Matrix{
	public:
		int row, col;
		ll a[7][7];
		
		void init(){
			FOR(x, 1, this->row){
				FOR(y, 1, this->col) this->a[x][y] = 0;
			}
		}
		
		Matrix operator*(Matrix o){
			Matrix res;
			if (this->col != o.row){
				res.row = res.col = 0;
				res.a[1][1] = -oo;
			}
			
			res.row = this->row;
			res.col = o.col;
			
			FOR(x, 1, res.row){
				FOR(y, 1, res.col){
					res.a[x][y] = 0;
					FOR(k, 1, o.row){
						ll g = (this->a[x][k] * o.a[k][y]) % MOD;
						res.a[x][y] = (res.a[x][y] + g) % MOD;
					}
				}
			}
			return res;
		}
};

ll n;
Matrix S, PP, Res;

Matrix Identity(int sz){
	Matrix res;
	res.row = res.col = sz;
	res.init();
	FOR(x, 1, sz) res.a[x][x] = 1;
	return res;
}

Matrix Pow(Matrix A, ll P){
	if (!P) return Identity(A.row);
	Matrix tmp = Pow(A, P >> 1);
	tmp = (tmp * tmp);
	return ((P & 1) ? (tmp * A) : tmp);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	S.row = S.col = 6;
	S.init();
	S.a[1][1] = S.a[2][1] = S.a[3][2] = S.a[4][4] = S.a[5][4] = S.a[6][5] = 1;
	S.a[1][2] = S.a[4][5] = 4;
	S.a[1][3] = S.a[4][6] = 2;
	S.a[4][2] = S.a[4][3] = 12;
	PP = Pow(S, n);
	cout << PP.a[4][1];
	return 0;
}

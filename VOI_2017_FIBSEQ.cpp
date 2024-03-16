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

int t, n, k;
ll i, v[nMax];

class Matrix{
	public:
		int row, col;
		ll a[10][10];
		
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
					FOR(C, 1, this->col){
						ll g = (this->a[x][C] * other.a[C][y]) % k;
						res.a[x][y] = (res.a[x][y] + g) % k;
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

ll Fib(ll N){
	Matrix S;
	S.row = S.col = 2;
	S.a[1][1] = S.a[1][2] = S.a[2][1] = 1LL;
	S.a[2][2] = 0LL;
	return Pow(S, N - 1).a[1][1];
}

void solve(){
	cin >> n >> i >> k;
	
	int s = 0, l = -1, r = -1;
	
	int marked[k + 5];
	
	FOR(x, 0, k - 1) marked[x] = 0;
	
	v[1] = Fib(i);
	v[2] = Fib(i + 1);
	FOR(x, 3, n) v[x] = (v[x - 1] + v[x - 2]) % k;
	
	marked[0] = 1;
    FOR(x, 1, n){
        s += v[x];
        s %= k;
        
        if (marked[s] > 0){
            l = marked[s];
            r = x;
            break;
        }else marked[s] = x + 1;
    }
    
    if (l < 0 || r < 0) cout << 0;
    else{
    	cout << r - l + 1 << " ";
    	for (int x = l; x <= r; ++x) cout << x + i - 1 << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> t;
	
	while (t--){
		solve();
		cout << "\n";
	}
	
	return 0;
}

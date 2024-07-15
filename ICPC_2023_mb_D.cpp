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
const int mMax = 3e3 + 30;
const ll MOD = 123456789;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, m, k, row, col, c;
vi cols;
vi adj[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	
	row = max(m, n);
	col = min(m, n);
	
	FOR(s, 0, (1 << col) - 1){
		if (!(s & (s >> 1))) cols.pb(s);
	}
	
	c = int(cols.size());
	
	FOR(x, 0, c - 1){
		int s = cols[x];
		FOR(y, 0, c - 1){
			int t = cols[y];
			if ((!(s & t)) && (!(s & (t << 1))) && (!(s & (t >> 1)))) adj[x].pb(y);
		}
	}
	
	ll dp[row + 1][k + 1][c];
	FOR(r, 0, row){
	    FOR(d, 0, k){
	        FOR(x, 0, c - 1) dp[r][d][x] = 0LL;
	    }
	}
	dp[0][0][0] = 1LL;
	FOR(r, 0, row - 1){
		FOR(d, 0, k){
			FOR(x, 0, c - 1){
				ll val = dp[r][d][x];
				if (!val) continue;
				
				for (auto y: adj[x]){
					int dd = d + __builtin_popcount(cols[y]);
					if (dd > k) continue;
					
					dp[r + 1][dd][y] = (dp[r + 1][dd][y] + val) % MOD;
				}
			}
		}
	}
	
	ll res = 0LL;
	FOR(x, 0, int(cols.size()) - 1) res = (res + dp[row][k][x]) % MOD;
	cout << res;
	return 0;
}

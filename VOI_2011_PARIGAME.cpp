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

int t, n, a[505][505], Srow[505][505], Scol[505][505], dp[505][505];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		
		FOR(r, 1, n){
			FOR(c, 1, n){
				dp[r][c] = 0;
				cin >> a[r][c];
				a[r][c] &= 1;
				Srow[r][c] = (Srow[r][c - 1] ^ a[r][c]) & 1;
			}
		}
		
		FOR(c, 1, n){
			FOR(r, 1, n) Scol[c][r] = (Scol[c][r - 1] ^ a[r][c]) & 1;
		}
		
		FOR(r, 1, n){
			FOR(c, 1, n){
				if (!Srow[r][c] && !dp[r - 1][c]) dp[r][c] = 1;
				if (!Scol[c][r] && !dp[r][c - 1]) dp[r][c] = 1;
			}
		}
		
		cout << (dp[n][n] ? "YES\n" : "NO\n");
	}
	
	return 0;
}

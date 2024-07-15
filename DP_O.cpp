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

const int nMax = 21;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, a[nMax][nMax], dp[1 << nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	FOR(x, 0, n - 1){
		FOR(y, 0, n - 1) cin >> a[x][y];
	}
	
	dp[0] = 1;
	
	FOR(State, 0, (1 << n) - 1){
		int cnt = __builtin_popcount(State);
		FOR(w, 0, n - 1){
			if ((State & (1 << w)) || (!a[cnt][w])) continue;
			dp[State | (1 << w)] += dp[State];
			dp[State | (1 << w)] %= MOD;
		}
	}
	
	cout << dp[(1 << n) - 1];
	
	return 0;
}

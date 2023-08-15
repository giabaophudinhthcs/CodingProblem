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
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, a[20], b[20], res, All, cost[20][20], dp[nMax];

int Mask(int v){
	return (1 << v);
}

int Cnt(int num){
	return __builtin_popcount(num);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1){
		cin >> n;
		if (!n) return 0;
		
		FOR(x, 1, n) cin >> a[x];
		FOR(x, 1, n) cin >> b[x];
		
		FOR(x, 1, n){
			FOR(y, 0, n - 1) cost[x][y] = abs(x - (y + 1)) + abs(a[x] - b[y + 1]);
		}
		
		All = Mask(n) - 1;
		
		FOR(State, 0, All) dp[State] = oo;
		dp[0] = 0;
		
		FOR(State, 0, All){
			int r = Cnt(State);
			FOR(m, 0, n - 1){
				int M = Mask(m);
				if ((State & M) == M) dp[State] = min(dp[State], dp[State ^ M] + cost[r][m]);
			}
		}
		
		cout << dp[All] << "\n";
	}
	return 0;
}

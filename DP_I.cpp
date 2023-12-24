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

int n;
double p[3003], res = 0.0, dp[3003][3003];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n) cin >> p[x];
	dp[1][0] = 1.0 - p[1];
	dp[1][1] = p[1];
	FOR(x, 2, n){
		FOR(y, 0, x){
		    if (y == 0){
		        dp[x][y] = dp[x - 1][y] * (1.0 - p[x]);
		        continue;
		    }
		    dp[x][y] = dp[x - 1][y - 1] * p[x] + dp[x - 1][y] * (1.0 - p[x]);
		}
	}
	FOR(x, 1, n){
		int y = n - x;
		if (x > y) res += dp[n][x];
	}
	cout << fixed << setprecision(9) << res;
	return 0;
}

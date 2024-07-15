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

int n, dp[1005][2];
string x, y, z;

void solve(){
	cin >> x >> y >> z;
	x = " " + x;
	y = " " + y;
	z = " " + z;
	FOR(p, 1, n) dp[p][0] = dp[p][1] = -1;
	dp[n + 1][0] = 0;
	dp[n + 1][1] = -1;
	FORD(p, n, 1){
		int dx = (x[p] - '0');
		int dy = (y[p] - '0');
		int dz = (z[p] - '0');
		FOR(r, 0, 1){
			if (dp[p + 1][r] == -1) continue;
			
			int s = dx + dy + r;
			if (s % 10 == dz) dp[p][s / 10] = max(dp[p][s / 10], dp[p + 1][r] + 1);
			
			dp[p][r] = max(dp[p][r], dp[p + 1][r]);
		}
	}
	cout << n - dp[1][0] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1){
		cin >> n;
		if (!n) return 0;
		solve();
	}
	return 0;
}

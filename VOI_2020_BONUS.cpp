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

int n, k;
ll a[305], dp[305][305][155], res = -1;

ll calc(int l, int r, int c){
	if (c == 0) return 0;
	
	if (l > r) return -ooll;
	
	if (dp[l][r][c] != -1) return dp[l][r][c];
	
	dp[l][r][c] = max(calc(l + 1, r, c), calc(l, r - 1, c));
	
	if (l < r){
		dp[l][r][c] = max(dp[l][r][c], calc(l + 2, r, c - 1) + abs(a[l] - a[l + 1]));
		dp[l][r][c] = max(dp[l][r][c], calc(l, r - 2, c - 1) + abs(a[r] - a[r - 1]));
		dp[l][r][c] = max(dp[l][r][c], calc(l + 1, r - 1, c - 1) + abs(a[l] - a[r]));
	}
	
	return dp[l][r][c];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	FOR(x, 1, n) cin >> a[x];
	
	FOR(l, 1, n){
		FOR(r, 1, n){
			FOR(c, 1, n) dp[l][r][c] = -1;
		}
	}
	
	cout << calc(1, n, k);
	
	return 0;
}

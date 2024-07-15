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
typedef unsigned long long ull;
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

int n, m, a[1505], b[1505], dp[1505], res = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m){
		cin >> b[i];
		dp[i] = 0;
	}
	
	FOR(i, 1, n){
		int cur = 0;
		
		FOR(j, 1, m){
			if (a[i] == b[j]) dp[j] = max(dp[j], cur + 1);
			if (a[i] > b[j]) cur = max(cur, dp[j]);
		}
	}
	
	FOR(i, 1, m) res = max(res, dp[i]);
	cout << res;
	
	return 0;
}

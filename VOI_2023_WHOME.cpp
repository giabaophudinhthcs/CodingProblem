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

const int nMax = 1e5 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, m, s[10];
ll p, c, a[nMax], dp[nMax][70];

int Mask(int v){
	return (1 << v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("WHOME.INP", "r", stdin);
	freopen("WHOME.OUT", "w", stdout);
	
	cin >> n >> m >> p >> c;
	FOR(x, 1, n) cin >> a[x];
	FOR(x, 0, m - 1) cin >> s[x];
	
	sort(a + 1, a + n + 1);
	
	int All = Mask(m) - 1;
	
	FOR(x, 0, n){
		FOR(T, 0, All) dp[x][T] = -ooll;
	}
	
	dp[0][0] = 0;
	
	FOR(x, 1, n){
		FOR(T, 0, All){
			dp[x][T] = max(dp[x][T], dp[x - 1][T]);
			FOR(y, 0, m - 1){
				if (x >= s[y]) dp[x][T | Mask(y)] = max(dp[x][T | Mask(y)], dp[x - s[y]][T] + p - (a[x] - a[x - s[y] + 1]) * (a[x] - a[x - s[y] + 1]) * c);
			}
		}
	}
	
	cout << dp[n][All];
	
	return 0;
}


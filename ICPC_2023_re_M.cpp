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

int t, n;
ll H, I, a[205], s[205], dp[205][205];

void solve(){
	cin >> n >> H >> I;
	FOR(x, 1, n){
		cin >> a[x];
		s[x] = s[x - 1] + a[x];
	}
	
	FOR(l, 1, n){
		FOR(r, l, n) dp[l][r] = ooll;
	}
	
	FORD(l, n, 1){
		FOR(r, l, n){
			if (l == r) dp[l][r] = a[l];
			else{
			    ll R = H + I - s[l - 1] + s[r] - s[n];
			    dp[l][r] = min(dp[l][r], min(max(a[l], R - dp[l + 1][r] + 1), max(a[r], R - dp[l][r - 1] + 1)));
			}
		}
	}
	
	cout << (H >= dp[1][n] ? "Haros\n" : "Iwys\n");
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}

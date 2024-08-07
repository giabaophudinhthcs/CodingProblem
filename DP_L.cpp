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
ll a[3005], dp[3005][3005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n){
		cin >> a[x];
		dp[x][x] = a[x];
	}
	
	FORD(x, n, 1){
		FOR(y, x + 1, n) dp[x][y] = max(a[x] - dp[x + 1][y], a[y] - dp[x][y - 1]);
	}
	
	cout << dp[1][n];
	
	return 0;
}

// Link: https://oj.vnoi.info/problem/fc111_calplus

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

int n;
ll a[mMax], dp[mMax][mMax], opt[mMax][mMax], s[mMax], cost, best;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n){
	    cin >> a[x];
	    s[x] = s[x - 1] + a[x];
	    dp[x][x] = 0;
	    opt[x][x] = x;
	}
	FORD(x, n - 1, 1){
	    FOR(y, x + 1, n){
	        dp[x][y] = (s[y] - s[x - 1]) * (s[y] - s[x - 1]);
	        best = ooll;
	        FOR(k, opt[x][y - 1], opt[x + 1][y]){
	            if (dp[x][k] + dp[k + 1][y] < best){
	                best = dp[x][k] + dp[k + 1][y];
	                opt[x][y] = k;
	            }
	        }
	        dp[x][y] += best;
	    }
	}
	cout << dp[1][n];
	return 0;
}

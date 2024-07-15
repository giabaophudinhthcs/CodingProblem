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

int n, k, dp[nMax][12], Prev[nMax];
string s;
map<char, int> last_pos;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> s;
	s = " " + s + " ";
	FOR(x, 1, n){
		Prev[x] = last_pos[s[x]];
		last_pos[s[x]] = x;
	}
	
	// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
	
	dp[0][0] = 1;
	FOR(x, 1, n){
		FOR(y, 0, min(k, x)){
			dp[x][y] = dp[x - 1][y];
			
			if (y) dp[x][y] = (dp[x][y] + dp[x - 1][y - 1]) % MOD;
			
			int u = Prev[x];
			int e = y - (x - u);
			if (u && 0 <= e && e <= k){
				dp[x][y] = (dp[x][y] - dp[u - 1][e]) % MOD;
				if (dp[x][y] < 0) dp[x][y] += MOD;
			}
		}
	}
	
	cout << dp[n][k];
	return 0;
}

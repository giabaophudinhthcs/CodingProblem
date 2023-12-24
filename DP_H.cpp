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

int H, W;
ll dp[1005][1005];
string s[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W;
	FOR(x, 1, H){
		cin >> s[x];
		s[x] = " " + s[x];
	}
	dp[1][1] = (s[1][1] == '.');
	FOR(x, 1, H){
		FOR(y, 1, W){
		    if (x == 1 && y == 1) continue;
			if (s[x][y] == '.') dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % MOD;
			else dp[x][y] = 0;
		}
	}
	cout << dp[H][W];
	return 0;
}

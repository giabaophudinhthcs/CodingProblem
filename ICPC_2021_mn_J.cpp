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

int m, n, cnt, dp[5005][5005], sz = -5, R, C;
string s[5005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	FOR(x, 1, m){
		cin >> s[x];
		s[x] = " " + s[x];
		FOR(y, 1, n) dp[x][y] = 10000;
	}
	
	FOR(r, 1, m){
		cnt = 0;
		FOR(c, 1, n){
			if (s[r][c] == '1') cnt++;
			else cnt = 0;
			dp[r][c] = min(dp[r][c], cnt);
		}
	}
	
	FOR(r, 1, m){
		cnt = 0;
		FORD(c, n, 1){
			if (s[r][c] == '1') cnt++;
			else cnt = 0;
			dp[r][c] = min(dp[r][c], cnt);
		}
	}
	
	FOR(c, 1, n){
		cnt = 0;
		FORD(r, m, 1){
			if (s[r][c] == '1') cnt++;
			else cnt = 0;
			dp[r][c] = min(dp[r][c], cnt);
		}
	}
	
	FOR(c, 1, n){
		cnt = 0;
		FOR(r, 1, m){
			if (s[r][c] == '1') cnt++;
			else cnt = 0;
			dp[r][c] = min(dp[r][c], cnt);
		}
	}
	
	FOR(r, 1, m){
		FOR(c, 1, n){
			if (sz < dp[r][c]){
				sz = dp[r][c];
				R = r;
				C = c;
			}
		}
	}
	
	if (sz == 0) cout << -1;
	else cout << 4 * sz - 3 << "\n" << R << " " << C;
	return 0;
}

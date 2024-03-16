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

const int nMax = 5e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

string s;
int m, n = 0, cnt = 0, d[nMax];
char C[nMax];
ll dp[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("ADN.INP", "r", stdin);
	freopen("ADN.OUT", "w", stdout);
	
	cin >> s;
	m = int(s.len());
	
	FOR(x, 0, m - 1) cnt += (s[x] != '?');
	
	if (!cnt){
		cout << 0;
		return 0;
	}
	
	if (s[0] == '?'){
		int pos = 0;
		while (s[pos] == '?') pos++;
		FOR(x, 0, pos - 1) s[x] = s[pos];
	}
	
	if (s[m - 1] == '?'){
		int pos = m - 1;
		while (s[pos] == '?') pos--;
		FOR(x, pos + 1, m - 1) s[x] = s[pos];
	}
	
	FOR(x, 0, m - 1){
		if (s[x] == '?'){
			int l = x, r = x;
			char L, R;
			L = s[l - 1];
			
			while (s[r] == '?') r++;
			
			r--;
			R = s[r + 1];
			
			if (L == R){
				FOR(y, l, r) s[y] = L;
			}
			
			x = r;
		}
	}
	
	dp[0] = 0;
	
	FOR(x, 0, m - 1){
		int cur = x;
		char c = s[x];
		while (s[x] == c) x++;
		x--;
		n++;
		C[n] = c;
		d[n] = x - cur + 1;
	}
	
	FOR(x, 1, n){
		dp[x] = 0;
		
		FOR(k, 1, min(x, 3)){
			cnt = 0;
			
			FOR(y, x - k + 1, x) cnt += (C[y] != '?');
			
			if (cnt > 1) break;
			
			ll D = 0;
			FOR(y, x - k + 1, x) D += d[y];
			
			ll v = dp[x - k] + (D * (D + 1) / 2);
			dp[x] = max(dp[x], v);
		}
	}
	
	ll M = m;
	ll res = (M * (M + 1) / 2) - dp[n];
	cout << res;
	
	return 0;
}

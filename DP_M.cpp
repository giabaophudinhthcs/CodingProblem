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

// c - a[i] <= c' <= c
// s[c] - s[c - a[i] - 1]
// res = dp[n][k]

int n, k, a[nMax], q[nMax], f[nMax], s[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	FOR(x, 1, n){
		cin >> a[x];
	}
	
	FOR(c, 0, k){
		q[c] = 0;
		if (c <= a[1]) q[c]++;
		s[c] = q[c];
		if (c > 0) s[c] += s[c - 1];
	}
	
	FOR(x, 2, n){
		FOR(c, 0, k){
			f[c] = s[c];
			if (c > a[x]) f[c] -= s[c - a[x] - 1];
			f[c] %= MOD;
			f[c] = (f[c] + MOD) % MOD;
			q[c] = f[c];
		}
		
		FOR(c, 0, k){
			s[c] = q[c];
			if (c > 0) s[c] = (s[c] + s[c - 1]) % MOD;
		}
	}
	
	cout << q[k];
	
	return 0;
}

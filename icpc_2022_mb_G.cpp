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

int t;
ll p[nMax];
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	p[0] = 0;
	FOR(x, 1, 1e6){
		p[x] = p[x - 1] + x;
		p[x] %= MOD;
	}
	
	FOR(x, 1, 1e6) p[x] = (p[x] + p[x - 1]) % MOD;
	
	cin >> t;
	
	while (t--){
		ll res = 0LL;
		cin >> s;
		int n = int(s.len());
		s = " " + s;
		FOR(x, 1, n){
			ll SS = p[n] - p[n - x] - p[x - 1];
			SS %= MOD;
			SS = (SS + MOD) % MOD;
			int v = int(s[x] - 'a' + 1);
			res = (res + (SS * v) % MOD) % MOD;
		}
		cout << res << "\n";
	}
	
	return 0;
}


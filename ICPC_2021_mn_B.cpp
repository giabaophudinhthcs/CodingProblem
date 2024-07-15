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

const int nMax = 1e7 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int t, n;
ll f[nMax], sf[nMax], ssf[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	f[0] = sf[0] = ssf[0] = 1;
	FOR(x, 1, 1e7){
		f[x] = (f[x - 1] * x) % MOD;
		sf[x] = (sf[x - 1] + f[x]) % MOD;
		ssf[x] = (ssf[x - 1] + sf[x]) % MOD;
	}
	
	cin >> t;
	FOR(test, 1, t){
		cin >> n;
		ll res = f[n];
		res -= 2 * sf[n - 1] + 1;
		res %= MOD;
		res = (res + MOD) % MOD;
		res = (res + ssf[n - 2] + 2) % MOD;
		cout << res << "\n";
	}
	return 0;
}

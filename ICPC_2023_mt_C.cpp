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

int test, n, a[102], Pi[75], c[75], f[75];
ll res;

ll Pow2(ll v){
	if (v <= 50){
		ll res = (1LL) << v;
		return (res % MOD);
	}
	
	ll tmp = Pow2(v >> 1);
	tmp = (tmp * tmp) % MOD;
	
	return ((v & 1) ? (tmp << 1LL) % MOD : tmp);
}

void calc_pi(){
	FOR(p, 2, 70) Pi[p] = -2;
	Pi[1] = 1;
	FOR(p, 2, 70){
		int ok = 0;
		for (int k = 2; k * k <= p; ++k) ok |= (p % (k * k) == 0);
		if (ok) Pi[p] = 0;
		c[p] = 0;
	}
	FOR(p, 2, 70){
		if (c[p] == 0){
			for (int y = p; y <= 70; y += p) c[y]++;
		}
	}
	FOR(p, 2, 70){
		if (Pi[p] == -2) Pi[p] = (c[p] & 1) ? -1 : 1;
	}
	
	FOR(p, 1, 70) Pi[p] = (Pi[p] + MOD) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	calc_pi();
	cin >> test;
	while (test--){
		res = 0LL;
		FOR(x, 1, 70) c[x] = f[x] = 0;
		cin >> n;
		FOR(x, 1, n){
			cin >> a[x];
			c[a[x]]++;
		}
		FOR(x, 1, 70){
			for (int y = x; y <= 70; y += x) f[x] += c[y];
		}
		FOR(g, 1, 70){
			ll r = 0LL;
			for (int x = 1; x * g <= 70; ++x){
				ll G = Pow2(f[x * g]) - 1;
				ll v = (G * Pi[x]) % MOD;
				r = (r + v) % MOD;
			}
			ll val = (r * g) % MOD;
			res = (res + val) % MOD;
		}
		cout << res << "\n";
	}
	return 0;
}

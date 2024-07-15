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

int n, m[nMax], mv = oo, Mv = -oo;
ll a[nMax], s[nMax], ans = -ooll;
vi ID[mMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n){
		cin >> m[x];
		mv = min(mv, m[x]);
		Mv = max(Mv, m[x]);
		ID[m[x] + 500].pb(x);
		a[x] = -oo;
	}
	
	FOR(v, mv, Mv){
		if (int(ID[v + 500].size()) == 0) continue;
		for (auto id: ID[v + 500]) a[id] = m[id];
		FOR(x, 1, n) s[x] = s[x - 1] + a[x];
		ll g = s[0], res = -ooll;
		FOR(x, 1, n){
			res = max(res, s[x] - g);
			g = min(g, s[x]);
		}
		ans = max(ans, res - v);
	}
	cout << ans;
	return 0;
}
